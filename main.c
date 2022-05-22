#include "monty.h"
/**
 * main - Entry Point
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: int
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	size_t bufsize = 1024;
	FILE *opcode;
	static char *string[1024] = {0};
	int n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opcode = fopen(argv[1], "r");
	if (opcode == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&(string[n]), &bufsize, opcode) > 0)
	{
		;
		n++;
	}
	exeOpcode(string, stack);
	freeContent(string);
	fclose(opcode);
	return (0);
}
