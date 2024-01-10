#include "monty.h"

/**
 * validate_args - Checks the number of args from the command-line arguments
 * @argc: Number of args
 */

void validate_args(int argc)
{
	if (argc == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
