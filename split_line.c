#include "monty.h"
/**
*split_line - creates a double pointer array that holders pointers
*to each string from the command line
*@line: buffer that stores the stdin input
*@len: len of words to create
*@stack: head of linked list (stack)
*Return: double pointer array of pointers that are commands to interpret
*and execute
*/
char **split_line(char *line, size_t len, stack_t **stack)
{
	int j = 0;
	char *token;
	char **word_arr;

	word_arr = malloc(sizeof(char *) * (len + 1));
	if (word_arr == NULL)
		error_malloc(stack);

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		word_arr[j] = malloc(strlen(token) + 1);
		if (word_arr[j] == NULL)
		{
			free_loop(word_arr);
			error_malloc(stack);
		}
		strncpy(word_arr[j], token, strlen(token) + 1);
		token = strtok(NULL, TOK_DELIM);
		j++;
	}
	word_arr[j] = NULL;
	return (word_arr);
}
