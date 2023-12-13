#include "monty.h"

void push(stack_t **stack, unsigned int line)
{
	stack_t *node = NULL;
	int i;
	char *token;

	token = strtok(commands[line - 1], " ");
	token = strtok(NULL, " ");
	
	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free(token);
		exit(EXIT_FAILURE);
	}
	
	node = malloc(sizeof(stack_t));
	node->n = atoi(token);
	node->next = NULL;
	node->prev = *stack;
	if (*stack)
		(*stack)->next = node;
	(*stack) = node;
}
