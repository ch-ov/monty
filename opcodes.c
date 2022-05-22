#include "monty.h"
/**
 * push - pushes an element to the stack
 *
 * @stack: head list.
 * @count: count line.
 * @n: Integer
 *
 * Return: address of new element
 */

void push(stack_t **stack, unsigned int count, int n)
{
	stack_t *new, *h = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", count);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->prev = NULL;
	new->n = n;
	new->next = *stack;
	if (*stack)
		h->prev = new;
	*stack = new;
}
/**
 * pall - prints all the values on the stack, starting from the top.
 * @stack: head list.
 * @count: count line.
 *
 * Return: Void
 */

void pall(stack_t **stack, unsigned int count)
{
	stack_t *h = *stack;
	(void)count;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
