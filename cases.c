#include "shell.h"
/**
 * run - execute command
 * @tokens: finaltokens[1]or[2]
 * @line2: command
 * Return: 0
 */
void run(char *tokens[], char line2[])
{
	execvp(tokens[0], tokens);
	printf("%s: command not found\n", line2);
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
	pid_t pid1, pid2;
	int pipefd[2], status1, status2;

	pipe(pipefd);
	pid1 = fork();

	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		execvp(args1[0], args1);
		printf("Command not found\n");
	}

	pid2 = fork();

	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		execvp(args2[0], args2);
		printf("Command not found\n");
	}
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
}
/**
 * executeOutputFileCommand - re direction to file
 * @args: token
 * @fileName: name of file
 * Return: 0
 */
void executeOutputFileCommand(char args[], char fileName[])
{
	close(STDOUT_FILENO);
	open(fileName, O_EXCL | O_CREAT | O_WRONLY, S_IRWXU);
	execute(args);
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
