#include "shell.h"
/**
 * flaqs - search delimiters in the command
 * @line2: command
 * Return: 1 is found, else 0
 */
int flaqs(char line2[])
{
	if (_strchr(line2, ';') != NULL)
		return (1);
	else if (_strchr(line2, '#') != NULL)
		return (2);
	else if (_strchr(line2, '|') != NULL)
		return (3);
	else if (_strchr(line2, '&') != NULL)
		return (4);
	else if (_strchr(line2, '$') != NULL)
		return (5);
	return (0);
}
/**
 * space - search spaces in the command
 * @line2: command
 * Return: 1 is found, else 0
 */
int space(char line2[])
{
	if (_strchr(line2, ' ') != NULL)
	{
		return (1);
	}
	return (0);
}
