#include "shell.h"
/**
 * _isdigit - prints 1 if it is a digit
 * @c: The character to say if is digit
 * Return: 0 if compilation is succesfully
 */
int _isdigit(int c)
{
	if (c > 47 && c < 58)
	{
		return (1);
	}
	return (0);
}
