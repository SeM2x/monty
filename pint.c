#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	char msg[50];
	if(node)
		printf("%d\n", node->n);
	else
	{
		sprintf(msg, "L%d: can't pint, stack empty", line_number);
		print_err(msg);
	}

	
}
