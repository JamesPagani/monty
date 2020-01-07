#include "monty.h"
/**
 * push - Adds a new element to the top of the stack
 * @stack: The stack itself
 * @line_number: Monty file's line number (used for error handling)
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *strint;
	stack_t *new;

	strint = malloc(12 * sizeof(char));
	new = malloc(sizeof(stack_t));
	if (strint == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strint = strtok(NULL, " ");
	new->n = atoi(strint);
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}

