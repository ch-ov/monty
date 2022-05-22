#include "monty.h"
/**
 * push - Pushes an element to the stack
 * @stack: Head list.
 * @count: Count line.
 * @n: Integer
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
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Head list.
 * @count: Count line.
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
/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Head list
 * @count: Count line
 */
void pint(stack_t **stack, unsigned int count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);

}
/**
 * pop - Removes the top element of the stack
 * @stack: Head list
 * @count: Count line
 */
void pop(stack_t **stack, unsigned int count)
{
	stack_t *h = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}

	if (h)
	{
		*stack = (h)->next;
		free(h);
	}
}
/**
 * swap - Swaps the top two elements of the stack
 * @stack: Head list
 * @count: Count list
 */
void swap(stack_t **stack, unsigned int count)
{
	stack_t *h = *stack, *ptr;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	if (h && h->next)
	{
		ptr = h->next;
		if (ptr->next)
			ptr->next->prev = h;
		h->next = ptr->next;
		ptr->prev = NULL;
		ptr->next = h;
		h->prev = ptr;
		*stack = ptr;
	}
}
