#include "monty.h"

void h_error(char *message, char *variable)
{
    dprintf(STDERR_FILENO, message, variable);
    exit(EXIT_FAILURE);
}
