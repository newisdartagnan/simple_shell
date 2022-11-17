#include "main.h"
/**
 * _strcmp - compares 2 strings
 * @s1: String 1
 * @s2: String 2
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int res = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			res = (s1[i] - s2[i]);
			break;
		}
		i++;
	}
	return (res);
}
/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: A string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
		if (src[j] == '\0')
			break;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 * Return: a pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - calculates the len of  a string
 * @str: the string we will work on
 * Return: len of str
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
/**
 * _strdup - imitates the original strdup
 * @str: src
 * Return: a pointer
 */
char *_strdup(char *str)
{
	char *chaine = NULL;

	if (str == NULL)
		return (NULL);
	chaine = malloc(_strlen(str) + 1);

	if (chaine == NULL)
		return (NULL);

	_strcpy(chaine, str);
	return (chaine);
}
