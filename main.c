#define _POSIX_C_SOURCE 200809L
#include "monty.h"
global_t global_var = {NULL, NULL, NULL, 1};

/**
 * main - Monty byte code interpreter
 * @ac: argument count
 * @av: argument arr
 * Return: 0 on success, 1 on Error
 **/
int main(int ac, char *av[])
{
	size_t state_buffer;
	int flag_EOF = 1;
	int count_words = 0;
	stack_t *head = NULL;
	int count_lines = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global_var.fd = fopen(av[1], "r");
	if (!global_var.fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		flag_EOF = getline(&global_var.buffer, &state_buffer, global_var.fd);
		if (flag_EOF == -1)
			break;
		count_words = countwords(global_var.buffer);
		count_lines++;
		global_var.words = split_line(global_var.buffer, count_words, &head);
		if (global_var.words[0] != NULL)
		{
			get_func(&head, count_lines);
			free_loop(global_var.words);
		}
		else
			free(global_var.words);
	}
	free(global_var.buffer);
	free_stack(head);
	fclose(global_var.fd);
	return (0);
}
