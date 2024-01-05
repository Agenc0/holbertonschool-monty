#include "monty.h"

/**
 * main - Entry point
 * @argc: argument counter
 * @argv: argument vector with command-line arguments
 *
 * Return: 0 if successful
 */

int main(int argc, char **argv)
{
	size_t n = 0;

	validate_arguments(argc);
	initialize_arguments();
	get_stream(argv[1]);

	while (getline(&arguments->line, &n, arguments->stream) != -1)
	{
		arguments->line_number += 1; /* tracking the line number of the file */
		tokenize_line(); /* breaking down the lines into words */
		get_instruction();
		run_instruction();
		free_tokens();
	}

	close_stream();
	free_arguments();

	return (0);
}
