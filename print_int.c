#include "monty.h"

/**
 * pint - print top
 * @stack: ...
 * @line_number: ...
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
