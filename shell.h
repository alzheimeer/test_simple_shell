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

extern char **environ;

char *_cpy(char *dest, char *src);
char *readc(void);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
void sigintHandler(int sig_num);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **split_command(char *line);
int execute_command(char **args, char *p, int cont);
char *comments(char *line);
void *_calloc(unsigned int nmemb, unsigned int size);
void errors(int cont, char *var, char *com);
char *_itoa(int n);
int _isdigit(int c);
int _atoi(char *s);

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
