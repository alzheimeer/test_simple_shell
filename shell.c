#include "shell.h"

void execute(char dig[])
{
	int commandSize = strlen(dig);
	int cantPipes = countPipeOcurrence(dig);
	int cantFluxCommand = countFluxOcurrence(dig);
	char copy[commandSize];
	strcpy(copy, dig);

	if (cantPipes == 0 && cantFluxCommand == 0)
	{
		int cantTokens = countBySpace(copy);
		char *finalTokens[cantTokens + 1];
		finalCommandTokens(finalTokens, dig);
		executeBasicCommand(finalTokens, dig);
	}
	else if (cantPipes != 0 && cantFluxCommand == 0)
	{
		char *slicedCommand[2];
		split(copy, slicedCommand, "|");

		//separar tokens del primer subarreglo
		char copy1[strlen(slicedCommand[0])];
		strcpy(copy1, slicedCommand[0]);
		int sizeFirstArray = countBySpace(copy1);
		char *tokensFirstArray[sizeFirstArray + 1];
		finalCommandTokens(tokensFirstArray, slicedCommand[0]);

                //separar tokens del segundo subarreglo
		char copy2[strlen(slicedCommand[1])];
		strcpy(copy2, slicedCommand[1]);
		int sizeSecondArray = countBySpace(copy2);
		char *tokensSecondArray[sizeSecondArray + 1];
		finalCommandTokens(tokensSecondArray, slicedCommand[1]);

		executeCommandWithPipes(tokensFirstArray, tokensSecondArray);
	}
	else if (cantFluxCommand == 1)
	{
		char * slicedCommand[2];
		split(copy, slicedCommand, ">");
		slicedCommand[1] = strtok(slicedCommand[1], " ");
		executeOutputFileCommand(slicedCommand[0], slicedCommand[1]);
	}
}
//cuenta si hay un pipe en el comando
int countPipeOcurrence(char dig[])
{
	if (strchr(dig, '|')!=NULL)
	{
		return 1;
	}
	return 0;
}
//cuenta si hay un '>' en el comando
int countFluxOcurrence(char dig[])
{
	if (strchr(dig, '>')!=NULL)
	{
		return 1;
	}
	return 0;
}
//llena cada posicion del arreglo finaltokens con cada token presente del comando
void finalCommandTokens(char * finalTokens[], char dig[])
{
	char * puntero;
	int i = 0;
	puntero = strtok(dig, " ");

	while(puntero != NULL)
	{
		finalTokens[i] = puntero;
		puntero = strtok(NULL, " ");
		i++;
	}
	finalTokens[i] = NULL;
}
void executeBasicCommand(char *tokens[], char dig[])
{
	execvp(tokens[0], tokens);
	printf("%s: no se encontro la orden\n", dig);
}
//separa el comando en dos subarreglos cuando encuentra el pipe o el '>'
void split(char dig[], char *slicedCommand[], char c[])
{
	char * puntero;
	int i = 0;
	puntero = strtok(dig, c);

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
int countBySpace(char dig[])
{


	return 1;
}
