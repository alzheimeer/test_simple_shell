#include "shell.h"

int main(){
	char dig[100];
	pid_t pid;

	while (1)
	{
		printf("$ ");
		scanf(" %99[\n]", dig);
		if (!strcmp("exit", dig))
			break;
		pid = fork();
		if (!pid)
		{
			execute(dig);
			break;
		}
		else
		{
			wait(NULL);
		}
	}
	return 0;

}
