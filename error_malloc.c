#include "monty.h"

/**
 * error_malloc - print error in stderr
 *@stack: head of linked list (stack)
 */
void error_malloc(stack_t **stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	free(global_var.buffer);
	free_stack(*stack);
	fclose(global_var.fd);
	exit(EXIT_FAILURE);
}
