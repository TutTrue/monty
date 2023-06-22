#include "monty.h"
Data global_data = {NULL, NULL, 0, NULL, NULL};
/**
 * main - ...
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	FILE *file;

	if (argc != 2)
	{

		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "rb");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	global_data.file = file;
	global_data.stack = &stack;
	while (getline(&line, &len, file) != -1)
	{
		global_data.line = line;
		global_data.line_number = line_number++;
		execute_instruction(&global_data);
	}
	free(line);
	fclose(file);
	free_stack(&stack);
	return (0);
}
