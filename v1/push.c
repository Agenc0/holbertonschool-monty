#include "monty.h"

/**
 * push - pushes an element (int) to the stack
 * @stack: Pointer to the stack
 * @line_number: Line number where the push function is called
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (arguments->n_tokens <= 1 || !(isdigit(arguments->tokens[1])))
	{
		free_arguments();
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		malloc_failed();
	}

	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = (int) atoi(arguments->tokens[1]);

	if (arguments->head != NULL)
	{
		(*stack)->next = arguments->head;
		arguments->head->prev = *stack;
	}
	arguments->head = *stack;
	arguments->stack_length += 1;
}
