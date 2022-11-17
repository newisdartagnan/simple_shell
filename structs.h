#ifndef _STRUCT_H
#define _STRUCT_H
/**
 * struct path - singly linked list
 * @path: string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct path
{
	char *path;
	struct path *next;
} path_t;

#endif
