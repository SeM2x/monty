#include "monty.h"

int get_lines(const char *str)
{
	int lines, isNonEmptyLine, i;

	if (str == NULL)
	{
		return (0);
	}

	lines = 0;
	isNonEmptyLine = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			if (isNonEmptyLine)
			{
				lines++;
			}

			isNonEmptyLine = 0;
		}
		else if (!isspace((unsigned char) str[i]))
		{
			isNonEmptyLine = 1;
		}
	}

	if (isNonEmptyLine)
	{
		lines++;
	}

	return (lines);
}
