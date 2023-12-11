#include <stdio.h>
#include "main.h"

extern char **environ;

int main ()
{
	char *str_line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int on = 1, i = 0;
	char **args;
	char path[][30] = {"/usr/local/bin/", "/usr/bin/", "/bin/", "/usr/local/games/", "/usr/games/"};

	if (!isatty(fileno(stdin))) /* non-interactive mode */
	{
		while((read_bytes = getline(&str_line, &len, stdin)) != -1) /* stdin into str_line */
		{
			if(read_bytes == -1) /* check if getline is succesfull */
			{
				printf("\n");
				on = 0;
			}

			printf("%s",str_line);
		}
	}
	else /* interactive mode */
		while (on != 0)
		{
			printf("($) ");
			read_bytes = getline(&str_line, &len, stdin); /* stdin into str_line */

			if(read_bytes == -1) /* check if getline is succesfull */
			{
				printf("\n");
				on = 0;
			}
			else
			{
				if (str_line[read_bytes - 1] == '\n')
				{
					str_line[read_bytes - 1] = '\0'; /* removed \n with \0 */
					read_bytes--; /* -1 to the old \n byte count */
				}

				if (strcmp(str_line, "exit") == 0) /* check if user put Exit */
					on = 0;
				else
				{
					args = get_tokens(str_line); /* makes tokens and args array with mallocs */

					if (access(args[0], X_OK) != 0) /* finds if file is excutable */
						printf("-bash: %s: command not found\n",args[0]);
					else
					{
						for (i = 0; path[i] != NULL; i++) /*iterate through path and concatenate with args[0]*/
						{
							char *full_path = malloc(strlen(path[i]) + strlen(args[0]) + 2); /* allocate memory */

							if (full_path == NULL) /* verify if malloc is succesful */
							{
								perror("Memory allocation error");
								exit(EXIT_FAILURE);
							}
							if (access(full_path, X_OK) == 0) /* verify if path is executable */
							{
								free(args[0]); /* execute command with full path */
								args[0] = full_path;
								break;
							}
							free(full_path); /* free memory for constructed path */
						}
					}
				}
				else /* function call for fork */
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

				for (i = 0; args[i] != NULL; i++) /* free the array and indxs */
					free(args[i]);
				free(args);
			}
		}
free(str_line);/* always free the str_line form stdin */
return (0);
}
