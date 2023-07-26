#include "lists.h"

/**
 * search_path - Search for a command in a specific directory.
 * @command: The command to search for.
 * @directory: The directory to search in.
 *
 * Return: If the command is found and executable, returns the full path.
 *         Otherwise, returns NULL.
 */

char *search_path(char *command, char *directory)
{
	size_t len_cmd = strlen(command);
	size_t len_dir = strlen(directory);
	size_t len_total = len_dir + 1 + len_cmd + 1;
	char *full_path = (char *)malloc(len_total);

	if (full_path == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	snprintf(full_path, len_total, "%s/%s", directory, command);

	if (access(full_path, X_OK) == 0)
	{
		return (full_path);
	}

	free(full_path);
	return (NULL);
}
