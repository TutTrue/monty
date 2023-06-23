#include "monty.h"

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
	new_node = NULL;
}
