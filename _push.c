#include "monty.h"


/**
 * _add_node - adds a new node to beginning of doubly linked list
 * @stack: pointer to head of list
 * @n: integer value
 * 
 * Return: void
 */

void _add_node(stack_t **stack, int n)
{
        stack_t *new_node;

        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        new_node->prev = new_node->next = NULL;
        new_node->n = n;

        if ((*stack) == NULL)
                (*stack) = new_node;
        else
        {
                new_node->next = (*stack);
                (*stack)->prev = new_node;
                (*stack) = new_node;
        }

}




/**

 * _push - function that add an element to the stack
 * @token: opcodes/instruction
 * @stack: pointer to the top of the stack
 * @line_number: the line number of the command
 * Return: Nothing
 */
void _push(char *token, stack_t **stack, unsigned int line_number)
{
        int n;

        if((*stack) == NULL || stack == NULL)
                return;

        if (token != NULL)
        {
                n = _atoi(token);
                if (n != -1)
                        _add_node(stack, n);
                else
                {
                        fprintf(stderr, "L%d: usage: push integer\n", line_number);
                        exit(EXIT_FAILURE);
                }
        }

}




/**
 * _atoi - function that converts a string to integer
 * @str: string to convert
 *
 * Return: integer value of converted string
 */
int _atoi(char *str)
{
        int i;
        unsigned int int_num = 0;

        for (i = 0; str[i] != '\0'; i++)
        {
                if (str[i] >= '0' && str[i] <= '9')
                        int_num = int_num * 10 + (str[i] - '0');

                if (str[i] > '9' || str[i] < '0')
                        return (-1);
        }
        return (int_num);
}
