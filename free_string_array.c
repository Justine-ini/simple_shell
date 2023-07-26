#include "lists.h"

/**
 * free_string_array - Frees a dynamically allocated string array.
 * @array: The string array to be freed.
 */

void free_string_array(char **array)
{
	int i;

	if (array == NULL)
		return;

	for (i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
}
