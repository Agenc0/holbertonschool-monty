#include "monty.h"

arg_t *arguments;

/**
 * tokenize_line - tokenizes lines from .m file
 * @filename: filename or filepath of the target file
 */

void tokenize_line(char *filename)
{
	char *delims = "$ \n";
	char *tokenizer, *item;
	size_t length = 0;
	int result = 0;
	stack_t *stack = NULL;

	arguments->stream = fopen(filename, "r");

	if (!arguments->stream)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		free(arguments);
		exit(EXIT_FAILURE);
	}

	while (getline(&arguments->line, &length, arguments->stream) != -1)
	{
		arguments->line_num++;
		tokenizer = strtok(arguments->line, delims); /* first command */

		if (tokenizer == NULL)
			continue;

		else if (*tokenizer == '#')
			continue;

		item = strtok(NULL, delims);
		if (item == NULL)
			continue;

		result = get_opcode(&stack, tokenizer, item, arguments->line_num);

		if (result == 1)
			push_error(stack);
		else if (result == 2)
			instruction_error(stack, tokenizer);
	}
	fclose(arguments->stream);
	clean_stack(stack);
	free(arguments->line);
	free(arguments);
}
