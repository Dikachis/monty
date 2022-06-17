#include "monty.h"
/**
*free_loop - function for free double pointer array of pointers
*@arr: double pointer array of pointers
*/
void free_loop(char **arr)
{
	int len;

	for (len = 0; arr[len]; len++)
		free(arr[len]);
	free(arr);
}
