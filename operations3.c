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

/**
 * pchar - prints the char at the top of the stack.
 *
 * @stack: inputs pointer to top.
 * @line_number: inputs line number.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}

	printf("%c\n", (*stack)->n);
}
