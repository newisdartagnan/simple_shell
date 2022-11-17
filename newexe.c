#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
/**
 * main - function main for starting
 * @argc: a counter of arguments
 * @argv: a pointer which contain a list of arguments
 * Return: 0 when it successes
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	char *buf, *p;
	pid_t pid;
	size_t bufsize = 32;

	buf = (char *)malloc(bufsize * sizeof(char));

	while (1)
	{
		printf("($) ");
		if (!getline(&buf, &bufsize, stdin))
			break;
		p = strchr(buf, '\n');

		if (p)
			*p = 0;
		if (strcmp(buf, "exit") == 0)
			break;
		/*char *tok = strtok(buf, " ");*/
		pid = fork();
		*argv[argc] = {buf, (char *)0};

		if (pid == 0)
		{	/*Child*/
			execve(argv[0], argv, NULL);
			perror("exec");
			exit(1);
		}
		else	/*Parent*/
			wait(NULL);
	}
	return (0);
}
