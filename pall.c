#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	while(node)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
	line_number++;
}
