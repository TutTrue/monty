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

/**
 * free_stack - free all stack
 * @top: stack
 * Return:void
 */
void free_stack(stack_t **top)
{
	stack_t *cur = *top;

	if (!*top || !top)
		return;
	while (cur)
	{
		*top = (*top)->next;
		free(cur);
		cur = *top;
	}

}
