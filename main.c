#include "monty.h"

/**
 * main - starting point
 * @ac: args count
 * @av: args vector
 *
 * Return: 0
*/
int main(int ac, char **av)
{
	char *content;
	int len, i;
	instruction_t *instructions;
	stack_t *stack = NULL;
		
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	

	content = get_file_content(av[1]);
	len = get_lines(content);
	commands = get_commands(content, len);
	instructions = get_instructs(commands, len);
	
	for (i = 0; i < len; i++)
	{
		instructions[i].f(&stack, i + 1);
	}

	return (0);
}
