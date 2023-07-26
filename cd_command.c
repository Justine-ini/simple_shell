#include "lists.h"

/**
 * cd_command - Change the current working directory.
 * @directory: The directory to change to. If NULL, change to $HOME.
 *
 * Return: 0 on success, -1 on failure.
 */
int cd_command(char *directory)
{
	char *new_dir;
	char *current_dir;
	int result;

	if (directory == NULL || strcmp(directory, "~") == 0)
	{
		new_dir = getenv("HOME");
	}
	else if (strcmp(directory, "-") == 0)
	{
		new_dir = getenv("OLDPWD");
		if (new_dir == NULL)
		{
			printf("bash: cd: OLDPWD not set\n");
			return (-1);
		}
	}
	else
		new_dir = directory;
	current_dir = getcwd(NULL, 0);
	if (current_dir == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	result = chdir(new_dir);
	if (result == -1)
	{
		perror("chdir");
		free(current_dir);
		return (-1);
	}
	setenv("OLDPWD", current_dir, 1);
	setenv("PWD", new_dir, 1);
	free(current_dir);
	return (0);
}
