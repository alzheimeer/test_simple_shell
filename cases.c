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
 * runsemicolon - manage two arg when found semicolon
 * @args1: first tok the command
 * @args2: second tok the command
 * Return: 0
 */
void runsemicolon(char copy[], char *dirs[])
{
	int x;
	char *cmd;
	char *ppp[2];

	split(copy, ppp, ";");
	char ex1[_strlen(ppp[0])];
	char ex2[_strlen(ppp[1])];

	_strcpy(ex1, ppp[0]);
	_strcpy(ex2, ppp[1]);

	x = (count(ex1, ' ')) + 1;
	char *argv1[x];

	splitSpace(argv1, ex1);
	cmd = search_path(dirs, argv1[0]);
	if (cmd == NULL)
		printf("commanddsds not found: %s\n", argv1[0]);
	else
		execve(cmd, argv1, NULL);

	//run(argv1, ex1);

	x = (count(ex2, ' ')) + 1;
	char *argv2[x];

	splitSpace(argv2, ex2);
	cmd = search_path(dirs, argv2[0]);
	if (cmd == NULL)
		printf("commanddsds not found: %s\n", argv2[0]);
	else
		execve(cmd, argv2, NULL);

	//run(argv2, ex2);
}
/**
 * executeOutputFileCommand - re direction to file
 * @args: token
 * @fileName: name of file
 * Return: 0
 */
void executeOutputFileCommand(char args[], char fileName[])
{





}
void splitSpace(char *argv[], char line2[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, " ");
	while (puntero != NULL)
	{
		argv[i] = puntero;
		puntero = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
}
void split(char line2[], char *slicedCommand[], char c[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, c);
	while (puntero != NULL)
	{
		slicedCommand[i] = puntero;
		puntero = strtok(NULL, c);
		i++;
	}
}
