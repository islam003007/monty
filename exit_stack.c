#include "monty.h"

/**
 * exit_stack - exits the stack.
 *
 * @stack: inputs pointer to top.
 * @line: inputs pointer to line.
 * @fp: inputs file pointer.
 * @exit_num: inputs exit number.
*/
void exit_stack(char *stack, char *line, FILE *fp, int exit_num)
{
	free_stack(stack);
	free(line);
	fclose(fp);
	if (exit_num)
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
