#include "monty.h"

/**
 * opcode_add - add
 * @stack: input
 * @line_number: input
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_nop - nop
 * @stack: input
 * @line_number: input
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * opcode_sub - sub
 * @stack: input
 * @line_number: input
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_div - div
 * @stack: input
 * @line_number: input
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_mul - mul
 * @stack: input
 * @line_number: input
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	opcode_pop(stack, line_number);
}
