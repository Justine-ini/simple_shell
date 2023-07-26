#include "lists.h"
/**
 * _execute - Execute a command with its arguments in a new process.
 * @path: The path to the executable or command to be executed.
 * @string: An array of strings containing the command-line arguments.
 *
 * Return: On success, returns the exit status of the child process.
 * On failure, returns -1.
 */

int _execute(char *path, char **string)
{
	int status;
	int check;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork: ");
		return (-1);
	}
	if (pid == 0)
	{
		check = execve(path, string, __environ);
		if (check == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", string[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	free(path);
	return (0);
}
