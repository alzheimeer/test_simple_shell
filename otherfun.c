#include "shell.h"
/**
 * _strchr - that locates a character in a string
 * @s: character locate
 * @c: character to find
 * Return: s or NULL
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	while (*(s + i++))
	{
		if (s[i] == c)
			return (&s[i]);
	}
	if (*(s + i) == c)
	{
		return (&s[i]);
	}
	return (0);
}
/**
 * _strcmp - Compare two strings
 * @s1: The firts string
 * @s2: The second string
 *
 * Return: indication number
 */
int _strcmp(char *s1, char *s2)
{
	char c1, c2;

	do {
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0')
			return (c1 - c2);
	} while (c1 == c2);
	return (c1 - c2);
}
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
/**
 * _strlen - Write a function that returns the length of a string.
 * @s: pointer char
 * Return: nothing
 */
int _strlen(char *s)
{
	int c = 0;

	while (*(s + c) != '\0')
		c++;

	return (c);
}
