#include "shell.h"
/**
 * main - mini shell
 * Return: Always 0.
 */
int main(){
	char *line, *line2, *l;
	pid_t pid;

	while (1)
	{
		write(1, "$ ", 2);
		line = readc();
		line2 = _cpy(l,line);
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
	return 0;
}
