#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void main(void)

{
	extern char **environ;
	char *str_environ = NULL, *str_environ_dup;
	char *str_path = "PATH", *token;
	int i, j, match = 0, token_count = 0;
	char **paths;
	char *path_slash;

	for (i = 0; environ[i] != NULL; i++)
	{
		match = 0;
		for(j = 0; environ[i][j] != '\0' && str_path[j] != '\0'; j++)
		{
			if(environ[i][j] == str_path[j])
				match++;
		}
		if(match == strlen(str_path))
		{
			str_environ = strdup(environ[i]);/* dup of environ, not to mess with environ */
			token = strtok(str_environ, "=");
			token = strtok(NULL, "=");/* after this we have evrything after "PATH="*/
			str_environ_dup = strdup(token);/* str for tokenize and count tokens */
			str_environ = strdup(token);/* str for tokenize and store in array */
			token = strtok(str_environ_dup, ":");
			while (token != NULL)
			{
				token_count++;
				token = strtok(NULL, ":");
				paths = malloc((token_count + 1) * sizeof(char *));
				while (token != NULL)/* cut paths */
				{
					path_slash = malloc(strlen(token) + 2);
					path_slash = strcpy(path_slash, token);
					path_slash = strcat(path_slash,"/");
					paths[i] = strdup(path_slash);
					printf("paths[]: %s\n", paths[i]);
					free(path_slash);
					token = strtok(NULL, ":");
					i++;
				}
				paths[i] = NULL;
				free(str_environ);
				free(token);
				free(str_environ_dup);
				break;
			}
		}
	}
}
