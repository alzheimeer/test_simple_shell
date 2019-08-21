#ifndef shell_l
#define shell_l

#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdint.h>
#include <fcntl.h>

char *_cpy(char *dest, char *src);
char *readc(void);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
void sigintHandler(int sig_num);

int Space(char dig[]);
int semicolon(char dig[]);
int comment(char dig[]);
void split(char dig[], char *slicedCommand[], char c[]);
void finalCommandTokens(char *finalTokens[], char dig[]);
void run(char *tokens[], char dig[]);
void runsemicolon(char *args1[], char *args2[]);
void executeOutputFileCommand(char args[], char fileName[]);
void execute(char dig[]);



#endif
