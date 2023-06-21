#include "monty.h"

/**
 * rotl - rotate the elements of the stack to the left
 * @stack: ...
 * @line_number: ...
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *cur, *last;

	if (!*stack || !stack || !(*stack)->next)
		return;
	temp = (*stack)->next;
	cur = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	temp = (*stack)->next;
	cur->next->prev = NULL;
	cur->prev = last;
	cur->next = NULL;
	last->next = cur;
	*stack = temp;
	(void)line_number;
}
