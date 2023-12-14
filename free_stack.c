#include "monty.h"

/**
 * free_stack - frees stack
 *
 * @stack: inputs stack top.
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
