#include "main.h"
/**
 * parse_line - it clear mate. this is the heart of
 * the program
 * @ipt: pointer
 * @size: size
 * @x: counter
 * @name: still clear
 */
void parse_line(char *ipt, size_t size, int x, char **name)
{
	int i, counter;
	ssize_t len;
	char **argList;
	const char *delim = "\n\t ";

	counter = 0;
	write(STDOUT_FILENO, PROMPT, str_len(PROMPT));
	len = getline(&ipt, &size, stdin);
	if (len != -1)
	{
		argList = token_interface(ipt, delim, counter);
		if (argList[0] == NULL)
		{
			single_free(2, argList, ipt);
			return;
		}
		i = built_in(argList, ipt);
		if (i == -1)
			create_child(argList, ipt, x, name);
		for (i = 0; argList[i] != NULL; i++)
			free(argList[i]);
		single_free(2, argList, ipt);
	}
	else
		exit_x(ipt);
}

/**
 * create_child - creates a child process
 * @argList: an list of args
 * @ipt: the input
 * @x: counter
 * @name: name
 */
void create_child(char **argList, char *ipt, int x, char **name)
{
	pid_t id;
	int i, s, c;
	struct stat buf;
	char *cmd;
	char *t_cmd;

	id = fork();
	if (id == 0)
	{
		t_cmd = argList[0];
		cmd = path_finder(argList[0]);
		if (cmd == NULL)
		{
			c = stat(t_cmd, &buf);
			if (c == -1)
			{
				error_printing(name[0], x, t_cmd);
				print_string(": not found", 0);
				single_free(2, ipt, t_cmd);
				for (i = 1; argList[i]; i++)
					free(argList[i]);
				free(argList);
				exit(100);
			}
			cmd = t_cmd;
		}
		argList[0] = cmd;
		if (argList[0] != NULL)
		{
			if (execve(argList[0], argList, environ) == -1)
				exec_error(name[0], x, t_cmd);
		}
	}
	else
		wait(&s);
}

/**
 * token_interface - communicates with cmd
 * @ipt: input.
 * @delim: delimeter
 * @x: counter
 * Return: annarray or Null
 */
char **token_interface(char *ipt, const char *delim, int x)
{
	char **argList;

	x = count_token(ipt, delim);
	if (x == -1)
	{
		free(ipt);
		return (NULL);
	}
	argList = tokenize(x, ipt, delim);
	if (argList == NULL)
	{
		free(ipt);
		return (NULL);
	}

	return (argList);
}

/**
 * tokenize - transforms a cmd into an array
 * @x: len lf the new array
 * @ipt: input
 * @delim: delimiter
 * Return: a pointer or Null
 */
char **tokenize(int x, char *ipt, const char *delim)
{
	int i;
	char **buffer;
	char *token;
	char *line_cp;

	line_cp = _strdup(ipt);
	buffer = malloc(sizeof(char *) * (x + 1));
	if (buffer == NULL)
		return (NULL);
	token = strtok(line_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		buffer[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}
