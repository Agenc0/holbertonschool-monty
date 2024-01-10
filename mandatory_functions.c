#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: pointer to the top of stack
 * @line_number: line location in file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (is_digit(arguments.token) == -1)
	{
		push_error(line_number);
	}

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		fclose(arguments.fd);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(arguments.token);
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;

	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
