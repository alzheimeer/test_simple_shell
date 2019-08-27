#define T_B_SIZE 1024
#define T_CUT " \t\r\n\a"
#include "shell.h"

char **split_command(char *line)
{
	int buffer = T_B_SIZE, i = 0;
	char **tokens = malloc(buffer);
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, T_CUT);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= buffer)
		{
			buffer += T_B_SIZE;
			tokens = realloc(tokens, buffer);
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, T_CUT);
	}
	tokens[i] = NULL;
	return (tokens);
}
