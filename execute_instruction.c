#include "monty.h"

/**
 * execute_instruction - execute instruction
 * @data: ...
 */
void execute_instruction(Data *data)
{
	int i;
	char *str, *op;

	instruction_t ops[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"pchar", pchar}, {"pstr", pstr},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", mul},
		{"mod", mod}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL}
	};
	op = strtok(data->line, " \n\t");
	str = strtok(NULL, " ");
	if (op == NULL)
		return;
	else if (op[0] == '#')
		return;
	i = 0;

	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			data->str = str;
			ops[i].f(data->stack, data->line_number);
			/*free(str);*/
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", data->line_number, op);
	free_stack(data->stack);
	free(data->line);
	fclose(data->file);
	exit(EXIT_FAILURE);
}
