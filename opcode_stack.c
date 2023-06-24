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
	stack_t *temp;

	(void)line_number;
	if ((*stack) == NULL || stack == NULL)
		exit(EXIT_FAILURE);

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
	(*stack) = temp->next;
	if (temp->next != NULL)
		(*stack)->prev = NULL;
	free(temp);

}


/**
 * _swap -  swaps the top two elements of the stack
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = (*stack);
		(*stack)->prev = temp;
		temp->next = (*stack);
		temp->prev = NULL;
		(*stack) = temp;
	}
}






/**
 * _nop - nop opcode does nothing
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)(*stack);
	(void)(line_number);
}
