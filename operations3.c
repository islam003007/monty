#include "monty.h"


/**
 * mod - computes the rest of division of the top 2 elements.
 *
 * @stack: inputs pointer to top.
 * @line_number: inputs line number.
*/
void mod(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
