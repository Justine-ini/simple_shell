#include "lists.h"
/**
 * _which - Searches for the full path of a command in the
 * directories listed in the PATH environment variable
 * @command: The command to search for
 *
 * Return: The full path of the command if found, otherwise NULL
 */

char *_which(char *command)
{
	char *path_env;
	char *path;
	char *token;
	char *full_path;

	if (command == NULL)
		return (NULL);

	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path = strdup(path_env);
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	while (token != NULL)
	{
		full_path = search_path(command, token);
		if (full_path != NULL)
		{
			free(path);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
