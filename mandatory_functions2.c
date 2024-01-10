#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to top of the stack
 * @line_number: line location in file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	current = (*stack);
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->prev = NULL;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;

	free(current);
}

/**
 * nop - uhhhhh doesn't do anything
 * @stack: stack
 * @line_number: line location
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
