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

/**
 * pstr - prints the string starting at the top of the stack.
 *
 * @stack: inputs pointer to top.
 * @line_number: inputs line number.
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	char str[1024];
	stack_t *temp = *stack;
	int i = 0;
	(void)line_number;

	str[1024] = 0;
	while (temp != NULL || i < 1024)
	{
		if (temp->n > 127 || temp->n <= 0)
			break;
		str[i] = temp->n;
		temp = temp->next;
		i++;
	}

	str[i] = 0;
	printf("%s\n", str);
}
