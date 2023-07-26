#include "lists.h"

/**
 * _getline - Reads a line of input from stdin and returns it as a string.
 *
 * This function uses the `getline` function to read a line of input from
 * the standard input (stdin).
 * It allocates memory for the line dynamically, and the caller is
 * responsible for freeing this memory.
 *
 * Return: On success, the function returns a pointer to the read line.
 * If an error occurs
 * or the end-of-file (EOF) is reached, the function returns NULL.
 */

char *_getline(void)
{
	size_t bufsize = 0;
	char *line = NULL;
	ssize_t character_read;

	character_read = getline(&line, &bufsize, stdin);
	if (character_read == -1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		free(line);
		return (NULL);
	}
	if (line[character_read - 1] == '\n')
	{
		line[character_read - 1] = '\0';
	}
	return (line);
}
