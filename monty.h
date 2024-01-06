#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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

/**
 * struct arg_s - hold variables
 * @stream: File that connects to the stream from file
 * @line: string which will be the line of text read from stream
 *
 * Description: hold variables that will be used in
 * different functions of the project as well as
 * variables that will require memory allocation and freeing
 */

typedef struct arg_s
{
	FILE *stream;
	char *line;
	unsigned int line_num;
	int value;
} arg_t;

extern arg_t *arguments;

/* handle command input */
int main(int argc, char **argv);
void validate_args(int argc);
void initialize_args(void);
void tokenize_line(char *filename);
int get_opcode(stack_t **stack, char *arg, char *item, int line_number);

/* error handlers */
void push_error(stack_t *stack);
void instruction_error(stack_t *stack, char *tokenizer);

/* commands */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* free stack */
void free_stack(stack_t *stack);

#endif
