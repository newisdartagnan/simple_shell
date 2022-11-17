#include "main.h"
/**
 * _itoa - converts int to a string
 * @num: the int to be converted
 * Return: new pointer with number converted to string
 */
char *_itoa(size_t num)
{
	char base[] = "0123456789";
	char *chaine;
	unsigned int len = 0;
	int x = num;

	for (len = 0; num > 0; len++)
	{
		num = num / 10;
	}

	chaine = malloc(sizeof(char) * len);
	if (chaine == NULL)
		return (NULL);
	chaine[len] = '\0';
	do {
		chaine[--len] = base[x % 10];
		x /= 10;
	} while (x != 0);
	return (chaine);
}
/**
 * genError - writes an error
 * @name: name of the cmd
 * @buffer: address of cmd searched
 * @nEr: number of errors
 */
void genError(char *name, char **buffer, size_t nEr)
{
	char *n = _itoa(nEr);

	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, n, _strlen(n));
	write(2, ": ", 2);
	write(2, *buffer, _strlen(*buffer));
	write(2, ": not found\n", 12);
	free(n);
}
/**
 * shell_loop - Makes the shell to always prompt
 * @argv: args
 */
void shell_loop(char **argv)
{
	int errors = 1;
	int status = 0;
	pid_t child;
	char *buffer = NULL;
	int len = 0;
	size_t i = 0;

	while (1)
	{
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		signal(SIGINT, ctrlC), len = getline(&buffer, &i, stdin);
		if (((int)len == -1) || (_strcmp(buffer, "exit\n") == 0))
		{
			if ((int)len == -1 && isatty(0) == 1)
				write(1, "\n", 1);
			break;
		}
		if (_strcmp(buffer, "\n") == 0 || c_s(buffer) == 0)
			continue;
		child = fork();
		if (child == -1)
			free(buffer), perror("Error:");
		if (child == 0)
		{
			if (execute(buffer) == -1)
			{
				genError(argv[0], &buffer, errors);
				free(buffer);
				exit(127);
			}
			exit(EXIT_SUCCESS);
		}
		else
			wait(&status), errors++;
	}
	free(buffer);
}
/**
 * c_s - checks for spaces
 * @str: string to validate
 * Return: 0 or 1
 */
int c_s(char *str)
{
	int i = 0, nspaces = 0;
	int len = _strlen(str);

	while (str[i] != '\0')
	{
		if (str[i] == 32)
			nspaces++;
		i++;
	}
	if (nspaces == (len - 1))
		return (0);
	return (1);
}
