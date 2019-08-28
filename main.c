#include "shell.h"
/**
 * main - mini shell
 * Return: Always 0.
 */
int main(void)
{
	char *line, *line2;
	pid_t pid;
	int e, cont = 0;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		cont ++;
		write(STDIN_FILENO, "$ ", 2);
		line = readc();
		line2 = _cpy(line2, line);
		if(line[0] == '\n')
			continue;
		line = comments(line);
		
		if (!_strcmp("env", line2))
		{
			_env();
			continue;
		}
		if (!_strcmp("exit", line2))
		{
			e = salir(line2, cont);
			if (e == -1)
			continue;
		}
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
		free(line);
	}
	return (0);
}
