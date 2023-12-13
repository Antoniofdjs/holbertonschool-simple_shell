#include "main.h"
#include <stdio.h>

/**
 * get_path - pairs args[0] with possible paths
 * @args : array from tokenization of get_tokens of str_line
 * @environ : golbal variable from system
 */

void get_path(char **args, char **environ)
{
	char **path;
	char *full_path;
	int i, did_path = 0;

	path = env_path(environ);
	for (i = 0; path[i] != NULL; i++) /*iterate path and concatenate with args[0]*/
	{
		full_path = malloc(strlen(path[i]) + strlen(args[0]) + 1);

		if (full_path == NULL) /* verify if malloc is succesful */
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		strcpy(full_path, path[i]);
		strcat(full_path, args[0]);
		if (access(full_path, X_OK) == 0) /* verify if path is executable */
		{
			free(args[0]);
			args[0] = strdup(full_path);
			my_exe(args, environ);
			free(full_path);
			free_args(path);
			did_path = 1;
			break;
		}
		free(full_path); /* done the full path, args[0] has full now */

	}
		if (did_path == 0)
			free_args(path);
}
