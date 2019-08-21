#include "shell.h"

void execute(char line2[])
{
	int lengthline2 = _strlen(line2);
	int flaq$$ = special$$(line2);
	int flaqcomment = comment(line2);
	int cantTokens;
	char copy[lengthline2];

	_strcpy(copy, line2);
	if (flaq$$ == 0 && flaqcomment == 0)
	{
		cantTokens = Space(copy);
		char *finalTokens[cantTokens + 1];
		finalCommandTokens(finalTokens, line2);
		executeBasicCommand(finalTokens, line2);
	}
	else if (flaq$$ != 0 && flaqcomment == 0)
	{
		char *slicedCommand[2];
		split(copy, slicedCommand, "|");

		//separar tokens del primer subarreglo
		char copy1[_strlen(slicedCommand[0])];
		_strcpy(copy1, slicedCommand[0]);
		int sizeFirstArray = Space(copy1);
		char *tokensFirstArray[sizeFirstArray + 1];
		finalCommandTokens(tokensFirstArray, slicedCommand[0]);

		//separar tokens del segundo subarreglo
		char copy2[_strlen(slicedCommand[1])];
		_strcpy(copy2, slicedCommand[1]);
		int sizeSecondArray = Space(copy2);
		char *tokensSecondArray[sizeSecondArray + 1];
		finalCommandTokens(tokensSecondArray, slicedCommand[1]);

		executeCommandWithPipes(tokensFirstArray, tokensSecondArray);
	}
	else if (flaqcomment == 1)
	{
		char * slicedCommand[2];
		split(copy, slicedCommand, ">");
		slicedCommand[1] = strtok(slicedCommand[1], " ");
		executeOutputFileCommand(slicedCommand[0], slicedCommand[1]);
	}
}

//llena cada posicion del arreglo finaltokens con cada token presente del comando
void finalCommandTokens(char * finalTokens[], char line2[])
{
	char * puntero;
	int i = 0;
	puntero = strtok(line2, " ");

	while(puntero != NULL)
	{
		finalTokens[i] = puntero;
		puntero = strtok(NULL, " ");
		i++;
	}
	finalTokens[i] = NULL;
}
void executeBasicCommand(char *tokens[], char line2[])
{
	execvp(tokens[0], tokens);
	printf("%s: command not found\n", line2);
}
//separa el comando en dos subarreglos cuando encuentra el pipe o el '>'
void split(char line2[], char *slicedCommand[], char c[])
{
	char * puntero;
	int i = 0;
	puntero = strtok(line2, c);

	while (puntero != NULL)
	{
		slicedCommand[i] = puntero;
		puntero = strtok(NULL, c);
		i++;
	}
}
void executeCommandWithPipes(char *args1[], char *args2[])
{
	pid_t pid1, pid2;
	int pipefd[2], status1, status2;

	pipe(pipefd);
	pid1 = fork();

	if (pid1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO); //abre extremo de escritura
		close(pipefd[0]); // cierra el extremo de lectura ya que no se utilizara
		execvp(args1[0], args1);
		printf("No se encontro la orden\n");
	}

	pid2 = fork();

	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO); //abre extremo de lectura
		close(pipefd[1]); // cierra el extremo de escritura ya que no se utilizara
		execvp(args2[0], args2);
		printf("No se encontro la orden\n");
	}
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
}
//Redirecciona la salida estandar a un archivo
void executeOutputFileCommand(char args[], char fileName[])
{
	close(STDOUT_FILENO);
	open(fileName, O_EXCL|O_CREAT|O_WRONLY, S_IRWXU);
	execute(args);
}
