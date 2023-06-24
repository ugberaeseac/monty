#include "monty.h"

/**
 * _push - function that add an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number of the command
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	while (tokens[1][i] != '\0')
	{
		if (tokens[1][i] == '-')
		{
			if (_isdigit(tokens[1][i + 1]) != 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free_dlistint(*stack);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		else if (!_isdigit(tokens[1][i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	helper_push(stack, line_number);
}
