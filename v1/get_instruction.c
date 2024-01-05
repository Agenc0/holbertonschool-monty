#include "monty.h"

/**
 * invalid_instruction - Handles an unknown instruction error
 */
void invalid_instruction(void)
{
	dprintf(2, "L%d: unknown instruction %s\n",
			arguments->line_number, arguments->tokens[0]);
}


/**
 * get_instruction - sets the function based on the first token obtained
 * from the command-line input
 */

void get_instruction(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{NULL, NULL}
	};

	if (arguments->n_tokens == 0) /* no instructions were parsed */
		return;

	while (instructions[i].opcode)
	{
		/* compare opcode of instruction to first token */
		if (strcmp(instructions[i].opcode, arguments->tokens[0] == 0))
		{
			arguments->instruction->opcode = instructions[i].opcode;
			arguments->instruction->f = instructions[i].f;
			return;
		}
		i++;
	}
		invalid_instruction();
}
