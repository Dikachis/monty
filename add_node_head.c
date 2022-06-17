#include "monty.h"

/**
 * add_node_head - adds a new node at the beginning of a stack_t list
 * @head: head of list
 * @n: value of element
 * Return: Address of new element
 */
stack_t *add_node_head(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
	return (new_node);
}
