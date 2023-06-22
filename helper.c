#include "monty.h"
/**
 * is_digits - see if string is digit
 * @str: string to check
 * Return: 1 if is digit 0 otherwise
 */
int is_digits(char *str)
{
	int i;

	if (str[0] == '-')
		str++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
	}
	return (1);
}

