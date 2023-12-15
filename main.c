#include "monty.h"
data_t data = {NULL, NULL, 0};

/**
 * main - entry point.
 *
 * @argc: argc.
 * @argv: argv.
 *
 * Return: 0 on success.
*/
int main(int argc, char **argv)
{
	char *args[2];
	ssize_t line_size;
	stack_t *stack = NULL;
	size_t n = 0;
	unsigned int line_number = 0;
	void (*operation)(stack_t **stack, unsigned int line_number);

	data.fp = file_open(argc, argv);
	while (1)
	{
		line_number++;
		line_size = getline(&data.line, &n, data.fp);
		if (line_size == -1)
			break;
		parser(data.line, args);
		if (args[0] == NULL || args[0][0] == '#')
			continue;
		if (strcmp(args[0], "push") == 0)
		{
			push(&stack, args[1], line_number);
			continue;
		}
		operation = get_op(args[0], line_number);
		if (operation == NULL)
			break;
		operation(&stack, line_number);
	}

	exit_stack(stack);
	return (0);
}

/**
 * file_open - opens file or sets error message.
 *
 * @argc: argc.
 * @argv: argv.
 *
 * Return: pointer to file.
*/
FILE *file_open(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fp);
}

/**
 * parser - parses line into op and argmunt.
 *
 * @line: inputs line.
 * @args: inputs args array to store arguments.
 */

void parser(char *line, char *args[])
{
	char *dilem = " \n\t";

	args[0] = strtok(line, dilem);
	args[1] = strtok(NULL, dilem);
}

/**
 * get_op - gets operation function.
 *
 * @op_code: inputs op argument.
 * @line_n: inputs line number.
 *
 * Return: pointer to op function.
*/
void (*get_op(char *op_code, int line_n))(stack_t **, unsigned int)
{
	int i;
	instruction_t op_arr[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	for (i = 0; op_arr[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, op_arr[i].opcode) == 0)
			return (op_arr[i].f);
	}

	fprintf(stderr, "L%i: unknown instruction %s\n", line_n, op_code);
	data.exit_num = 1;
	return (NULL);
}
