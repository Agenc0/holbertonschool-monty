#include "monty.h"

/**
 * initialize_args - initializes a pointer to arg_s structure
 */

arg_t *arguments;

void initialize_args(void)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		{
			fprintf(stderr, "Error: Memory allocation for struct arg_s");
			exit(EXIT_FAILURE);
		}
	arguments->stream = NULL;
	arguments->line = NULL;
	arguments->line_num = 0;
}
