#include "monty.h"

void inst_err(stack_t **stack, unsigned int line)
{
	char *opcode = strtok(commands[line - 1], " ");

	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	free(*stack);
	exit(EXIT_FAILURE);

}
