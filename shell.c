#include "shell.h"
/**
 * execute - find in command special caracter and run
 * @line2: command
 * Return: 0
 */
void execute(char line2[])
{
	int lengthline2 = _strlen(line2);
	int x, flaqsc, flaqspace, sizeFirstArray, sizeSecondArray;
	char copy[lengthline2];
	char *cmd;
	char *path;
	char **dirs;
	char **tokens;

	path = get_path(environ);
	dirs = split_path(path);
	flaqsc = flaqs(line2);
	flaqspace = Space(line2);
	_strcpy(copy, line2);
	if (flaqsc == 0)
	{
		x = (count(line2, ' ')) + 1;
		char *argv[x];

		splitSpace(argv, line2);
		cmd = search_path(dirs, argv[0]);
		if (cmd == NULL)
			printf("commanddsds not found: %s\n", argv[0]);
		else
			execve(cmd, argv, NULL);

		//	run(argv, line2);
	}
	else if (flaqsc == 1)
	{
		runsemicolon(char copy[], char dirs[])
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

//		run(argv2, ex2);
	}
	else if (flaqsc == 2)
	{
		char *slicedCommand[2];

		split(copy, slicedCommand, "#");
		slicedCommand[1] = strtok(slicedCommand[1], " ");
		executeOutputFileCommand(slicedCommand[0], slicedCommand[1]); }
}
/**
 * countSpace - count number of space in the command
 * @line2: command
 * Return: number of the space
 */
int count(char line2[], char c)
{
	int j = 0, k = 0;

	while (line2[j])
		{
			if (line2[j] == c)
			{
				k++;
			}
			j++;
		}
	return (k);
}
