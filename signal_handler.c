#include "lists.h"


/**
 * _signal_handler - Handles the SIGINT signal (Ctrl+C) by printing a new line,
 * displaying the prompt, and flushing the standard output.
 * @signal: The signal number received.
 */

void _signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		_prompt();
		fflush(stdout);
	}
}
