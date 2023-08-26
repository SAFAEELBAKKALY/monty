#include "monty.h"

/**
 * opcode_mod - mod
 * @stack: input
 * @line_number: input
 */

void opcode_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	opcode_pop(stack, line_number);
}
/**
 * opcode_pchar - pchar
 * @stack: input
 * @line_number: input
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
/**
 * opcode_pstr - pstr
 * @stack: input
 * @line_number: input
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	while (curr != NULL && curr->n != 0 && curr->n >= 0 && curr->n <= 127)
	{
		putchar(curr->n);
		curr = curr->next;
	}
	putchar('\n');
}
