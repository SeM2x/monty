#include "monty.h"

/**
 * get_commands - 
 * @str:
 *
 * Return:
*/
char **get_commands(char *str)
{
	char **commands = NULL, buff[1024], *tmp;
	int i, j, k, len = 0;

	if (!str)
		return (NULL);
	
	for (i = 0; i < (int) strlen(str); i++)
	{
		if (str[i] == '\n')
			len++;
	}

	commands = malloc((len + 1) * sizeof(char *));

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
			if (strcmp(buff, "\0"))
			{
				commands[k] = malloc((strlen(buff) + 1) * sizeof(char));
				strcpy(commands[k], buff);
				k++;
			}
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
