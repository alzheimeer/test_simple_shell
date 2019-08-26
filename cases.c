#include "shell.h"
/**
 * run - execute command
 * @tokens: finaltokens[1]or[2]
 * @line2: command
 * Return: 0
 */
void run(char *tokens[], char line2[])
{
	execve(tokens[0], tokens, NULL);
	write(1, line2, _strlen(line2));
	write(2, ": not found\n", 12);
}
/**
 * runsemicolon - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * Return: 0
 */
void runsemicolon(char copy[], char *dpath[])
{
	int x;
	char *dpathcmd;
	char *ppp[2];

	split(copy, ppp, ";");
	char ex1[_strlen(ppp[0])];
	char ex2[_strlen(ppp[1])];

	_strcpy(ex1, ppp[0]);
	_strcpy(ex2, ppp[1]);

	x = (count(ex1, ' ')) + 1;
	char *argv1[x];

	splitSpace(argv1, ex1);
	dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
		write(1, ": not found\n", 12);
	else
		execve(dpathcmd, argv1, NULL);

	x = (count(ex2, ' ')) + 1;
	char *argv2[x];

	splitSpace(argv2, ex2);
	dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		write(1, ": not found\n", 12);
	else
		execve(dpathcmd, argv2, NULL);

}
/**
 * splitSpace - cut each space
 * @argv: array save cut
 * @line2: name of filecommand complete
 * Return: 0
 */
void splitSpace(char *argv[], char line2[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, " ");
	while (puntero)
	{
		argv[i] = puntero;
		puntero = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
}
/**
 * split - cut each delimiter
 * @line2: command
 * @slicedCommand: array save cut
 * @c: delimiter
 * Return: 0
 */
void split(char line2[], char *slicedCommand[], char c[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, c);
	while (puntero)
	{
		slicedCommand[i] = puntero;
		puntero = strtok(NULL, c);
		i++;
	}
}
