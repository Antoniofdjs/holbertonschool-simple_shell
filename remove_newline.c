#include <stdio.h>
#include "main.h"
/**
 * remove_newline - removes new line.
 * @str_line: 
 * @read_bytes: total chars read for str_line
 */

void remove_newline(char **str_line, ssize_t *read_bytes)
{
	if ((*str_line)[strlen(*str_line) - 1] == '\n')
	{
		(*str_line)[strlen(*str_line) - 1] = '\0'; /* removed \n with \0 */
		(*read_bytes)--; /* -1 to the old \n byte count */
	}
}
