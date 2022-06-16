#include "monty.h"

/**
 * * error_fun - exit and free stack
 * @headstack: head stack pointer
 *
 */
void error_fun(stack_t **headstack)
{
	if (*headstack)
		free_list(*headstack);
	exit(EXIT_FAILURE);
}
/**
 * free_list - free memory of the linked list
 * @head: first node of linked list
 *
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * openfile - read fun
 * @namefile: output
 * Return: Nothing.
 */
void openfile(char *namefile)
{
	char *buff = NULL;
	char *ptr = NULL;
	unsigned int line_number = 0;
	size_t buff_long;
	FILE *file = fopen(namefile, "r");

	if (!file)
	{
		dprintf(2, "Error: Can't open file %s\n", namefile);
		exit(EXIT_FAILURE);
	}
	else
	{
		global.file = file;
		while ((getline(&buff, &buff_long, file)) != -1)
		{
			line_number++;
			global.line_number = line_number;
			ptr = strtok(buff, DELIM);
			global.num = strtok(NULL, DELIM);
			get_func(ptr);
		}
		free(buff);
		fclose(file);
		exit(EXIT_SUCCESS);
	}
}
