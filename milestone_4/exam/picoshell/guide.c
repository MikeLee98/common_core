// process id for forking
// fd array for pipes
// loop counter
// save the input fd
// loop through each command
// create a pipe if there is a next command
// create a child process
// handle fork error
// if fork fails
// if pipe was created, close it
// handle child process
// if not the first command, redirect input from last_fd
// if not the last command, set up output to the current pipe
// execute the command
// handle parent process
// if not the first command, close the last_fd
// if not the last command, close the write end of the pipe and save the read end for the next command
// increment loop counter
// wait for all child processes to finish
