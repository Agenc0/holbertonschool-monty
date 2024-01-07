#include "monty.h"

/**
 * stack_t - initializes a new nose
 * @n: value of node
 * 
 * Return: new node if successful, otherwise error
 */

stack_t *new_Node(int n)
{
	stack_t *new = NULL;

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
	stack_t *new = NULL;
	(void) line_number;

	if (op_toks[1] == NULL && isdigit(op_toks[1]) != 0)
	{
		push_error(*stack);
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

/**
 * free_stack - frees memory of a stack
 * @stack: stack to free memory
 */

void free_stack(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_stack(current->next);
		free(current);
	}
}
