#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

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
        void (*f)(stack_t **stack, unsigned int line_number); /* executes opcode */
} instruction_t;

/**
 * struct arg_s - hold variables
 * @stream: File that connetcs to the stream from file
 * @line: string which will be the line of text read from stream
 *
 * Description: hold variables that will be used
 * in different functions of the project as well as variables
 * that will require malloc and freeing
 */

typedef struct arg_s
{
	FILE *stream;
	char *line;
	unsigned int line_number; /* we need the line_number in various files */
	char **tokens; /* store words in the lines read from the file */
	int n_tokens; /* allocate memory for the tokens array */
	instruction_t *instruction; /* pointer to instruction_s and contains a valid opcode from a line read */
	char *head;
	int stack_length;
} arg_t;

extern arg_t *arguments;

/* stream argument functions and handlers */
void validate_arguments(int argc);
void initialize_arguments();
void malloc_failed(void);
void get_stream(char *fileName);
void tokenize_line(void);
void get_instruction(void);
void free_tokens(void);
void close_stream(void);
void run_instruction(void);
void free_arguments(void);
void free_head(void);
void free_stack(stack_t *head);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif
