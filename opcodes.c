#include "monty.h"

/**
 * opcode_push - push
 * @stack: input
 * @line_number: input
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{

}

/**
 * opcode_pall - pall
 * @stack: input
 * @line_number: input
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{

}

void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
