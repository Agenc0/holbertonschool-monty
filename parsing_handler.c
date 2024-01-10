#include "monty.h"

/**
 * validate_args - validates input arguments
 * @argc: argument counter to validate
 * @argv: argument vector to validate
 */

void validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	arguments.fd = fopen(argv[1], "r");
	if (!arguments.fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * tokenize_line - tokenizes each line from file into separate words
 */

void tokenize_line(void)
{
	size_t length = 0;
	unsigned int line_num = 1;
	char *delims = " \n";

	for (; getline(&arguments.buffer, &length, arguments.fd) != -1; line_num++)
	{
		arguments.token = strtok(arguments.buffer, delims);

		if (arguments.token)
		{
			arguments.f = get_op(arguments.token, line_num);
			arguments.token = strtok(NULL, delims);
			arguments.f(&arguments.top, line_num);
		}
	}
}

/**
 * get_op - sets opcode and instruction on the first token
 * @arg: instruction name
 * @line_number: line position in file
 *
 * Return: function address if successful, else exit failure
 */

void (*get_op(char *arg, unsigned int line_number))(stack_t **, unsigned int)
{
	int i;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; strcmp(op[i].opcode, arg) != 0; i++)
	{
		if (op[i + 1].opcode == NULL && op[i].opcode != arg)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, arg);
			free_stack();
			fclose(arguments.fd);
			exit(EXIT_FAILURE);
		}
	}
	return (op[i].f);
}

/**
 * free_stack - frees stack
 */

void free_stack(void)
{
	stack_t *tmp = NULL;

	while (arguments.top != NULL)
	{
		tmp = arguments.top;
		arguments.top = arguments.top->next;
		free(tmp);
	}

	free(arguments.top);
	free(arguments.buffer);
}

/**
 * is_digit - checks if a char type is a number in decimal value
 * @number: string
 * Return: 0 if string is number, otherwise -1
 */

int is_digit(char *number)
{
	int i = 0;

	if (number)
	{
		if (number[i] == '-')
			++i;

		while (number[i] != '\0')
		{
			if ((isdigit(number[i])) == 0)
				return (-1);
			i++;
		}
		return (0);
	}

	return (-1);
}
