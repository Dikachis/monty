#include "lists.h"

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list
 * @head: head pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head)
	{
		if (index == i)
			return (head);
		head = head->next;
		i++;
	}

	return (NULL);
}

/**
 * sum_dlistint - returns the sum of all the data
 *                of a doubly linked list
 * @head: head pointer to the list
 *
 * Return: sum of the nodes or 0 on empty
 */
int sum_dlistint(stack_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 *                        in a doubly linked list
 * @h: head double pointer to the list
 * @idx: index of the node to insert
 * @n: int  to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp_prev, *temp = *h;
	unsigned int i = 0;

	if (!new)
		return (NULL);

	new->n = n;

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (temp)
	{
		if (idx == i)
		{
			temp->prev->next = new;
			new->prev = temp->prev;
			new->next = temp;
			temp->prev = new;
			return (new);
		}
		temp_prev = temp;
		temp = temp->next;
		i++;
	}
	if (!temp && i == idx)
	{
		temp_prev->next = new;
		new->prev = temp_prev;
		return (new);
	}

	free(new);
	return (NULL);
}

/**
 * delete_dnodeint_at_index - deletes a node in a doubly linked list
 *                    at a given index
 * @head: head double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp = *head;
	unsigned int i = 0;

	if (!(*head))
		return (-1);

	while (temp && i != index)
	{
		i++;
		temp = temp->next;
	}

	if (!temp)
		return (-1);
	else if (temp == *head)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
	}
	else if (temp->next == NULL)
	{
		temp->prev->next = NULL;
		free(temp);
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}

	return (1);
}
