#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: number of commmand
 * @argv: array of command
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	int num_line = 0;
	char line[max_bytes];
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Too Few Arguments\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, max_bytes, file)) != NULL)
	{
		line[strlen(line) - 1] = '\0';
		num_line++;
		parsing_line(line, num_line);
		check_opcodes(&stack, num_line);

	}
	free_dlistint(stack);
	fclose(file);
	return (0);
}

