#include "monty.h"

/**
 * pchar - print top
 * @stack: ...
 * @line_number: ...
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	if (top->n >= 0 && top->n <= 127)
		printf("%c\n", top->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(global_data.stack);
		free(global_data.line);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
}
