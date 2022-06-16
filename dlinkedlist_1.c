#include "lists.h"

/**
 * dlistint_len - returns the number of elements
 *                  in a doubly linked list
 * @h: head pointer to the list
 *
 * Return: number of elements
 */
size_t dlistint_len(const stack_t *h)
{
	size_t i = 0;

	while (h)
	{
		i++;
		h = h->next;
	}

	return (i);
}

/**
 * add_dnodeint - adds a new node at the
 *          beginning of a doubly linked list
 * @head: head double pointer to the list
 * @n: int data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = n;

	if (!(*head))
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
		return (new);
	}

	new->next = *head;
	new->prev = NULL;
	(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end
 *                  of a doubly linked list
 * @head: head double pointer to the list
 * @n: int data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *last = *head;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (!(*head))
	{
		*head = new;
		new->prev = NULL;
		return (new);
	}

	while (last->next)
		last = last->next;

	last->next = new;
	new->prev = last;

	return (new);
}

/**
 * free_dlistint - frees a doubly linked list
 * @head: head pointer to the list
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
