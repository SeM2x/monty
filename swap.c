#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	char msg[50];
	int tmp;

	if(node && node->prev)
	{
		tmp = node->n;
		node->n = node->prev->n;
		node->prev->n = tmp;
	}	
	else
	{
		sprintf(msg, "L%d: can't swap, stack too short", line_number);
		print_err(msg);
	}

	
}
