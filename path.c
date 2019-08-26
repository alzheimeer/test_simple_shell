#include "shell.h"
/**
 * gpath - Gets the PATH environment.
 * Return: Pointer value of PATH.
 */
char *gpath()
{
	unsigned int i = 0, j = 5, k = 0;
	char *s, **e = environ;

	while (e[i])
	{
		if (e[i][0] == 80 && e[i][3] == 72 && e[i][4] == 61)
		{
			s = malloc(PATH_MAX);
			if (s == NULL)
			{
				write(1, "Error: failed malloc gpath\n", 27);
				return (NULL);
			}
			while (e[i][j])
			{
				s[k] = e[i][j];
				k++;
				j++;
			}
			s[k] = '\0';
			return (s);
		}
		i++;
	}
	return (0);
}
/**
 * splitPath - Splits PATH each ':'
 * @path: Pointer value PATH
 * Return: Pointer each directories
 */
char **splitPath(char *path)
{
	char **d;
	char *carp;
	int i = 0;

	d = malloc(PATH_MAX);
	if (d == NULL)
	{
		write(1, "Error: failed malloc splitPath\n", 31);
		return (NULL);
	}
	carp = strtok(path, ":");
	while (carp)
	{
		d[i] = carp;
		carp = strtok(NULL, ":");
		i++;
	}
	d[i] = NULL;
	return (d);
}
/**
 * checkPath - check with stat in the folders PATH with command
 * @dpath: pointer array of dir in PATH
 * @argv0: pointer to cmd name
 * Return: pointer if found, NULL not found
 */
char *checkPath(char **dpath, char *argv0)
{
	struct stat mao;
	char *completline;
	int i = 0;

	while (dpath[i])
	{
		completline = unePath(dpath[i], argv0);
		if (stat(completline, &mao) == 0)
			return (completline);
		i++;
	}

	return (NULL);
}
/**
 * unePath - Concatenate command argv[0] to each directory path
 * @dpath: pointer a one dir PATH
 * @argv0: command
 * Return: pointer string dir + cmd or NULL error
 */
char *unePath(char *dpath, char *argv0)
{
	int dpathlen, argv0len, len, i = 0, j = 0;
	char *path_cmd;

	dpathlen = _strlen(dpath);
	argv0len = _strlen(argv0);
	len = dpathlen + argv0len;
	path_cmd = malloc(len + 1);
	if (path_cmd == NULL)
	{
		write(1, "Error: malloc catpath\n", 22);
		return (NULL);
	}
	while (dpath[i])
	{
		path_cmd[i] = dpath[i];
		i++;
	}
	path_cmd[i] = '/';
	i++;
	while (argv0[j])
	{
		path_cmd[i] = argv0[j];
		j++;
		i++;
	}
	path_cmd[i] = '\0';
	return (path_cmd);
}
