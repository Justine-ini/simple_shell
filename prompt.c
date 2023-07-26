#include "lists.h"

/**
 * _prompt - Displays a prompt to the user.
 *
 * This function prints a prompt (e.g., "$ ") to the standard output (stdout)
 * to indicate that the program is ready to receive input from the user.
 *
 * Return: No return value.
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}
