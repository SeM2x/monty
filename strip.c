#include "monty.h"

/**
 *strip - remove spaces from both sides a string
 *@word: the string
 *
 *Return: a pointer to the striped string.
 */
char *strip(char *input)
{
	size_t len = strlen(input);
	char result[1024 * 1024], *res;
	size_t i, j = 0;
	int prev_space = 1;

	if (result == NULL)
	{
		perror("malloc");
		free(result);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++)
	{
		if (isspace((unsigned char) input[i]))
		{
			if (!prev_space)
			{
				result[j++] = ' ';
				prev_space = 1;
			}
		}
		else
		{
			result[j++] = input[i];
			prev_space = 0;
		}
	}

	if (j > 0 && result[j - 1] == ' ')
	{
		j--;
	}

	result[j] = '\0';

	res = malloc(strlen(result) * sizeof(char));
	if (!res)
		print_err("Error: malloc failed");
	strcpy(res, result);
	return (res);
}
