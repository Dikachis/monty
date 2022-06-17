#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define TOK_DELIM " \t\r\n\v\a"

/**
 * struct global - store neccesary variables
 * @words: array with the words of the instruction
 * @buffer: current line processed
 * @fd: file to process
 * @is_stack: flag for queue or stack
 *
 * Description: store neccesary variables
 */
typedef struct global
{
	char **words;
	char *buffer;
	FILE *fd;
	int is_stack;
} global_t;

extern global_t global_var;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

size_t countwords(char *in);
char **split_line(char *line, size_t len, stack_t **stack);
void get_func(stack_t **stack, unsigned int line_number);
void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void f_swap(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void f_sub(stack_t **stack, unsigned int line_number);
void f_div(stack_t **stack, unsigned int line_number);
void f_mul(stack_t **stack, unsigned int line_number);
void f_mod(stack_t **stack, unsigned int line_number);
void f_pchar(stack_t **stack, unsigned int line_number);
void f_pstr(stack_t **stack, unsigned int line_number);
void f_rotl(stack_t **stack, unsigned int line_number);
void f_rotr(stack_t **stack, unsigned int line_number);
void f_stack(stack_t **stack, unsigned int line_number);
void print_number(size_t n);
void print_arr(char **arr);
void free_loop(char **arr);
void error_malloc(stack_t **stack);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node_head(stack_t **head, const int n);
void free_stack(stack_t *head);
instruction_t definition(int i);

#endif
