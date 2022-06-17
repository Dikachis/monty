#include "monty.h"

/**
 * get_func - selects the correct function to perform
 * @stack: linked list
 * @line_number: counter lines
 */
void get_func(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	int len = 19;
	instruction_t monty_functions[19];

	for (i = 0; i < len; i++)
		monty_functions[i] = definition(i);

	if (strcmp(global_var.words[0], "nop") == 0 || global_var.words[0][0] == '#')
		return;

	for (i = 0; monty_functions[i].opcode != NULL; i++)
	{
		if (strcmp(monty_functions[i].opcode, global_var.words[0]) == 0)
		{
			monty_functions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n",
		line_number, global_var.words[0]);
	free(global_var.buffer);
	free_stack(*stack);
	fclose(global_var.fd);
	free_loop(global_var.words);
	exit(EXIT_FAILURE);
}

/**
 * definition - return definitions
 * @i: index
 * Return: definition
 */
instruction_t definition(int i)
{
	instruction_t monty_functions[] = {
	    {"push", f_push},
	    {"pall", f_pall},
	    {"pint", f_pint},
	    {"pop", f_pop},
	    {"pop", f_pop},
	    {"swap", f_swap},
	    {"add", f_add},
	    {"sub", f_sub},
	    {"div", f_div},
	    {"mul", f_mul},
	    {"mod", f_mod},
	    {"pchar", f_pchar},
	    {"pchar", f_pchar},
	    {"pstr", f_pstr},
	    {"rotl", f_rotl},
	    {"rotr", f_rotr},
	    {"stack", f_stack},
	    {"queue", f_stack},
	    {NULL, NULL}};

	return (monty_functions[i]);
}
