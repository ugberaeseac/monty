#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to head node
 * @line_number: line number of opcode instruction
 *
 * Return: Void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n <= 127 && (*stack)->n >= 0)
	{
		putchar('0' + (*stack)->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}





/**
 * _pstr - prints the string starting at the top of the stack then a new line
 * @stack: double pointer to head node
 * @line_number: line number of opcode instruction
 *
 * Return: Void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = (*stack);
	if ((*stack) == NULL || stack == NULL)
		putchar('\n');

	if ((*stack)->n <= 127 && (*stack)->n >= 0)
	{
		while (temp != NULL && temp != 0)
		{
			putchar('0' + temp->n);
			temp = temp->next;
		}
	}
	putchar('\n');
}
