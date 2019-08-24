#include "shell.h"
/**
 * main - mini shell
 * Return: Always 0.
 */
int main(void)
{
	char *line, *line2, *l;
	pid_t pid;
	int i = 1;
	char *s = *environ;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		write(1, "$ ", 2);
		line = readc();
		line2 = _cpy(l, line);
		if (!_strcmp("env", line2))
		{
			for (; s; i++) {
				printf("%s\n", s);
				s = *(environ+i);
			}
			continue;
		}
		if (!_strcmp("exit", line2))
			break;
		pid = fork();
		if (!pid)
		{
			execute(line2);
			break;
		}
		else if (pid < 0)
		{
			perror("fork");
			exit(-1);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
