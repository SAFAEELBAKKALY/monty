#include "monty.h"

/**
 * opcode_push - push
 * @stack: input
 * @line_number: input
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	int value = 0;
	stack_t *n_node;

	if (!argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n_node-> = value;
	n_node->prev = NULL;
	n_node->next = *stack;
	if(*stack)
	{
		(*stack)->prev = n_node;
	}
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
	
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
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
