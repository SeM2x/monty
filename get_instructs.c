#include "monty.h"

instruction_t *get_instructs(char **cmds, int len)
{
	char *token, *opcode, *arg;
	char *tmp;
	int i = 0;
	instruction_t *instructions;

	if (cmds == NULL)
		return (NULL);

	instructions = malloc(len * sizeof(instruction_t));
	if (!instructions)
		print_err("Error: malloc failed");

	while (*cmds)
	{
		tmp = malloc(strlen(*cmds) * sizeof(char));
		if (!tmp)
			print_err("Error: malloc failed");
		strcpy(tmp, *cmds);
                token = strtok(tmp, " ");
                if (token != NULL)
                {
                        opcode = malloc(strlen(token) * sizeof(char));
			if (!opcode)
				print_err("Error: malloc failed");
			strcpy(opcode, token);
                        token = strtok(NULL, " ");
                        if (token != NULL)
			{
                                arg = malloc(strlen(token) * sizeof(char));
				if (!arg)
					print_err("Error: malloc failed");

				strcpy(arg, token);
			}
                        else
                                arg = NULL;
                }
                else
                        opcode = NULL;
		
		if (strcmp(opcode, "push") == 0)
			instructions[i].f = push;
		else if (strcmp(opcode, "pall") == 0)
			instructions[i].f = pall;
		else if (strcmp(opcode, "pint") == 0)
			instructions[i].f = pint;	
		else if (strcmp(opcode, "pop") == 0)
			instructions[i].f = pop;
		else if (strcmp(opcode, "swap") == 0)
			instructions[i].f = swap;
		else if (strcmp(opcode, "add") == 0)
			instructions[i].f = add;
		else if (strcmp(opcode, "nop") == 0)
			instructions[i].f = nop;
		else if (strcmp(opcode, "\n") == 0)
			instructions[i].f = nop;
		else
			instructions[i].f = inst_err;
		instructions[i].opcode = opcode;
		i++;
		cmds++;
	}

	return (instructions);
}
