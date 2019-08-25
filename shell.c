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
		runsemicolon(copy, dirs);
	}
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
