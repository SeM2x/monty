#include "monty.h"

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	char msg[50];

	if(node && node->prev)
	{
		node = node->prev;
		if (node->next->n == 0)
		{
			sprintf(msg, "L%d: division by zero", line_number);
			print_err(msg);
		}
		node->n = node->n % node->next->n;
		*stack = node;
	}	
	else
	{
		sprintf(msg, "L%d: can't add, stack too short", line_number);
		print_err(msg);
	}

	
}
