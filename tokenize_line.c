#include "monty.h"

/**
 * tokenize_lines - tokenizes input into separate words
 */

arg_t *arguments;

void tokenize_line(char *filename)
{
	char *delims = " \n\t\r";
	char *argtoken = NULL, *item = NULL;
	size_t length = 0;

	arguments->stream = fopen(filename, "r");

	if (!arguments->stream)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&arguments->line, &length, arguments->stream) != -1)
	{
		argtoken = strtok(arguments->line, delims); /* first command */

		if (argtoken == NULL)
		{
			free(argtoken);
			continue;
		}
		else if (*argtoken == '#')
			continue;

		printf("%s\n", argtoken);

		item = strtok(NULL, delims); /* integer after the command */
		if (item == NULL)
		{
			free(item);
			continue;
		}

		arguments->line_num++;
		/*result = get_opcode(&stack, argtoken, item, arguments->line_num);*/
		printf("%s\n", item);

		/* e.g.
		 * argtoken = push
		 * item = 5 */
	}
	fclose(arguments->stream);
	free(arguments->line);
}
