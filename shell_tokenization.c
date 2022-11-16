#include "main.h"

/**
 * tokenize_path - tokenizes a path
 * @index: the index of the path.
 * @str: delimitor
 * Return: An array if we succed
 * Otherwise, it will be NULL
 */
char **tokenize_path(int index, char *str)
{
	char *vars;
	int x = 0, len;
	const char *delim = ":\n";
	char **z;

	len = str_len(str);
	vars = environ[index] + (len + 1);
	z = tInterface(vars, delim, x);
	if (z == NULL)
		return (NULL);
	return (z);
}

/**
 * count_token - xounternof token
 * @ipt:input
 * @delim: delimeter
 * Return: an int
 */
int count_token(char *ipt, const char *delim)
{
	char *str;
	char *token;
	int i;

	str = _strdup(ipt);
	if (str == NULL)
		return (-1);
	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);
	free(str);
	return (i);
}
