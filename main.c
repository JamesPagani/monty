#include "monty.h"
/**
 * op_scan - Detects which instruction to use according to the opcode
 * @op_tkn: Token which may represent a Monty opcode
 * Return: Pointer to a function if a valid instruction was found
 * or NULL if nothing was found.
 */
void (*op_scan(char *op_tkn))(stack_t **stack, unsigned int line_number)
{
	instruction_t instrucs[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;
	while (instrucs[i].opcode != NULL)
	{
		if (strcmp(instrucs[i].opcode, op_tkn) == 0)
		{
			return (instrucs[i].f);
		}
		i++;
	}
	return (NULL);
}

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
	char *delims = " \n";
	size_t buff_size = 0;
	int line;
	char *buff = NULL;
	void (*op_func)(stack_t **stack, unsigned int line_number);

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
		op_func = op_scan(strtok(buff, delims));
		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, buff);
			free(buff);
			fclose(monty_f);
			exit(EXIT_FAILURE);
		}
		op_func(&stack, line);
	}
	free(buff);
	fclose(monty_f);
	return (EXIT_SUCCESS);
}
