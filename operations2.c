#include "monty.h"

/**
 * add - adds the last 2 values of the stack.
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

/**
 * nop - does nothing.
 *
 * @stack: inputs pointer to top.
 * @line_number: inputs line number.
*/
void nop(stack_t **stack, unsigned int line_number)
{

	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the last 2 values of the stack.
 *
 * @stack: inputs pointer to top.
 * @line_number: inputs line number.
*/
void sub(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
