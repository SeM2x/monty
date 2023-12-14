#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	char msg[50];

	if(*stack)
	{
		(*stack) = (*stack)->prev;
	}	
	else
	{
		sprintf(msg, "L%d: can't pop an empty stack", line_number);
		print_err(msg);
	}

	
}
