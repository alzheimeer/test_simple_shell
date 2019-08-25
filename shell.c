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

	flaqsc = flaqs(line2);
	flaqspace = Space(line2);
	x = (count(line2, ' ')) + 1;
	_strcpy(copy, line2);
	if (flaqsc == 0)
	{
		char *argv[x];

		splitSpace(argv, line2);
		run(argv, line2);
	}
	else if (flaqsc == 1)
	{
		char *argv1[2];

		split(copy, argv1, ";");
		char copy1[_strlen(argv1[0])];

		_strcpy(copy1, argv1[0]);

		x = (count(copy1, ' ')) + 1;
		sizeFirstArray = Space(copy1);
		char *tokensFirstArray[sizeFirstArray + 1];

		splitSpace(tokensFirstArray, argv[0]);
		char copy2[_strlen(argv1[1])];

		_strcpy(copy2, argv1[1]);
		sizeSecondArray = Space(copy2);
		char *tokensSecondArray[sizeSecondArray + 1];

		splitSpace(tokensSecondArray, slicedCommand[1]);
		runsemicolon(tokensFirstArray, tokensSecondArray);
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
