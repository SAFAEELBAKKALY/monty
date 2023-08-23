#include "monty.h"

/**
 * opcodes_instruction - get opcodes instruction
 * @l: input
 * @line_number: input
 * @stack: input
 * Return: instruction
 */
void (*opcodes_instruction(char *l, unsigned int line_number))(
		stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"swap", opcode_swap},
		{"pop", opcode_pop},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"", NULL}
	};
	int i = 0;
	char *cmd, *_ptr;
	long int nm;

	cmd = strtok(l, " \n");
	if (cmd == NULL)
		return (NULL);
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(cmd, instructions[i].opcode) == 0)
		{
			if (strcmp(cmd, "push") == 0)
			{
				cmd = strtok(NULL, " \n");
				if (cmd == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				nm = strtol(cmd, &_ptr, 10);
				if (*_ptr != '\0')
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				if (nm > INT_MAX || nm < INT_MIN)
				{
					fprintf(stderr, "L%d: integer out of range\n", line_number);
					exit(EXIT_FAILURE);
				}
				/*n = (int)nm;*/
			}
			return (instructions[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}
