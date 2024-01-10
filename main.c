#include "monty.h"

/**
 * main - main function for monty bytecode program
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 if successful
 */

int main(int argc, char **argv)
{
	validate_args(argc, argv);
	tokenize_line();
	free_stack();
	fclose(arguments.fd);
	return (0);
}
