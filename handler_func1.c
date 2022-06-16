#include "monty.h"
#include "lists.h"

/**
 * push_handler - handles the push instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, i;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_handler - handles the pall instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}
