#include "monty.h"

/**
 * pall - print the stack
 * @stack: ...
 * @line_number: ...
 * Return:void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (!*stack)
		return;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
