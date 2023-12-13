#include "monty.h"

void init(stack_t **stack)
{
	(*stack)->prev = NULL;
	(*stack)->next = NULL;	
}
