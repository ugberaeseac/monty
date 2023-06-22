#include "monty.h"

/**
 * _free_stack - frees a doubly list
 * @stack: double pointer to head node
 *
 * Return: void
 */
void _free_stack(stack_t *stack)
{

        if ((stack) == NULL)
                return;

        while (stack->next != NULL)
        {
                stack = stack->next;
                free(stack->prev);
        }
        free(stack);
}
