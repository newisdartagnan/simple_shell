#include "main.h"
/**
 * ctrlC - tackles ctr c
 * @s: signal to verify
 * Return: Always 0.
 */
void ctrlC(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
/**
 * execute - executes the cmd
 * @input: user input
 * Return: 0 or -1
 */
int execute(char *input)
{
	int x = 0, y = 0;
	char **argv;

	if (_strcmp(input, "env\n") == 0)
	{
		env_x();
		return (0);
	}
	else
	{
		argv = coreShell(input);
		if (argv[0][0] == '/' || argv[0][0] == '.')
			y = execve(argv[0], argv, NULL);
		else
			y = xPath(argv[0], argv);
	}
	while (argv[x] != NULL)
	{
		free(argv[x]);
		x++;
	}
	free(argv);
	return (y);
}
/**
 * env_x - print the environment variables
 */
void env_x(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		dprintf(1, "%s\n", environ[i]);
		i++;
	}
}

/**
 * _get_env - get a value of a variable
 * @name: name of environment variable to search
 * Return: the variable
 */
char *_get_env(const char *name)
{
	int i = 0;
	char *tmp, *ptr;

	while (environ[i] != NULL)
	{
		if (_strcmp((char *)name, environ[i]) == 0)
		{
			tmp = environ[i];
			ptr = strtok(tmp, "=");
			ptr = strtok(NULL, "\0");
			break;
		}
		i++;
	}
	return (ptr);
}
/**
 * coreShell - the core function of our program
 * @ipt: the cmd
 * Return: double_pointer
 */
char **coreShell(char *ipt)
{
	int i = 0, j = 0;
	char *path = ipt;
	char *x = _strdup(ipt);
	char **argv = NULL;

	path = strtok(path, " \n\t");
	while (path != NULL)
	{
		i++;
		path = strtok(NULL, " \n\t");
	}
	argv = (char **) malloc((sizeof(char *) * i) + 1);
	if (argv == NULL)
	{
		free(x);
		return (NULL);
	}
	x = strtok(x, " \n\t");
	while (x != NULL)
	{
		argv[j] = _strdup(x);
		j++;
		x = strtok(NULL, " \n\t");
	}
	argv[i + 1] = NULL;
	free(x);
	return (argv);

}
