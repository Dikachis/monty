#include "monty.h"

/**
 * f_pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
