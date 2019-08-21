#ifndef shell_l
#define shell_l

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdint.h>
#include <fcntl.h>


int countBySpace(char dig[]);
int countPipeOcurrence(char dig[]);
int countFluxOcurrence(char dig[]);
void split (char dig[], char *slicedCommand[], char c[]);
void finalCommandTokens(char * finalTokens[], char dig[]);
void executeBasicCommand(char *tokens[], char dig[]);
void executeCommandWithPipes(char *args1[], char *args2[]);
void executeOutputFileCommand(char args[], char fileName[]);
void execute(char dig[]);



#endif
