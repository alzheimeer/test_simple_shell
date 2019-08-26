#ifndef shell_l
#define shell_l

#define PATH_MAX 512
#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
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
int count(char line2[], char c);

int Space(char dig[]);
int flaqs(char dig[]);
void split(char line2[], char *slicedCommand[], char c[]);
void splitSpace(char *argv[], char line2[]);
void run(char line[], char *dpath[]);
void runsemicolon(char copy[], char *dpath[]);
void execute(char dig[]);

char *checkPath(char **dpath, char *argv0);
char *gpath();
char **splitPath(char *path);
char *unePath(char *dpath, char *argv0);

#endif
