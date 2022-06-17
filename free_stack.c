#include "monty.h"

/**
 * free_stack - free a stack list.
 * @head: head of the list.
 */
void free_stack(stack_t *head)
{
	stack_t *position;

	while (head)
	{
		position = head;
		head = head->next;
		free(position);
	}
}
