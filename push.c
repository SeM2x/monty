#include "monty.h"

void push(stack_t **stack, unsigned int line)
{
	stack_t *node = NULL;
	char *token;

	token = strtok(commands[line - 1], " ");
	token = strtok(NULL, " ");
	
	if (token == NULL || !is_number(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	
	node = malloc(sizeof(stack_t));
	if (!node)
		print_err("Error: malloc failed");

	node->n = atoi(token);
	node->next = NULL;
	node->prev = *stack;
	if (*stack)
		(*stack)->next = node;
	(*stack) = node;
}
