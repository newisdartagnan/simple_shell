#include "main.h"

/**
 * error_printing - prints an error
 * @x: an int
 * @name: name of the program running the shell.
 * @cmd: command
 */
void error_printing(char *name, int x, char *cmd)
{
	print_string(name, 1);
	print_string(": ", 1);
	print_number(x);
	print_string(": ", 1);
	print_string(cmd, 1);
}
/**
 * exec_error - simply prints exec errors
 * @name: name
 * @x: counter
 * @cmd: command
*/
void exec_error(char *name, int x, char *cmd)
{
	error_printing(name, x, cmd);
	print_string(": ", 1);
	perror("");
	exit(1);
}
