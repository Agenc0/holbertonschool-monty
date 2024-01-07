#include "monty.h"

char **op_toks = NULL;

int main(int argc, char **argv)
{
	validate_args(argc);
	initialize_args();
	tokenize_line(argv[1]);

	return (0);
}
