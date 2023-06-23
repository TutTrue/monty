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
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n += temp;
	free(cur);
}

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
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	if (cur->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n /= temp;
	free(cur);
}

/**
 * mod - mod first 2 element of the stack
 * @stack: ...
 * @line_number: ...
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cur = *stack;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	if (cur->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n %= temp;
	free(cur);
}

/**
 * mul - mul first 2 element of the stack
 * @stack: ...
 * @line_number: ...
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cur = *stack;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n *= temp;
	free(cur);
}

/**
 * sub - sub first 2 element of the stack
 * @stack: ...
 * @line_number: ...
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cur = *stack;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n -= temp;
	free(cur);
}
