#include "lists.h"
/**
 * main - Entry point of the program.
 *
 * This function is the entry point of the program and serves as the main loop
 * for tokenizing user input. It reads a line of input from the user, tokenizes
 * it into separate words using the specified delimiters, and then prints each
 * word along with its position (index) in the line.
 *
 * Return: Always 0.
 */

int main(void)
{
	char **string, *new_line, *path;
	int i, status;

	signal(SIGINT, _signal_handler);
	while (1)
	{
		_prompt();
		new_line = _getline();
		if (new_line == NULL)
			break;
		string = strtok_array(new_line, " \n");
		if (string == NULL)
		{
			free(new_line);
			continue;
		}
		exit_shell(string, new_line);
		if (strcmp(string[0], "env") == 0)
		{
			print_environment();
			free(new_line);
			free_string_array(string);
			continue;
		}
		if (strcmp(string[0], "cd") == 0)
		{
			if (string[1] == NULL)
				cd_command(NULL);
			else
				cd_command(string[1]);
		}
		path = _which(string[0]);
		status = _execute(path, string);
		free(new_line);
		for (i = 0; string[i] != NULL; i++)
			free(string[i]);
		free(string);
		free(path);
	}
	return (status);
}
