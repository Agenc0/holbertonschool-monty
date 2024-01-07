#include "monty.h"

/**
 * push_error - handle push error
 * @stack: pointer to a stack or queue
 */

void push_error(stack_t *stack)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", arguments->line_num);
	fclose(arguments->stream);
	free(arguments->line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * instruction_error - handle invalid instruction
 * @stack: poiner to a stack or queue
 * @tokenizer: tokenized work to print to stdout
 */

void instruction_error(stack_t *stack, char *tokenizer)
{
	dprintf(STDERR_FILENO, "L%u: unknown instructions %s\n",
			arguments->line_num, tokenizer);
	fclose(arguments->stream);
	free(arguments->line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
