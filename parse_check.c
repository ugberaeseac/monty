#include "monty.h"
#include "glo_var.h"

char *tokens[3];
/**
 * test_space_line - function to test the spaces
 * @line: pointer to the line in the file
 * Return: integer
 */
int test_space_line(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
/**
 * parsing_line - function that parses the instruction
 * @line: line to be parsed
 * Return: returns an array of tokens exactly two
 */
void parsing_line(char *line, unsigned int line_number)
{
	int i = 1;

	(void)line_number;
	tokens[0] = NULL;
	if (test_space_line(line))
	{
		tokens[0] = strtok(line, " \t");
		if (strcmp(tokens[0], "push") == 0)
		{
			tokens[i] = strtok(NULL, " \t");
			i++;
		}
		tokens[i] = NULL;
	}
}
/**
 * check_opcodes - function that check for valid command
 * @line_number: the line of instruction in the file
 * Return: returns 0 if no valid command
 * otherwise returns 1 if Yess and Execute the function to it
 */
void check_opcodes(stack_t **stack, unsigned int line_number)
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
	if (tokens[0] != NULL && *tokens[0] != '\0' && *tokens[0] != '#')
	{
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (!strcmp(tokens[0], instructions[i].opcode))
			{
				instructions[i].f(stack, line_number);
				break;
			}
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L:%d: unkown instruction\n", line_number);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}
	}
}
