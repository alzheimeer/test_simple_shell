#include "shell.h"

void _env(void)
{
	int i;
	char *s = *environ;
	for (i = 0; s; i++)
	{
		write(STDIN_FILENO, s, _strlen(s));
		write(STDIN_FILENO, "\n", 1);
		s = *(environ + i);
	}
}
