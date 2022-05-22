#include "monty.h"
/**
 * exeOpcode - Executes opcode
 * @string: argv
 * @stack: Pointer to head
 * Return: void
 */
void exeOpcode(char *string[], stack_t *stack)
{
	int line = 1, x = 0, y = 0;

	instruction_t names[] = {
		{"pall", pall},
		{"null", NULL}
	};

	while (string[x + 1])
	{
		if (_strcmp("push", string[x]) != 0)
			push(&stack, line, pushInt(string[x], line));
		else if (_strcmp("nop", string[x]))
			;
		else
		{
			while (!_strcmp(names[y].opcode, "null"))
			{
				if (_strcmp(names[y].opcode, string[x]))
				{
					names[y].f(&stack, line);
					break;
				}
				y++;
			}
			if (_strcmp(names[y].opcode, "null") && !_strcmp(string[x], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", line, string[x]);
				if (!findNewLine(string[x]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
		 x++, line++;
	}
	freeStack(stack);
}
/**
 * pushInt - Int for push opcode
 * @content: Content of the file
 * @line: Number of line
 * Return: int
 */
int pushInt(char *content, int line)
{
	char *opcode = "push";

	while (*content != '\0')
	{
		if (*opcode == *content)
		{
			opcode++;
			content++;
			if (*opcode == '\0')
				while (*content)
				{
					if ((*content >= '0' && *content <= '9') || *content == '-')
					{
						checkNumber(content, line);
						return (atoi(content));
					}
					else if (*content == ' ')
						content++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", line);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			content++;
	}
	return (0);
}
/**
 * checkNumber - Find number
 * @content: content
 * @line: Number of line
 * Return: int
 */
int checkNumber(char *content, int line)
{
	int x = 1;

	while (content[x])
	{
		if (content[x] == '\0' || content[x] == '\n')
			break;
		if ((content[x] >= '0' && content[x] <= '9') || content[x] == ' ')
			x++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
/**
 * findNewLine - Find new line
 * @content: content
 * Return: int
 */
int findNewLine(char *content)
{
	char *opcode = "\n";

	while (*content != '\0')
	{
		if (*opcode == *content)
		{
			opcode++;
			content++;
			if (*opcode == '\0')
				return (1);
		}
		else
			content++;
	}
	return (0);
}
