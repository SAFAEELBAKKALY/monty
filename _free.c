#include "monty.h"

/**
 * _free - free tascks
 * @stack: input
 */

void _free(stack_t **stack)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
