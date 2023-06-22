#include "monty.h"

/**
 * parsing_line - function that parses the instruction
 * @line: line to be parsed
 * Return: returns an array of tokens exactly two
 */
char **parsing_line(char *line)
{
	int i = 1;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		fprintf(stderr, "Malloc Failed");
		return (NULL);
	}
	tokens[0] = strtok(line, " \t");
	while (i < 2)
	{
		tokens[i] = strtok(NULL, " \t");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * check_opcodes - function that check for valid command
 * @line_number: the line of instruction in the file
 * Return: returns 0 if no valid command
 * otherwise returns 1 if Yess and Execute the function to it
 */
int check_opcodes(unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"push", _push},
		{NULL, NULL}
	};
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (!strcmp(tokens[0], instructions[i].opcode))
		{
			return (1);
		}
	}
	fprintf(stderr, "L:%d: unkown instruction\n", line_number);
	exit(EXIT_FAILURE);
}

