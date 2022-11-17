#include "main.h"
/**
 * add_path - adds path
 * @head: head of linked list
 * @str: the string
 * Return: pointer
 */
path_t *add_path(path_t **head, const char *str)
{
	path_t *tmp;
	path_t *last = *head;

	tmp = malloc(sizeof(path_t));
	if (tmp == NULL)
		return (NULL);
	if (str != NULL)
		tmp->path = _strdup((char *)str);
	else
		tmp->path = "(nil)";
	tmp->next = NULL;
	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	return (tmp);
}
/**
 * pLinker - path linkerp
 * Return: linkedlist
  */
path_t *pLinker()
{
	const char *name = "PATH";
	char *nodevalue;
	path_t *head;

	head = NULL;
	nodevalue = _get_env(name);
	nodevalue = strtok(nodevalue, ":");
	while (nodevalue != NULL)
	{
		add_path(&head, nodevalue);
		nodevalue = strtok(NULL, ":");
	}
	return (head);
}

/**
 * xPath - execute the command
 * @x: cmd
 * @op: options to a cmd
 * Return: 0 or -1
 */
int xPath(char *x, char **op)
{
	DIR *dir;
	int st = 0;
	struct dirent *pDirent;
	path_t *head = pLinker();
	path_t *tmp = head;
	char *path = NULL;

	while (tmp->next != NULL)
	{
		dir = opendir(tmp->path);
		if (dir == NULL)
		{
			printf("Cannot open directory '%s'\n", head->path);
			return (1);
		}
		while ((pDirent = readdir(dir)) != NULL)
		{
			if ((_strcmp(pDirent->d_name, x)) == 0)
			{
				path = _strdup(tmp->path);
				path = _strcat(path, "/");
				path = _strcat(path, x);
				op[0] = malloc(_strlen(path) + 1);
				_strcpy(op[0], path);
				break;
			}
		}
		closedir(dir);
		if (path != NULL)
			break;
		tmp = tmp->next;
	}
	if ((execve(path, op, NULL)) == -1)
		st = -1;
	free(path);
	free_list(head);
	return (st);
}
