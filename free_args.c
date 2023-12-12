#include "main.h"
#include <stdio.h>
/**
 * free_args - free the args array
 * @args : array from get tokens, tokenization of str_line
 */

void free_args(char **args)
{
	int i = 0;

	for (i = 0; args[i] != NULL; i++) /* free the array and the indxs */
		free(args[i]);
	free(args);
}
