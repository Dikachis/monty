#include "monty.h"

/**
 * _push - read fun
 * @stack: output
 * @line_number: num
 * Return: Nothing.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n;

	if ((_isnumber(global.num)) == 1)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(global.num);
	add_dnodeint(stack, n);
}
/**
 * _pall - read fun
 * @stack: output
 * @line_number: num
 * Return: Nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (stack && tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _pint - prints the value at the top of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack || !(*stack))
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
/**
 * _pop - removes the top element of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _pop(stack_t **stack, unsigned int line_number)
{

	if (!stack || !(*stack))
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	delete_node_index(stack, 0);

}
/**
 * _swap - swaps the top two elements of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *tmp2, *tmp3;
	int count = 0;

	while (tmp)
		tmp = tmp->next, count++;
	if (count < 2 || !stack || !(*stack) || !(*stack)->next)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	tmp = tmp3 = *stack;
	tmp2 = tmp->next;

	tmp->next = tmp2->next, tmp->prev = tmp2;
	tmp2->next = tmp3, tmp2->prev = tmp3->prev;

	*stack = tmp2;
}
