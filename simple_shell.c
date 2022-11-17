#include "main.h"

/**
 * main - the main function
 * @argc: arg count
 * @argv: list of args
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *ipt;
	size_t size;
	int i;

	i = 0;
	signal(SIGINT, SIG_IGN);
	do {
		i++;
		ipt = NULL;
		size = 0;
		parse_line(ipt, size, i, argv);

	} while (1);

	return (0);
}
