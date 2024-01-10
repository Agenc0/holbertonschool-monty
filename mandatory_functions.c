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

/**
 * pall - prints all elements in stack, starting from top
 * @stack: pointer to top of the stack
 * @line_number: line location in file
 */

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

/**
 * pint - prints the top element of the stack
 * @stack: pointer to top of the stack
 * @line_number: line location in file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(arguments.fd);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to top of the stack
 * @line_number: line location in file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!*stack)
	{
		fprintf(stderr,	"L%u: can't pop an empty stack\n", line_number);
		fclose(arguments.fd);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	if (*stack)
		(*stack)->prev = NULL;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to top of the stack
 * @line_number: line location in file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeStack();
		fclose(glob.fd);
		exit(EXIT_FAILURE);
	}

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack();
		fclose(glob.fd);
		exit(EXIT_FAILURE);
	}

	tmp->n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp->n;
	free(tmp);
}
