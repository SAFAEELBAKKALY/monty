#include "monty.h"

/**
 * main - programme monty
 * @argc: input
 * @argv: input
 * Return: 0
 */

int main(int argc, char *argv[])
{
	instruction_t instructions[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"swap", opcode_swap},
		{"pop", opcode_pop},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{"mul", opcode_mul},
		{"mod", opcode_mod},
		{NULL, NULL}
	};
	char l[256], opcode[256];
	FILE *file;
	int argument, items_read, i = 0;
	stack_t *stack;
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
	line_number = 0;
	while (fgets(l, sizeof(l), file))
	{
		line_number++;
		items_read = sscanf(l, "%s %d", opcode, &argument);
		if (items_read == 1)
			argument = 0;
		else if (items_read != 2)
		{
			fprintf(stderr, "L%u: invalid instruction format\n", line_number);
			fclose(file);
			return (EXIT_FAILURE);
		}
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(instructions[i].opcode, opcode) == 0)
			{
				execute(&stack, &instructions[i], line_number);
				break;
			}
			i++;
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	exit(EXIT_SUCCESS);
}
