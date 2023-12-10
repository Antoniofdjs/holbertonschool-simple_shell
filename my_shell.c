#include <stdio.h>
#include "main.h"
int main ()
{
	char *str_line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int on = 1, i = 0;
	char **args;

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

			if (strcmp(str_line, "Exit") == 0) /* check if user put Exit */
				on = 0;
			else
			{
				args = get_tokens(str_line); /* makes tokens and args array with mallocs */
				execve(args[0], args, NULL);
				
				for (i = 0; args[i] != NULL; i++) /* free the array and indxs */
					free(args[i]);
				free(args);
			}
		}
	}
	free(str_line);/* always free the str_line form stdin */
	return (0);
}
