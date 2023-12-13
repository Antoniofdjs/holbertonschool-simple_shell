#include "main.h"
#include <stdio.h>

/**
 * get_path - pairs args[0] with possible paths
 * @args : array from tokenization of get_tokens of str_line
 * @environ : golbal variable from system
 */

void get_path(char **args, char **environ)
{
	char path[][30] = {"/usr/local/bin/", /* all possible paths */
		"/usr/bin/",
		"/bin/",
		"/usr/local/games/",
		"/usr/games/"};
	int i;

	for (i = 0; i < 5; i++) /*iterate path and concatenate with args[0]*/
	{
		char *full_path = malloc(strlen(path[i]) + strlen(args[0]) + 1);

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
			break;
		}
		free(full_path); /* done the full path, args[0] has full now */
	}
}
