#include "monty.h"

/**
 * tokenize_lines - tokenizes input into separate words
 */

arg_t *arguments;

void tokenize_line(char *filename)
{
	char *delims = " \n\t\r";
	char *tokenizer = NULL, *item = NULL;
	size_t length = 0;
	stack_t *stack = NULL;

	arguments->stream = fopen(filename, "r");

	if (!arguments->stream)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&arguments->line, &length, arguments->stream) != -1)
	{
		tokenizer = strtok(arguments->line, delims); /* first command */

		if (tokenizer == NULL)
		{
			free(arguments);
			continue;
		}
		else if (*tokenizer == '#')
			continue;

		item = strtok(NULL, delims); /* integer after the command */

		arguments->line_num++;
		/*result = get_opcode(&stack, tokenizer, item, arguments->line_num);*/
		printf("%s\n", tokenizer);
		printf("%s\n", item);

		/* e.g.
		 * tokenizer = push
		 * item = 5 */
	}
}
