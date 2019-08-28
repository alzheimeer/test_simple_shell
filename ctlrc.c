#include "shell.h"
/**
 * sigintHandler -  Signal Handler for SIGINT
 * When Ctrl+C is pressed, SIGINT signal is generated,
 * we can catch this signal and run our defined signal handler.
 * @sig_num: Reset handler to catch SIGINT next time.
 * Return: 0
 */
void sigintHandler()
{
	signal(SIGINT, sigintHandler);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
