#include "monty.h"

/**
 * push - pushes element into the stack.
 *
 * @stack: inputs pointer to the top of the stack.
 * @element: inputs element to be pushed.
 * @line_number: inputs pointer to line number.
 *
 * Return: 0 on success, -1 if it failed.
*/

int push(stack_t **stack, char *element, unsigned int line_number)
{
	stack_t *new_top;

	if (element == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}
	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		data.exit_num = 1;
		exit_stack(*stack);
	}

	new_top->n = atoi(element);
	new_top->next = NULL;
	new_top->prev = NULL;
	if (*stack != NULL)
	{
		new_top->next = *stack;
		(*stack)->prev = new_top;
	}
	*stack = new_top;

	return (0);
}


/**
 * pall - prints all elements of the stack.
 *
 * @stack: inputs pointer to the top of the stack.
 * @line_number: inputs line number.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;

	while (temp != NULL)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}


/**
 * pint - prints the value at the top of the stack.
 *
 * @stack: inputs pointer to top.
 * @line_number: inputs line number.
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}
	printf("%i\n", (*stack)->n);
}

/**
 * pop - prints the value at the top of the stack.
 *
 * @stack: inputs pointer to top.
 * @line_number: inputs line number.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		data.exit_num = 1;
		exit_stack(*stack);
	}

	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



