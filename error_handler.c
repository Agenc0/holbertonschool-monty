#include "monty.h"

/**
 * push_error - handle push error
 * @line_number: line location in file
 */

void push_error(unsigned int line_number)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
	free_stack();
	fclose(arguments.fd);
	exit(EXIT_FAILURE);
}

/**
 * instruction_error - handle invalid instruction
 * @tokenizer: tokenized word to printn to stdout
 * @line_number: line location in file
 */

void instruction_error(char *tokenizer, unsigned int line_number)
{
	dprintf(STDERR_FILENO, "L%u: unknown instructions %s\n",
			line_number, tokenizer);
	free_stack();
	fclose(arguments.fd);
	exit(EXIT_FAILURE);
}
