#include "main.h"

/**
 * cmd_x - works like cd command in shell of powershell(windows)
 * @line: the adress
 */
void cmd_x(char *line)
{
	int i, x;
	char **argArr;
	const char *delim = "\n\t ";

	x = 0;
	argArr = tInterface(line, delim, x);
	if (argArr[0] == NULL)
	{
		single_free(2, argArr, line);
		return;
	}
	if (argArr[1] == NULL)
	{
		i = find_index("HOME");
		chdir((environ[i]) + 5);
	}
	else if (_strcmp(argArr[1], "-") == 0)
		print_string(argArr[1], 0);

	else
		chdir(argArr[1]);
	double_free(argArr);
}

/**
 * env_x - outputs the variables in the current shell
 * @line: the input
 */
void env_x(__attribute__((unused))char *line)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * exit_x - command to exit the shell
 * @ipt: the input
 */
void exit_x(char *ipt)
{
	free(ipt);
	print_string("\n", 1);
	exit(1);
}

/**
 * check_built_ins - chooses the right function to execute
 * @func: function name
 * Return: a pointer
 * NULL if it fails.
 */
void (*check_built_ins(char *func))(char *func)
{
	int i;

	usine_f builds[] = {
		{"cd", cmd_x},
		{"exit", exit_x},
		{"env", env_x},
		{NULL, NULL}
		};

	for (i = 0; builds[i].name != NULL; i++)
	{
		if (_strcmp(func, builds[i].name) == 0)
		{
			return (builds[i].func);
		}
	}
	return (NULL);
}

/**
 * built_in - Checks for builtin functions
 * @arg_list: list of arg given as inputs
 * @ipt: input
 * Return: 0 on success
 * -1 on failure
 */
int built_in(char **arg_list, char *ipt)
{
	void (*build)(char *);

	build = check_built_ins(arg_list[0]);
	if (build == NULL)
		return (-1);
	if (_strcmp("exit", arg_list[0]) == 0)
		double_free(arg_list);
	build(ipt);
	return (0);
}
