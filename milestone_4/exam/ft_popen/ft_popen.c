#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int ft_popen(const char *file, char *const argv[], char type)
{
// fd array for pipes
    int fd[2];
// process id for forking
    pid_t pid;

// check for invalid input
    if(!file || !argv || (type != 'r' && type != 'w'))
        return(-1);
// create a pipe    
    if(pipe(fd) == -1)
        return(-1);
// create a child process
    pid = fork();
// handle fork error
    if(pid == -1)
    {
        close(fd[0]);
        close(fd[1]);
        return(-1);
    }
// handle child process
    if(pid == 0)
    {
// if type is 'r', redirect output to the pipe
        if(type == 'r')
        {
            if(dup2(fd[1], STDOUT_FILENO) == -1)
                exit(1);
        }
// if type is 'w', redirect input from the pipe
        else
        {
            if(dup2(fd[0], STDIN_FILENO) == -1)
                exit(1);
        }
// close the pipe file descriptors
        close(fd[0]);
        close(fd[1]);
// execute the command
        execvp(file, argv);
        exit(1);
    }
// handle parent process
// if type is 'r', close the write end of the pipe and return the read end
    if(type == 'r')
    {
        close(fd[1]);
        return(fd[0]);
    }
// if type is 'w', close the read end of the pipe and return the write end
    else
    {
        close(fd[0]);
        return(fd[1]);
   }
}
