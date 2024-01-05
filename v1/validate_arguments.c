#include "monty.h"

/**
 * validate_arguments - Checks the numebr of command-line args
 * @argc: Argument counter
 */

void validate_arguments(int argc)
{
	if (argc == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
