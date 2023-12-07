#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
	char *str_line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int on = 1;

	while (on != 0)
	{
		printf("($) ");
		read_bytes = getline(&str_line, &len, stdin);

		if(read_bytes == -1)
			write(STDOUT_FILENO, "ERROR\n", 6);
		else
		{
			if (str_line[read_bytes - 1] == '\n')
			{
				str_line[read_bytes - 1] = '\0'; /* removed \n with \0 */
				read_bytes--;
			}

			printf("COMMAND ENTERED: ");
			printf("%s\n", str_line);


		}
		if (strcmp(str_line, "Exit") == 0)
			on = 0;
	}
	free(str_line);
	return (0);
}
