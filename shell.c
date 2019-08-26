#include "shell.h"
/**
 * execute - find in command special caracter and run
 * @line2: command
 * Return: 0
 */
void execute(char line2[])
{
	int lengthline2 = _strlen(line2);
	int x, flaqsc, flaqspace;
	char copy[lengthline2];
	char *path;
	char **dpath;
	char *dpathcmd;

	path = gpath();
	dpath = splitPath(path);
	flaqsc = flaqs(line2);
	flaqspace = Space(line2);
	_strcpy(copy, line2);
	if (flaqsc == 0)
	{
		x = (count(line2, ' ')) + 1;
		char *argv[x];

		splitSpace(argv, line2);
		dpathcmd = checkPath(dpath, argv[0]);
		if (dpathcmd == NULL)
			write(1, ": not found\n", 12);
		else
			execve(dpathcmd, argv, NULL);
	}
	else if (flaqsc == 1)
	{
		runsemicolon(copy, dpath);
	}
}
/**
 * count - count number of delimiter in the command
 * @line2: command
 * @c: delimiter
 * Return: number of the delimiter
 */
int count(char line2[], char c)
{
	int j = 0, k = 0;

	while (line2[j])
	{
		if (line2[j] == c)
			k++;
		j++;
	}
	return (k);
}
