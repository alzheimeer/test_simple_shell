#include "shell.h"
char *_cpy(char *dest, char *src);
int main(){
	char *line, *line2, l[100];
	pid_t pid;

	while (1)
	{
		write(1, "$ ", 2);
		line = lsh_read_line();
		line2 = _cpy(l,line);
		if (!_strcmp("exit", line2))
			break;
		pid = fork();
		if (!pid)
		{
			execute(line2);
			break;
		}
		else
		{
			wait(NULL);
		}
	}
	return 0;
}
char *lsh_read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	return line;
}
char *_cpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\n'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
