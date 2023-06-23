#include "monty.h"

int switch_mode(char *op);
/**
 * execute_instruction - execute instruction
 * @data: ...
 */
void execute_instruction(Data *data)
{
	int i;
	char *str, *op;

	instruction_t ops[] = {
		{"push", push}, {"push", push_end},
		{"pall", pall}, {"pint", pint},
		{"pchar", pchar}, {"pstr", pstr},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", mul},
		{"mod", mod}, {"rotl", rotl},
		{"rotr", rotr}, {"pop", pop},
		{NULL, NULL}
	};
	op = strtok(data->line, " \n\t");
	str = strtok(NULL, " \n\t");
	if (op == NULL)
		return;
	else if (op[0] == '#')
		return;
	i = 0;

	while (ops[i].opcode && op)
	{
		if (switch_mode(op))
			return;
		if (strcmp(op, ops[i].opcode) == 0)
		{
			if (strcmp(op, "push") == 0 && global_data.mode == 'S')
			{
				data->str = str ? str : "e";
				ops[i].f(data->stack, data->line_number);
				return;
			}
			else if (strcmp(op, "push") == 0 && global_data.mode == 'Q')
			{
				data->str = str ? str : "e";
				ops[++i].f(data->stack, data->line_number);
				return;
			}
			else
			{
				data->str = str ? str : "e";
				ops[i].f(data->stack, data->line_number);
				return;
			}
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", data->line_number, op);
	free_stack(data->stack);
	free(data->line);
	fclose(data->file);
	exit(EXIT_FAILURE);
}
/**
 * switch_mode - switch queue to stack or oppest
 * @op: op code
 * Return: 1 if succes 0 or not
 */
int switch_mode(char *op)
{
	if (strcmp(op, "stack") == 0)
	{
		global_data.mode = 'S';
		return (1);
	}
	else if (strcmp(op, "queue") == 0)
	{
		global_data.mode = 'Q';
		return (1);
	}
	else
		return (0);
}
