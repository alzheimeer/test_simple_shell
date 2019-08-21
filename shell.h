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

//int _putchar(char c);
char *_cpy(char *dest, char *src);
char *readc(void);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
//char **_strtok(char *line, char *delim);
//ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
//void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strchr(char *s, char c);

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
