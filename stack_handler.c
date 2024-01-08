#include "monty.h"

/**
 * check_mode - checks if a stack_t is whether a stack or queue
 * @stack: pointer to the stack
 *
 * Return: 0 if its a stack
 * 1 if its a queue
 * else 2
 */

int check_mode(stack_t *stack)
{
	if (stack->n == 0)
		return (0);
	else if (stack->n == 1)
		return (1);
	return (2);
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

void clean_stack(stack_t *stack)
{
	stack_t *current = stack;

	for (; current; current = stack)
	{
		stack = stack->next;
		free(current);
	}
}
