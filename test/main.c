#include "monty.h"

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
	__ssize_t line_size;
	char *args[2];
	stack_t *stack = NULL;
	char *line = NULL;
	FILE *fp = file_open(argc, argv);
	size_t n = 0;
	unsigned int line_number = 0;
	int exit_error = 0;
	void (*operation)(stack_t **stack, unsigned int line_number);

	while (1)
	{
		line_number++;
		line_size = getline(&line, &n, fp);
		if (line_size == -1)
			break;
		parser(line, args);
		if (args[0] == NULL)
			continue;
		if (strcmp(args[0], "push") == 0 && args[0])
		{
			if (push(&stack, args[1], line_number) == -1)
				exit_error = 1;
			break;
		}
		operation = get_op(args[0], line_number);
		if (operation == NULL)
		{
			exit_error = 1;
			break;
		}
		operation(&stack, line_number);
	}
	free_stack(stack);
	free(line);
	fclose(fp);
	if (exit_error)
		exit(EXIT_FAILURE);
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
		{NULL, NULL}
	};

	for (i = 0; op_arr[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, op_arr[i].opcode) == 0)
			return (op_arr[i].f);
	}

	fprintf(stderr, "L%i: unknown instruction %s", line_n, op_code);
	return (NULL);
}
