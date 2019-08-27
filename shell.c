#include "shell.h"
/**
 * execute - find in command special caracter and run
 * @line2: command
 * Return: 0
 */
void execute(char line2[])
{
	int lengthline2, flaqsc, flaqcomment, flaqspace;
	int sizeFirstArray, sizeSecondArray;

	lengthline2 = _strlen(line2);
	char copy[lengthline2];
	flaqsc = semicolon(line2);
	flaqcomment = comment(line2);
	flaqspace = Space(line2);

	if (flaqsc == 0 && flaqcomment == 0)
	{
		char *finalTokens[flaqspace + 1];
		finalCommandTokens(finalTokens, line2);
		run(finalTokens, line2);
	}
	else if (flaqsc != 0 && flaqcomment == 0)
	{
		char *slicedCommand[2];
		split(copy, slicedCommand, ";");
		char copy1[_strlen(slicedCommand[0])];

		_strcpy(copy1, slicedCommand[0]);
		sizeFirstArray = Space(copy1);
		char *tokensFirstArray[sizeFirstArray + 1];

		finalCommandTokens(tokensFirstArray, slicedCommand[0]);
		char copy2[_strlen(slicedCommand[1])];

		_strcpy(copy2, slicedCommand[1]);
		sizeSecondArray = Space(copy2);
		char *tokensSecondArray[sizeSecondArray + 1];

		finalCommandTokens(tokensSecondArray, slicedCommand[1]);
		runsemicolon(tokensFirstArray, tokensSecondArray);
	}
	else if (flaqcomment == 1)
	{
		char *slicedCommand[2];
		split(copy, slicedCommand, "#");
		slicedCommand[1] = strtok(slicedCommand[1], " ");
		executeOutputFileCommand(slicedCommand[0], slicedCommand[1]);
	}
}
