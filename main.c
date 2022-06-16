#include "monty.h"
global_t global;

/* /\** */
/*  * global_var - handle function for monty languege */
/*  * @void: num of inputs int */
/*  * Return: None */
/*  *\/ */
/* void global_var(void) */
/* { */
/*  global.num = NULL; */
/*  global.headstack = NULL; */
/*  global.line_number = 0; */
/*     global.linecount = 1; */
/*  global.gbuff = NULL; */

/* } */

/**
 * main - handle function for monty languege
 * @argc: num of inputs int
 * @argv: code files char
 * Return: None
 */
int main(int argc, char **argv)
{
	stack_t *headstack = NULL;

	global.headstack = &headstack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		error_fun(&headstack);
		exit(EXIT_FAILURE);
	}

	openfile(argv[1]);
	return (0);
}
