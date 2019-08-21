#include "shell.h"
/**
 * main - mini shell
 * Return: Always 0.
 */
int main(void)
{
	char *line, *line2, *l;
	pid_t pid;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		write(1, "$ ", 2);
		line = readc();
		line2 = _cpy(l, line);
		if (!_strcmp("exit", line2))
			break;
		pid = fork();
		if (!pid)
		{
			execute(line2);
			break;
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
/**
 * sigintHandler -  Signal Handler for SIGINT
 * When Ctrl+C is pressed, SIGINT signal is generated,
 * we can catch this signal and run our defined signal handler.
 * @sig_num: Reset handler to catch SIGINT next time.
 * Return: 0
 */
void sigintHandler(int sig_num)
{
	signal(SIGINT, sigintHandler);
	write(1, "\n$ ", 2);
	fflush(stdout);
}
