#include "shell.h"
/**
 * main - mini shell
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	char *line, *aux;
	char **com;
	int s, e, cont = 0;
	pid_t pid;
Here:
	signal(SIGINT, sigintHandler);
	while (1)
	{
		cont ++;
		write(STDIN_FILENO, "Simple_shell$ ", 14);
		line = readc();
		line = comments(line);
		com = split_command(line);
		if (com[0] == NULL)
			goto Here;
		if (!_strcmp("exit", com[0]))
		{
			if (com[1] == NULL)
			{
				free(line);
				free(com);
				exit(0);
			}
			e = _atoi(com[1]);
			if (e >= 0 && e + 1 > 0)
			{
				free(line);
				free(com);
				exit(e);
			}
			else
			{
				errors(cont, com[0], com[1]);
				goto Here;
			}
		}
	        s = execute_command(com, line, cont);
		free(line);
		free(com);
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
	write(1, "\nSimple_shell$ ", 14);
	fflush(stdout);
}
