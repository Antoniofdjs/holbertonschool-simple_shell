#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
	char *str_line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int on = 1, tok_count = 0, i;
	char *args[20];
	char *token;

	while (on != 0)
	{
		printf("($) ");
		read_bytes = getline(&str_line, &len, stdin); /* stdin into str_line */

		if(read_bytes == -1)
			write(STDOUT_FILENO, "ERROR\n", 6);
		else
		{
			if (str_line[read_bytes - 1] == '\n')
			{
				str_line[read_bytes - 1] = '\0'; /* removed \n with \0 */
				read_bytes--; /* -1 to the old \n byte count */
			}

			if (strcmp(str_line, "Exit") == 0)
				on = 0;
			else
			{
				token = strtok(str_line, " "); /* make tokens */
				tok_count = 0;
				while (token != NULL)
				{
					args[tok_count] = strdup(token); /* dup tokens into args */
					tok_count++;
					token = strtok(NULL, " "); /* next token */
				}
				for (i = 0; i < tok_count; i++)/* print tokens */
				{
					printf("%s\n", args[i]);
					free(args[i]);
				}
			}
		}
	}
	free(str_line);
	return (0);
}
