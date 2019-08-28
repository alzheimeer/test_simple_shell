#include "shell.h"

void errors(int cont, char *var, char *com)
{
	char *s = "hsh: ", *con, *a = "not found\n", *num;
	char *aux = ": ";
	char st[300];
	int i;

	if (!_strcmp("exit", var))
	{
		a = "Illegal number: ";
		num = com;
	}

	con = _itoa(cont);
	_strcat(con, aux);
	_strcat(var, aux);
	_strcat(st, s);
	_strcat(st, con);
	_strcat(st, var);
	_strcat(st, a);
	_strcat(st, num);
	_strcat(st, "\n");
	for (i = 0; st[i] != '\0'; i++)
		;
	free(con);
	write(STDIN_FILENO, st, i);
	free(con);
}
