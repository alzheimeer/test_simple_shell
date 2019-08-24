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
 * split - separate the command into two sub-fixes when it finds
 * # or $
 * @line2: command
 * @slicedCommand: pointer array of 3 element
 * @c: separator
 * Return: 0
 */
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
/**
 * runsemicolon - manage two arg when found semicolon
 * @args1: first tok the command
 * @args2: second tok the command
 * Return: 0
 */
void runsemicolon(char *args1[], char *args2[])
{





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
/**
 * finalCommandTokens - tokens command with space
 * @finalTokens: array 1 or 2
 * @line2: command
 * Return: 0
 */
void finalCommandTokens(char *finalTokens[], char line2[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, " ");
	while (puntero != NULL)
	{
		finalTokens[i] = puntero;
		puntero = strtok(NULL, " ");
		i++;
	}
	finalTokens[i] = NULL;
}
