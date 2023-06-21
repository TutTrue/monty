#include "monty.h"

/**
 * push - push in stack
 * @stack: ...
 * @line_number: ...
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t **top = stack;
	int num;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(global_data.stack);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	if (!atoi(global_data.str) && global_data.str[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		if (global_data.stack)
			free_stack(global_data.stack);
		fclose(global_data.file);
		exit(EXIT_FAILURE);
	}
	num = atoi(global_data.str);
	new_node->n = num;
	if (!*top)
	{
		*top = new_node;
		return;
	}
	new_node->next = *top;
	(*top)->prev = new_node;
	*top = new_node;
}
