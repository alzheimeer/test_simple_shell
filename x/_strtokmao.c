#include "shell.h"

char _strtokmao(char *line, char *delim)
{
	char *ret;

	ret = _strcmp(line, delim);
	*ret = '\0';
	return (line);
}
