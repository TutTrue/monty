#include "monty.h"

/**
 * pstr - print the string starting from top of stack, followed by new line
 * @stack: ...
 * @line_number: ...
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (!p)
		printf("\n");
	while (p)
	{
		if (p->n > 0 && p->n <= 127)
			printf("%c", p->n);
		else
			break;
		p = p->next;
	}
	printf("\n");
}
