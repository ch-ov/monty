#include "monty.h"
/**
 * freeStack - Free linked list
 * @head: Pointer to list
 * Return: void
 */
void freeStack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
/**
 * freeContent - Frees content
 * @ptr: Pointer to array
 * Return: void
 */
void freeContent(char *ptr[])
{
	int i = 0;

	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
}
