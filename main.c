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
	len = 0;
	for (i = 0; i < (int) strlen(content); i++)
	{
		if (content[i] == '\n')
			len++;
	}
	commands = get_commands(content);
	instructions = get_instructs(commands, len);
	
	for (i = 0; i < len; i++)
	{
		instructions[i].f(&stack, i + 1);
	}

	free(content);
	free_array(commands);
	/*
	for (i = 0; instructions[i].opcode != NULL; i++)
		    free(instructions[i].opcode);
	*/
	return (0);
}
