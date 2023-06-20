#include "monty.h"

/**
 * rotr - rotate the elements of the stack to the right
 * @stack: ...
 * @line_number: ...
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur, *last;

	if (!*stack || !stack)
		return;
	cur = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = cur;
	cur->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;
}
