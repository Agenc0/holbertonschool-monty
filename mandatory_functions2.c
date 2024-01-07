#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 * @stack: stack to swap the top two values
 * @line_number: line location
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp = 0;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}

/**
 * add - add two integers to the stack
 * @stack: stack to add two integers
 * @line_number: line location
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	pop(stack, line_number);
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
