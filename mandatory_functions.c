#include "monty.h"

/**
 * new_Node - initializes a new nose
 * @n: value of node
 *
 * Return: new node if successful, otherwise error
 */

stack_t *new_Node(int n)
{
	stack_t *new = NULL;
	(void) n;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * push - pushes an element onto the stack
 * @stack: target stack to push element
 * @line_number: line location
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void) line_number;
	int i;

	if (op_toks[1] == NULL)
	{
		push_error(*stack);
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			push_error(*stack);
		}
	}

	new = new_Node(atoi(op_toks[1]));

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all elements in the stack, starting from the top
 * @stack: target stack to print all elements
 * @line_number: line location
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void) line_number;

	tmp = *stack;

	while (tmp != NULL)
	{
		dprintf(STDIN_FILENO, "%d\n", tmp->n);
		tmp = tmp->next;
	}

	free(tmp);
}

/**
 * pint - prints the value at the top
 * of the stack, followed by newline
 * @stack: stack to get top value from
 * @line_number: line location
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: stack to remove top value from
 * @line_number: line location
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
}
