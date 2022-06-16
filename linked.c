#include "monty.h"
/**
 *add_dnodeint - add a new node
 *@head: head of the current list
 *@n: value new node list
 *Return: address new element.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newnode;

	if (head == NULL)
		return (NULL);

	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
		return (NULL);

	newnode->n = n;

	if (*head == NULL)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
	}

	else
	{
		newnode->next = *head;
		newnode->prev = NULL;
		(*head)->prev = newnode;
	}
	*head = newnode;
	return (newnode);
}
/**
 *add_dnodeint_end - add new node at the end
 *@head: thead list
 *@n: value new node
 *Return: new node at the end
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *newnode;
	stack_t *endnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
	}

	else
	{
		endnode = *head;
		while (endnode->next != NULL)
			endnode = endnode->next;
		newnode->prev = endnode;
		endnode->next = newnode;
	}
	return (newnode);
}
/**
 * delete_node_index - deletes the node at index
 * @head: pointer to head of doubly linked list
 * @index: index to look for
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_node_index(stack_t **head, unsigned int index)
{
	stack_t *tmpcount = *head, *tmp1 = *head, *tmp2, *tmp3;
	unsigned int count = 0;

	if (!head || !(*head))
		return (-1);
	while (tmpcount)
		tmpcount = tmpcount->next, count++;
	if (index > (count - 1))
		return (-1);
	if (index == 0)
	{
		tmp1 = tmp1->next;
		free(*head);
		*head = tmp1;
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}
	for (count = 0; count < index; count++)
		tmp2 = tmp1, tmp1 = tmp1->next;

	tmp2->next = tmp1->next;
	tmp3 = tmp1->next;
	if (tmp3)
		tmp3->prev = tmp2;
	free(tmp1);
	return (1);
}
/**
 * free_stack_t - function that frees a stack_t list.
 * @head: head of doubly linked list
 *
 * Return: No return
 */
void free_stack_t(stack_t **head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
/**
 * _isnumber - checks if a string is composed of numbers
 * @s: string
 *
 * Return: 1 if string has only numbers, 0 if not
 */
int _isnumber(char *s)
{
	int i;

	if (!s)
		return (1);

	if (*s == '-')
		s++;

	for (i = 0; s[i]; i++)
		if (s[i] < 48 || s[i] > 57)
			return (1);
	return (0);
}
