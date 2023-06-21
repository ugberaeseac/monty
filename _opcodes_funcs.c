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
		printf("L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", stack->n);
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
		printf("L%d: can't pop an empty stack", line_number);
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
	int count = 0;

	temp = (*stack);
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	if (count < 2)
	{
		printf("L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
	}
}
