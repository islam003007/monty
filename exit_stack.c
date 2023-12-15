#include "monty.h"

/**
 * exit_stack - exits the stack.
 *
 * @stack: inputs pointer to top.
 *
*/
void exit_stack(stack_t *stack)
{
	free_stack(stack);
	free(data.line);
	fclose(data.fp);
	if (data.exit_num)
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
