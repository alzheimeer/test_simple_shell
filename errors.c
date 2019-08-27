#include "shell.h"

void errors(int cont, char *var, char *com)
{
	char *s = "hsh: ", *con, *a = "not found\n", *num;
	char *aux = ": ";
	char st[300];
	int i, flag = 0;

	if (!_strcmp("exit", var))
	{
		a = "Illegal number: ";
		num = com;
	}

	con = _itoa(cont);
	strcat(con, aux);
	strcat(var, aux);
	strcat(st, s);
	strcat(st, con);
	strcat(st, var);
	strcat(st, a);
	strcat(st, num);
	strcat(st, "\n");
	for (i = 0; st[i] != '\0'; i++)
		;
	free(con);
	write(STDIN_FILENO, st, i);
}
