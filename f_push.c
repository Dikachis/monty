#include "monty.h"

/**
 * f_push - pushes an element to the stack.
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	int i;

	if (global_var.words[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(global_var.buffer);
		free_loop(global_var.words);
		free_stack(*stack);
		fclose(global_var.fd);
		exit(EXIT_FAILURE);
	}

	for (i = 0; global_var.words[1][i] != '\0'; i++)
	{
		if (global_var.words[1][0] == '-' && i == 0)
		{
		}
		else if (isdigit(global_var.words[1][i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(global_var.buffer);
			free_loop(global_var.words);
			free_stack(*stack);
			fclose(global_var.fd);
			exit(EXIT_FAILURE);
		}
	}
	if (global_var.is_stack == 1)
		add_node_end(stack, atoi(global_var.words[1]));
	else
		add_node_head(stack, atoi(global_var.words[1]));
}
