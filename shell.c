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
	char copy[2], *finalTokens[1], *slicedCommand[2];
	char copy1[2], copy2[2], *tokensFirstArray[1], *tokensSecondArray[1];

	lengthline2 = _strlen(line2);
	copy[lengthline2];
	flaqsc = semicolon(line2);
	flaqcomment = comment(line2);
	flaqspace = Space(line2);

	if (flaqsc == 0 && flaqcomment == 0)
	{
		slicedCommand[2];
		finalTokens[flaqspace + 1];
		finalCommandTokens(finalTokens, line2);
		run(finalTokens, line2); }
	else if (flaqsc != 0 && flaqcomment == 0)
	{
		split(copy, slicedCommand, ";");
		copy1[_strlen(slicedCommand[0])];

		_strcpy(copy1, slicedCommand[0]);
		sizeFirstArray = Space(copy1);
		tokensFirstArray[sizeFirstArray + 1];

		finalCommandTokens(tokensFirstArray, slicedCommand[0]);
		copy2[_strlen(slicedCommand[1])];

		_strcpy(copy2, slicedCommand[1]);
		sizeSecondArray = Space(copy2);
		tokensSecondArray[sizeSecondArray + 1];

		finalCommandTokens(tokensSecondArray, slicedCommand[1]);
		runsemicolon(tokensFirstArray, tokensSecondArray); }
	else if (flaqcomment == 1)
	{
		slicedCommand[2];
		split(copy, slicedCommand, "#");
		slicedCommand[1] = strtok(slicedCommand[1], " ");
		executeOutputFileCommand(slicedCommand[0], slicedCommand[1]); }
}
