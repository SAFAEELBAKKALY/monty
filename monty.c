#include "monty.h"

/**
 * main - programme monty
 * @argc: input
 * @argv: input
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char l[254];
	FILE *file;
	stack_t *stack;
	void (*instruction)(stack_t **stack, unsigned int line_number);
	unsigned int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	stack = NULL;
	if (!file)
	{
		fprintf(stderr, "Error: can't open file%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while (fgets(l, sizeof(l), file))
	{
		instruction = opcodes_instruction(l, line_number);
		if (instruction != NULL)
			instruction(&stack, line_number);
		line_number++;
	}
	_free(&stack);
	exit(EXIT_SUCCESS);
}
