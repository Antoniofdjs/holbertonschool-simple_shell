#include "main.h"
#include <stdio.h>

char **get_tokens(char *str_line)
{
	char **array;
	int tok_count = 0;
	char *token, *str_line_dup;
	
	str_line_dup = strdup(str_line);
	token = strtok(str_line_dup, " ");

	while (token != NULL)
	{
		tok_count++;
		token = strtok(NULL, " "); /* next token */
	}

	free(str_line_dup);
	array = malloc((tok_count + 1) * sizeof(char *));

	if (array == NULL)
		return (NULL);

	token = strtok(str_line, " ");
	tok_count = 0;

	while (token != NULL)
	{
		array[tok_count] = strdup(token); /* dup tokens into args */
		tok_count++;
		token = strtok(NULL, " "); /* next token */
	}
	array[tok_count] = NULL;
	return (array);
}
