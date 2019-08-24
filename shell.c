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
	x = (countSpace(line2)) + 1;
	if (flaqsc == 0)
	{
		char *argv[x];

		splitSpace(argv, line2);
		run(argv, line2); }
	else if (flaqsc == 1)
	{
		char *slicedCommand[2];

		split(copy, slicedCommand, ";");
		char copy1[_strlen(slicedCommand[0])];

		_strcpy(copy1, slicedCommand[0]);
		sizeFirstArray = Space(copy1);
		char *tokensFirstArray[sizeFirstArray + 1];

		splitSpace(tokensFirstArray, slicedCommand[0]);
		char copy2[_strlen(slicedCommand[1])];

		_strcpy(copy2, slicedCommand[1]);
		sizeSecondArray = Space(copy2);
		char *tokensSecondArray[sizeSecondArray + 1];

		splitSpace(tokensSecondArray, slicedCommand[1]);
		runsemicolon(tokensFirstArray, tokensSecondArray); }
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
int countSpace(char line2[])
{
	int j = 0, k = 0;

	while (line2[j])
		{
			if (line2[j] == ' ')
			{
				k++;
			}
			j++;
		}
	return (k);
}
