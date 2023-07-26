#include "lists.h"

/**
 * exit_shell - Exits the shell based on the provided command and exit status.
 * @string: An array of strings representing the user's input and arguments.
 * @new_line: A pointer to a dynamically allocated buffer for user input.
 */
void exit_shell(char **string, char *new_line)
{
	if (strcmp(string[0], "exit") == 0)
	{
		int exit_status = 0;

		if (string[1] != NULL)
		{
			exit_status = _atoi(string[1]);
		}

		free(new_line);
		free_string_array(string);

		exit(exit_status);
	}
}
