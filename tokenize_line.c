#include "monty.h"

/**
 * tokenize_lines - tokenizes input into separate words
 */

void tokenize_line(char *filename)
{
	char *delims = " \n$", *tokenizer;
	unsigned int length;
	char *buffer;
	FILE *file;

	file = fopen(filename, "r");

	if (!file)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fseek(file, 0, SEEK_END); /* seek to EOF */
	length = ftell(file);
	fseek(file, 0, SEEK_SET); /* seek to beginning of file */
	buffer = malloc(sizeof(char) * length);

	while (fgets(buffer, length, file))
	{
		tokenizer = strtok(buffer, delims);
		while (tokenizer != NULL)
		{
			printf("%s\n", tokenizer);
			tokenizer = strtok(NULL, delims);
		}
	}

	printf("\n");
	fclose(file);
}
