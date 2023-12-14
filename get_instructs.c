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
		else
			instructions[i].f = inst_err;
		instructions[i].opcode = opcode;
		i++;
		cmds++;
	}

	return (instructions);
}
