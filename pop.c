#include "monty.h"

/**
 * pop - delete top
 * @stack: ...
 * @line_number: ...
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *cur;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	*stack = (*stack)->next;
	free(cur);
}
