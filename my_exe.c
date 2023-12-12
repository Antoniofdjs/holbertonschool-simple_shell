#include "main.h"
#include <stdio.h>

void my_exe(char **args, char **environ)
{
	pid_t pid;
	pid = fork();

	if (pid == -1)/* child wasn't process and it couldn't work */
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)/* child process is the current process in work */
	{
		execve(args[0], args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);/* parent process suspended until the child finishes */
	}

}
