#include "monty.h"

/**
 * _free_stack - frees a doubly list
 * @head: double pointer to head node
 *
 * Return: void
 */
void _free_stack(stack_t **head)
{

	if ((*stack) == NULL)
		return;

	while ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		free((*stack)->prev);
	}
	free((*stack));
}
