#include "monty.h"

/**
 * _div - div first 2 element of the stack
 * @stack: ...
 * @line_number: ...
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cur = *stack;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	if (cur->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n /= temp;
	free(cur);
}
