#include "monty.h"

/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp;

	if ((*stack) == NULL || stack == NULL)
		return (NULL);

	temp = (*stack);
	while (temp->next != NULL)
	{
		fprintf(stderr, "%d\n", temp->n);
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
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stderr, "%d\n", stack->n);
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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		(*stack) == NULL;
		free(*temp);
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}

}




/**
 * _swap - swaps the top two elements of the stack
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	temp = (*stack);
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
	}
}
