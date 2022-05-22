#include "monty.h"
/**
 * add - Adds the top two elements of the stack.
 * @stack: Head list.
 * @count: Count of line.
 */
void add(stack_t **stack, unsigned int count)
{
	stack_t *h = *stack, *n;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		n = h->next;
		n->n += h->n;
		free(h);
		*stack = n;
	}
}
