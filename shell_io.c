#include "main.h"
/**
 * str_len - returns the lenght of a string
 * @str:the string we will be working on
 * Return: an int
 */
int str_len(char *str)
{
	int x;

	if (str == NULL)
		return (0);
	for (x = 0; str[x] != '\0'; x++)
	{
	}
	return (x);
}

/**
 * double_free - frees pointer to pointers
 * @el: adress of the element to be freed
 * Return: void
 */
void double_free(char **el)
{
	int x;

	for (x = 0; el[x] != NULL; x++)
		free(el[x]);
	free(el);
}

/**
 * single_free - double free for pointers.
 * @n: num of pointers
 * Return: void
 */
void single_free(int n, ...)
{
	int x;
	char *str;
	va_list a_list;

	va_start(a_list, n);
	for (x = 0; x < n; x++)
	{
		str = va_arg(a_list, char*);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(a_list);
}

