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

/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if ((*stack) == NULL || stack == NULL)
		return;

	temp = (*stack);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _pint - prints all the values at the top the stack
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _pint(stack_t **stack, unsigned int line_number)
{

	if ((*stack) == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}




/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to head  node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = (*stack);
	if ((*stack) == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(temp);
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}

}

