#include "shell.h"
/**
 * readc - read line command
 * Return: string line with line break
 */
char *readc(void)
{
	char *line = NULL;
	ssize_t bufsize = 0, i;

	i = getline(&line, &bufsize, stdin);
	if (i == -1)
		exit (0);
	return (line);
}
/**
 * _cpy - new string without line break
 * function for getline
 * @dest: destination.
 * @src: source.
 * Return: dest.
 */
char *_cpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\n'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
