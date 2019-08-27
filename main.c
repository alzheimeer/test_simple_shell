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
	char grillo;
	ssize_t bufsize = 0;
		
	signal(SIGINT, sigintHandler);
	while (1)
	{
//		((grillo = getline(&line, &bufsize, stdin)) != EOF)
		write(1, "$ ", 2);
		line = readc();
		line2 = _cpy(l, line);
		if (!_strcmp("env", line2))
		{
			for (; s; i++)
			{
				write(STDIN_FILENO, s, _strlen(s));
				write(STDIN_FILENO, "\n", 1);
				s = *(environ + i);
			}
			continue;
		}
		if (!_strcmp("exit", line2))
			break;
		pid = fork();
		free(line);
		line = NULL;
		bufsize = 0;
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
