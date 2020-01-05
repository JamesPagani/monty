#include "monty.h"
/**
 * pall - Prints all values on the stack (top to bottom)
 * @stack: The stack itself
 * @line_number: Monty file's opcode line (used for error handling)
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
