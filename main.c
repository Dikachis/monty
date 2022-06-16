#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fd;
	size_t size = 0;

	if (argc != 2)
		h_error("USAGE: monty file\n", NULL);

	fd = fopen(argv[1], "r") ? fopen(argv[1], "r") :
		h_error("Error: Can't open file %s\n", argv[1]);

	while (getline(&var.bufline, &size, fd) != EOF)
	{
		var.line_number++;
		run_cmd(var.bufline);
	}
	return (EXIT_SUCCESS);
}
