#include "shell.h"

char *comments(char *line)
{
	int i, j = 0;
	char *compare = ". \t\r\n\a";
	char aux;

Here:
	while (compare[j] != '\0')
	{
		if (line[0] == compare[j])
		{
			for (i = 0; line [i] != '\0'; i++)
			{
				aux = line[i + 1];
				line[i] = aux;
			}
			goto Here;
		}
		j++;
	}
	for (i = 0; line [i] != '\0'; i++)
	{
		if( line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
	}
	return(line);
}
