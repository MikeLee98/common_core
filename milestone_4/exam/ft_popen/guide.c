// fd array for pipes
// process id for forking
// check for invalid input
// create a pipe
// create a child process
// handle fork error
// handle child process
// if type is 'r', redirect output to the pipe
// if type is 'w', redirect input from the pipe
// close the pipe file descriptors
// execute the command
// handle parent process
// if type is 'r', close the write end of the pipe and return the read end
// if type is 'w', close the read end of the pipe and return the write end
