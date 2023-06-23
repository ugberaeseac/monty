#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 * Return: Void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n += (*stack)->n;
		(*stack) = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;

	}
}





/**
 * _sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack) = (*stack)->next;
		diff = (*stack)->n - (*stack)->prev->n;
		(*stack)->n = diff;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}




/**
 * _mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack) = (*stack)->next;
		product = (*stack)->n * (*stack)->prev->n;
		(*stack)->n = product;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}




/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else if ((*stack)->prev->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	else
	{
		(*stack) = (*stack)->next;
		result = (*stack)->n / (*stack)->prev->n;
		(*stack)->n = result;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}




/**
 * _mod - computes the modulus of the second top element of the stack
 * by the top element of the stack
 * @stack: double pointer to head node
 * @line_number: line number of instruction
 *
 * Return: Void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else if ((*stack)->prev->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	else
	{
		(*stack) = (*stack)->next;
		result = (*stack)->n % (*stack)->prev->n;
		(*stack)->n = result;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}

