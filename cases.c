#include "shell.h"
/**
 * run - execute command
 * @tokens:
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
 * @slicedCommand:
 * @c:
 */
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
