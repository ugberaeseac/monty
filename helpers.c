#include "monty.h"

extern char *tokens[3];
/**
 * helper_push - function that add at the begining of the list
 * @head: pointer to the top of the stack
 * @number: data of the element to be added to the stack
 */
void helper_push(stack_t **head, unsigned int number)
{
	stack_t *new_node;

	(void)number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return;
	new_node->n = atoi(tokens[1]);
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}
/**
 * _isdigit -  a function that checks for a digit 0-9
 * @c: input
 * Return: 1 if c is a digit, 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
 * free_dlistint - function that free the whole list
 * @head: pointer to the first node in the list
 * Return: Nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

