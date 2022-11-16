#include "main.h"
/**
 * find_index - returns the index of a given variable
 * @v: the variable
 * Return: the index of the variable.
 * otherwise returns -1.
 */
int find_index(char *v)
{
	int x, y, len;

	len = str_len(v);
	for (x = 0; environ[x] != NULL; x++)
	{
		for (y = 0; y < len; y++)
		{
			if (environ[x][y] != v[y])
			{
				break;
			}
		}
		if (y == len && environ[x][y] == '=')
			return (x);
	}
	return (-1);
}
/**
 * path_finder - finds a path
 * @ipt: the input enterrd by the user.
 * Return: Upon sucess, the path of the program.
 * NULL, otherwise
 */
char *path_finder(char *ipt)
{
	char *str = "PATH";
	char *constructed;
	char **path_tokens;
	int index;
	char *directory;

	index = find_index(str);
	path_tokens = tokenize_path(index, str);
	if (path_tokens == NULL)
		return (NULL);

	directory = search_directories(path_tokens, ipt);
	if (directory == NULL)
	{
		double_free(path_tokens);
		return (NULL);
	}

	constructed = build_path(directory, ipt);
	if (constructed == NULL)
	{
		double_free(path_tokens);
		return (NULL);
	}

	double_free(path_tokens);

	return (constructed);
}

/**
 * search_directories - it is in the name
 * @path_tokens: a pointer
 * @cmd: cmd
 * Return: a string
 */
char *search_directories(char **path_tokens, char *cmd)
{
	int i, s;
	char *cwd;
	char *buf;
	size_t size;
	struct stat stat_buf;

	buf = NULL;
	size = 0;
	cwd = getcwd(buf, size);
	if (cwd == NULL)
		return (NULL);
	if (cmd[0] == '/')
		cmd = cmd + 1;
	for (i = 0; path_tokens[i] != NULL; i++)
	{
		s = chdir(path_tokens[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(cmd, &stat_buf);
		if (s == 0)
		{
			chdir(cwd);
			free(cwd);
			return (path_tokens[i]);
		}
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}

/**
 * build_path - builds the path
 * @directory: the dir
 * @command: cmd
 * Return: a string
 */
char *build_path(char *directory, char *command)
{
	int i, j;
	int dir_len;
	int command_len;
	int len;
	char *built;

	if (directory == NULL || command == NULL)
		return (NULL);
	dir_len = str_len(directory) + 1;
	command_len = str_len(command) + 1;
	len = dir_len + command_len;

	built = malloc(sizeof(char) * len);
	if (built == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		for (j = 0; directory[j] != '\0'; j++, i++)
			built[i] = directory[j];
		built[i] = '/';
		i++;
		for (j = 0; command[j] != '\0'; j++, i++)
			built[i] = command[j];
	}
	built[--i] = '\0';
	return (built);
}
