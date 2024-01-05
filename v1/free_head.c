#include "monty.h"

/**
 * free_head - frees the memory allocated for the head
 * and sets it to NULL
 */

void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);

	arguments->head = NULL;
}
