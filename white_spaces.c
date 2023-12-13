#include <stdio.h>
#include "main.h"

/**
 * white_spaces - checks if args is null, has only white spaces
 * @args: array from get_tokens, from main
 * @str_line: string from main, from stdin
 * Return: 0 if args was null(white spaces only)
 */

int white_spaces(char **args, char *str_line)
{
	if (args[0] == NULL) /* white spaces only */
	{
		free(str_line);
		free(args);
		return (0);
	}

	return (-1);
}
