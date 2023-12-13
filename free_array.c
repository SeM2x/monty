#include "monty.h"

/**
 * free_array - frees ana rray
 * @array: the array
 * @size: array's length
 *
 * Return: Void.
*/
void free_array(char **array)
{
	size_t i;

	if (array == NULL)
		return;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}
