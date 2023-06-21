#include "monty.h"

/**
 * free_stack - free all stack
 * @top: stack
 * Return:void
 */
void free_stack(stack_t **top)
{
	stack_t *cur = *top;

	if (!*top || !top)
		return;
	while (cur)
	{
		*top = (*top)->next;
		free(cur);
		cur = *top;
	}

}
