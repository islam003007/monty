#ifndef MONTY
#define MONTY

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

FILE *file_open(int argc, char **argv);
void parser(char *line, char *args[]);
void free_stack(stack_t *stack);
int push(stack_t **stack, char *element, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void (*get_op(char *op_code, int line_n))(stack_t **, unsigned int);
void exit_stack(stack_t *stack, char *line, FILE *fp, int exit_num);

#endif
