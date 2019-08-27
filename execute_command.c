#include "shell.h"

int execute_command(char **args, char *p, int cont)
{
	pid_t pid, wpid;
	int status, i = 0, j;
	char us[128] = "/bin";
	char *aux = "/b";

	if(p[0] == aux[0] && p[1] == aux[1])
	{
		strcpy(us, p);
	}
	else if (p[0] == aux[0] && p[1] != aux[1])
	{
		strcat(us, p);
	}
	else
	{
		strcat(us, "/");
		strcat(us, p);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(us, args, NULL) == -1)
		{
			errors(cont, p, NULL);
			return(0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		errors(cont, p, NULL);
		return (0);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return(1);
}
