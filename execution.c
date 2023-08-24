#include "monty.h"

/**
 * execute - execute instruction
 * @stack: input
 * @instruction: input
 * @line_number: input
 */

void execute(stack_t **stack, instruction_t *instruction,
		unsigned int line_number)
{
	if (strcmp(instruction->opcode, "push") == 0)
		opcode_push(stack, line_number);
	else if (strcmp(instruction->opcode, "pall") == 0)
		opcode_pall(stack, line_number);
	else if (strcmp(instruction->opcode, "pint") == 0)
		opcode_pint(stack, line_number);
	else if (strcmp(instruction->opcode, "pop") == 0)
		opcode_pop(stack, line_number);
	else if (strcmp(instruction->opcode, "swap") == 0)
		opcode_swap(stack, line_number);
	else if (strcmp(instruction->opcode, "add") == 0)
		opcode_add(stack, line_number);
	else if (strcmp(instruction->opcode, "nop") == 0)
		opcode_nop(stack, line_number);
	else if (strcmp(instruction->opcode, "sub") == 0)
		opcode_sub(stack, line_number);
	else if (strcmp(instruction->opcode, "div") == 0)
		opcode_div(stack, line_number);
	else if (strcmp(instruction->opcode, "mul") == 0)
		opcode_mul(stack, line_number);
	else if (strcmp(instruction->opcode, "mod") == 0)
		opcode_mod(stack, line_number);
	else if (strcmp(instruction->opcode, "#") == 0)
	{
		/* Comment line, don't do anything */
	}
}
