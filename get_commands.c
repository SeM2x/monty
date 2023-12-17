#include "monty.h"

/**
 * get_commands - 
 * @str:
 *
 * Return:
*/
char **get_commands(char *str, int len)
{
	char **commands = NULL, buff[1024], *tmp;
	int i, j, k;

	if (!str)
		return (NULL);

	commands = malloc((len + 1) * sizeof(char *));
	if (!commands)
		print_err("Error: malloc failed");

	j = 0;
	k = 0;
	for (i = 0; i < (int) strlen(str); i++)
	{
		if (str[i] == '\n' || str[i] == '\0')
		{	
			buff[j] = '\0';
			tmp = strip(buff);
			strcpy(buff, tmp);
			free(tmp);

			commands[k] = malloc((strlen(buff) + 1) * sizeof(char));
			if (!commands[k])
					print_err("Error: malloc failed");	
			if (strcmp(buff, "\0"))
				strcpy(commands[k], buff);
			else
				strcpy(commands[k], "\n");
			k++;
			j = 0;
		}
		else
		{
			buff[j] = str[i];
			j++;
		}
	}

	commands[len] = NULL;
	return (commands);
}
