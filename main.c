#include "monty.h"
/**
 * main - Entry Point. Reads the file and sends it to the parser
 * @argc: Amount of arguments recieved
 * @argv: Argument vector/array
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	FILE *monty_f;
	stack_t *stack = NULL;
	char *buff = NULL;
	size_t buff_size = 0;
	int line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_f = fopen(argv[1], "r");
	if (monty_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (line = 1; getline(&buff, &buff_size, monty_f) != -1; line++)
	{
		
	}

	return (0);
}

/**
 * parser - Parses the line into an opcode and executes it
 * @line: Line's content
 * @stack: The stack itself
 * @line_number: Monty file's current line
 * Return: Nothing
 */
void parser(char *line, char **stack, unsigned int line_number)
{
	instruction_t execute[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	
}
