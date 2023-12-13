#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **env_path(char **environ)
{
    int i, j = 0, token_count = 0;
    char *path, *token, *path_dup;
    char **env_path;

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strstr(environ[i], "PATH=") == environ[i])
        {
			printf("environ[1]: %s\n",environ[i]);
			path = environ[i] + 5;/* skips "PATH=" */
			printf("environ[2]: %s\n",environ[i]);
            path_dup = strdup(path);
            token = strtok(path_dup, ":");
            while (token != NULL)
            {
                token_count++;
                token = strtok(NULL, ":");
            }
            free(path_dup);

            env_path = malloc((token_count + 1) * sizeof(char *));
            token = strtok(path, ":");
            while (token != NULL)
            {
                /* Allocate memory for the token and '/' */
                env_path[j] = malloc(strlen(token) + 2);
                strcpy(env_path[j], token);
                strcat(env_path[j], "/"); /* Add '/' at the end */
                j++;
                token = strtok(NULL, ":");
            }

            env_path[j] = NULL;
        }
    }
	for (j = 0; env_path[j] != NULL; j++)
		printf("alfre after making array: %s\n", env_path[j]);
	return (env_path);
}
