#include "monty.h"

int get_lines(const char *str)
{
	int lines, i;

	if (str == NULL)
	{
		return (0);
	}

	lines = 0;
	
	for (i = 0; i < (int) strlen(str); i++)
	{
		if (str[i] == '\n')
			lines++;
	}	

	return (lines);
}
