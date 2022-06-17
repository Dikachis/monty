#include "monty.h"
/**
 * print_number - Save in buffer numbers to be printed
 * @n: number to be printed
 * Return: new position of the buffer
 */
void print_number(size_t n)
{
	ssize_t i, j, z = 1;
	size_t n1;
	char c;

	n1 = n;
	for (i = 0; n / 10 != 0; i++)
		n = n / 10;

	for (j = 0; j <= i - 1; j++)
		z = z * 10;

	for (; z != 0;)
	{
		c = (n1 / z) + '0';
		write(STDERR_FILENO, &c, 1);
		n1 = n1 % z;
		z = z / 10;
	}
}
