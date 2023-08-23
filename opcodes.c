#include "monty.h"

/**
 * opcode_push - push
 * @stack: input
 * @line_number: input
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
	{
		free(n_node);
		fprintf(stderr, "L%d: stack is null\n", line_number);
		exit(EXIT_FAILURE);
	}
	n_node->n = line_number;
	n_node->prev = NULL;
	n_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = n_node;
	*stack = n_node;
}

/**
 * opcode_pall - pall
 * @stack: input
 * @line_number: input
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * opcode_pint - pint
 * @stack: input
 * @line_number: input
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * opcode_swap - swap
 * @stack: input
 * @line_number: input
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * opcode_pop - pop
 * @stack: input
 * @line_number: input
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
