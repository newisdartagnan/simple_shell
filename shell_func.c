#include "main.h"
/**
 * free_list - free the memory of each node in the list
 * @head: Address of the list
 */
void free_list(path_t *head)
{
	path_t *current = head;
	path_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->path);
		free(current);
		current = next;
	}
}
