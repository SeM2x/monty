#include "monty.h"

void nop(stack_t **stack, unsigned int line_number)
{
	if(*stack)
		line_number++;	
}
