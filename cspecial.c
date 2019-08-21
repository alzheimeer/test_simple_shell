#include "shell.h"
/**
 * semicolon - search ; in the command
 * @line2: command
 * Return: 1 is found, else 0
 */
int semicolon(char line2[])
{
	if (_strchr(line2, ';') != NULL)
	{
		return (1);
	}
	return (0);
}
/**
 * comment - search # in the command
 * @line2: command
 * Return: 1 is found, else 0
 */
int comment(char line2[])
{
	if (_strchr(line2, '#') != NULL)
	{
		return (1);
	}
	return (0);
}
/**
 * Space - search spaces in the command
 * @line2: command
 * Return: 1 is found, else 0
 */
int Space(char line2[])
{
	if (_strchr(line2, ' ') != NULL)
	{
		return (1);
	}
	return (0);
}
