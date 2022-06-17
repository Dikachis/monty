#include "monty.h"

/**
 * print_arr - print a linked list
 * @arr: head
 */
void print_arr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
