#include "monty.h"
/**
 * get_func - opcode
 * @op: output
 * Return: Nothing.
 */
void get_func(char *op)
{
	instruction_t fun[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{NULL, NULL}

	};

	int i;

	if (op[0] == '#')
	{
		return;
	}
	for (i = 0; fun[i].opcode; i++)
	{
		if ((strcmp(fun[i].opcode, op) == 0))
		{
			fun[i].f(global.headstack, global.line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", global.line_number, op);
	exit(EXIT_FAILURE);
}
