#include <stdio.h>
#include "main.h"

extern char **environ;

int main ()
{
	char *str_line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int on = 1;
	char **args;

	if (!isatty(fileno(stdin))) /* non-interactive mode */
	{
		while((read_bytes = getline(&str_line, &len, stdin)) != -1) /* stdin into str_line */
		{

			remove_newline(&str_line, &read_bytes);
			if (strcmp(str_line, "exit") == 0) /* check if user put Exit */
				on = 0;
			else
			{
				args = get_tokens(str_line); /* makes tokens and args array with mallocs */
				if (args[0] == NULL)/* args might be white spaces only */
				{
					free(str_line);
					free(args);
					return (main());
				}
				if (access(args[0], X_OK) != 0) /* finds if file is excutable */
					printf("-bash: %s: command not found\n", args[0]);
				else
					my_exe(args, environ);
			}
			free_args(args);
		}
	}

	else /* interactive mode */
	{
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
				remove_newline(&str_line, &read_bytes);
				if (strcmp(str_line, "exit") == 0) /* check if user put Exit */
					on = 0;
				else
				{
					args = get_tokens(str_line); /* makes tokens and args array with mallocs */
					if (args[0] == NULL) /* if args was null, maybe white spaces only */
					{
						free(str_line);
						free(args);
						return (main());
					}
					if (access(args[0], X_OK) != 0) /* finds if file is excutable */
						printf("-bash: %s: command not found\n", args[0]);
					else
						my_exe(args, environ);
					free_args(args);
				}
			}
		}
	}
	free(str_line);/* always free the str_line form stdin */
	return (0);
}
