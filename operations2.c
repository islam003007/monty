#include "monty.h"

/**
 * add - prints the value at the top of the stack.
 *
 * @stack: inputs pointer to top.
 * @line_number: inputs line number.
*/
void add(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
