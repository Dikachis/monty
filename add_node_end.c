#include "monty.h"

/**
 * add_node_end - adds a new node at the end of a stack_t list.
 * @head: head of the list.
 * @n: value to store.
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *position;
	stack_t *new_node;

	if (head == NULL)
		return (NULL);
	position = *head;
	if (position)
	{
		while (position->next != NULL)
			position = position->next;
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(global_var.buffer);
		free_loop(global_var.words);
		free_stack(*head);
		fclose(global_var.fd);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = position;
	new_node->next = NULL;
	if (position)
		position->next = new_node;
	else
		*head = new_node;
	return (new_node);
}
