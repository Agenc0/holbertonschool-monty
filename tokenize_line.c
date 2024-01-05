#include "monty.h"

/**
 * tokenize_lines - tokenizes input into separate words
 */

void tokenize_line(char *filename)
{
	char *delims = " \n\t\r", *tokenizer;
	size_t length = 0;
	char *buffer, *item = NULL;

	arguments->stream = fopen(filename, "r");

	if (!arguments->stream)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&arguments->line, &length, arguments->stream) != -1)
	{
		tokenizer = strtok(arguments->line, delims); /* first command */
		printf("%s\n", tokenizer);
		item = strtok(NULL, delims); /* integer after the command */

		/* e.g.
		 * tokenizer = push
		 * item = 5 */
	}
}
