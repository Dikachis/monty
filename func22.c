#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int count = 0, tmpn;

	while (tmp)
		tmp = tmp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	tmpn = (*stack)->n;
	delete_node_index(stack, 0);
	(*stack)->n += tmpn;

}
/**
 * _nop - doesn’t do anything
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * _sub -  subtracts the top element of the stack from the second
 * top element of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int count = 0, tmpn;

	while (tmp)
		tmp = tmp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	tmpn = (*stack)->n;
	delete_node_index(stack, 0);
	(*stack)->n -= tmpn;

}
/**
 * _div - divides the second top element of the stack by the top
 * element of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int count = 0, tmpn;

	while (tmp)
		tmp = tmp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	tmpn = (*stack)->n;
	delete_node_index(stack, 0);

	if (tmpn == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->n /= tmpn;

}
/**
 * _mul - multiplies the second top element of the stack with the top element
 * of the stack.
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int count = 0, tmpn;

	while (tmp)
		tmp = tmp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}
	tmpn = (*stack)->n;
	delete_node_index(stack, 0);
	(*stack)->n *= tmpn;
}
