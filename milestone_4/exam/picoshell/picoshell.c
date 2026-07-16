#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
// process id for forking
	pid_t pid;
// fd array for pipes
	int fd[2];
// loop counter
	int i;
// save the input fd
	int last_fd;

	i = 0;
	last_fd = -1;
// loop through each command
	while (cmds[i])
	{
// create a pipe if there is a next command
		if (cmds[i + 1] && pipe(fd) == -1)
			return (1);
// create a child process
		pid = fork();
// handle fork error
		if (pid == -1) // if fork fails
		{
			if (cmds[i + 1]) // if pipe was created, close it
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
// handle child process
		if (pid == 0)
		{
// if not the first command, redirect input from last_fd
			if (last_fd != -1)
			{
				if (dup2(last_fd, STDIN_FILENO) == -1)
					exit(1);
				close(last_fd);
			}
// if not the last command, set up output to the current pipe
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
			}
// execute the command
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
// handle parent process
// if not the first command, close the last_fd
		if (last_fd != -1)
			close(last_fd);
// if not the last command, close the write end of the pipe and save the read end for the next command
		if (cmds[i + 1])
		{
			close(fd[1]);
			last_fd = fd[0];
		}
// increment loop counter
		i++;
	}
// wait for all child processes to finish
	while (wait(NULL) > 0)
		;
	return (0);
}
