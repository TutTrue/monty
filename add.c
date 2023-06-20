#include "monty.h"

/**
 * add - add first 2 element of the stack
 * @stack: ...
 * @line_number: ...
 */
void add(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cur = *stack;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n += temp;
	free(cur);
}
