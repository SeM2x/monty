#include "monty.h"

/**
 * free_instructs - frees ana rray
 * @array: the array
 * @size: array's length
 *
 * Return: Void.
*/
void free_instructs(instruction_t *array)
{
	size_t i;

	if (array == NULL)
		return;


	free(array);
}
