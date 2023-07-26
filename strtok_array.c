#include "lists.h"

/**
 * strtok_array - Splits a string into an array of words using delimiters
 * @new_line: The string to be split
 * @delimiters: The delimiters used for splitting
 *
 * Return: An array of strings containing the words, or NULL on failure
 */


char **strtok_array(char *new_line, char *delimiters)
{
	char *str_copy, *token, **words;
	int i = 0, j, num_words = 0;

	if (new_line == NULL || delimiters == NULL)
		return (NULL);
	str_copy = strdup(new_line);
	if (str_copy == NULL)
		return (NULL);
	token = _strtok(str_copy, delimiters);
	if (token == NULL)
	{
		free(str_copy);
		return (NULL);
	}
	for (; token != NULL; num_words++)
		token = _strtok(NULL, delimiters);
	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
	{
		free(str_copy);
		return (NULL);
	}
	token = _strtok(new_line, delimiters);
	while (token != NULL)
	{
		words[i] = strdup(token);
		if (words[i] == NULL)
		{
			for (j = i - 1; j >= 0; j--)
				free(words[j]);
			free(words);
			free(str_copy);
			return (NULL);
		}
		i++;
		token = _strtok(NULL, delimiters);
	}
	words[i] = NULL;
	free(str_copy);
	return (words);
}
