#include "monty.h"

/**
 * get_opcode - sets the opcode and instruction on the first token
 * @stack: pointer to a pointer to a stack or queue
 * @arg: argument parsed to execute opcode
 * @item: integer to be trated with the according argument
 * @line_number: number of line
 *
 * Return: 0 if successful, else 1 if item isn't an integer
 * 2 if argument does not match opcode.
 */

arg_t *arguments;

int get_opcode(stack_t **stack, char *arg, char *item, int line_number)
{
	int i = 0, j;
	int *buffer;

	instruction_t op[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop}
	};

	buffer = malloc(sizeof(item) * sizeof(int));
	while (op[i].opcode)
	{
		if (strcmp(arg, op[i].opcode))
		{
			if (strcmp(arg, "push")) /* check if arg is push to use item */
			{
				for (j = 0; item[j] != '\0'; j++)
				{
					if (isdigit(item[j]) != 0)
						buffer[j] = atoi(item);
					else
						return (1);
				}
			}
			op[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
