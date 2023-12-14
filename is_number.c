#include "monty.h"

int is_number(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	i = 0;
	if (str[i] == '-')
	{
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i]<'0' || str[i] > '9')
		{
			return 0;
		}
	}

	return (1);
}
