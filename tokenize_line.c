#include "monty.h"

char **op_toks = NULL;
arg_t *arguments;

/**
 * free_tokens - frees tokens
 */

void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * tokenize_line - tokenizes lines from .m file
 * @filename: filename or filepath of the target file
 */

void tokenize_line(char *filename)
{
	char *delims = " \n";
	size_t length = 0;
	int result = 0;
	stack_t *stack = NULL;

	arguments->stream = fopen(filename, "r");

	if (!arguments->stream)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&arguments->line, &length, arguments->stream) != -1)
	{
		arguments->line_num++;
		op_toks = strtow(arguments->line, delims); /* first command */

		if (op_toks == NULL)
			continue;

		else if (op_toks[0][0] == '#')
			continue;

		result = get_opcode(&stack, op_toks[0], arguments->line_num);

		if (result == 1)
			push_error(stack);
		else if (result == 2)
			instruction_error(stack, op_toks[0]);
	}
	fclose(arguments->stream);
	free(arguments->line);
}
