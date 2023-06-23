#include "monty.h"

/**
 * push - push in stack
 * @stack: ...
 * @line_number: ...
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int num;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	if (!atoi(global_data.str) && global_data.str[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	num = atoi(global_data.str);
	new_node->n = num;
	new_node->prev = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * push_end - push at end
 * @stack: ...
 * @line_number: ...
 */
void push_end(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t)), *p = *stack;
	int num;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		exit(EXIT_FAILURE);
	}
	if (!atoi(global_data.str) && global_data.str[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(global_data.stack);
		fclose(global_data.file);
		free(global_data.line);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	num = atoi(global_data.str);
	new_node->n = num;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
		return;
	}
	while (p->next)
		p = p->next;
	p->next = new_node;
	new_node->prev = p;
	new_node->next = NULL;
}

/**
 * pall - print the stack
 * @stack: ...
 * @line_number: ...
 * Return:void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (!stack || !*stack)
		return;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
	(void)line_number;
}

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
		free(global_data.line);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}

/**
 * pstr - print the string starting from top of stack, followed by new line
 * @stack: ...
 * @line_number: ...
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (!p)
	{
		printf("\n");
		return;
	}
	while (p)
	{
		if (p->n > 0 && p->n <= 127)
			printf("%c", p->n);
		else
			break;
		p = p->next;
	}
	printf("\n");
	(void)line_number;
}
