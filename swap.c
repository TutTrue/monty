#include "monty.h"

/**
 * swap - swap first 2 element of the stack
 * @stack: ...
 * @line_number: ...
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *cur, *next;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	next = (*stack)->next;
	cur->next = next->next;
	cur->prev = next;
	next->next = cur;
	next->prev = NULL;
	cur->next->prev = cur;
	*stack = next;
}
