#include "lists.h"

/**
 * print_environment - Prints all the environment variables.
 *
 * This function prints all the environment variables and their corresponding
 * values. It uses the `environ` variable, which is an array of strings
 * containing the environment.Each element in the array is a string of the form
 *
 * The function iterates through the `environ` array and print each environment
 * variable followed by a new line using the `printf` function from the
 * standard I/O library.
 *
 * Note: The `environ` variable is typically defined in the C standard library
 * header `stdlib.h`.
 * Ensure that this header is included in the source file using this function.
 */
void print_environment(void)
{
	/*char **environ;*/
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
