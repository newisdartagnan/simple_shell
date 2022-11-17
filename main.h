#ifndef _MAIN_H
#define _MAIN_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <stddef.h>
#include <string.h>
<<<<<<< HEAD
#include <stdio.h>
#define PROMPT " "

extern char **environ;

=======
#include "structs.h"
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int execute(char *ipt);
int xPath(char *x, char **op);
char **coreShell(char *ipt);
char *_strcat(char *dest, char *name);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
>>>>>>> 5b872cbd2946dd29fd37d77f2ac3f22ffd7bc804

void free_list(path_t *head);
void shell_loop(char **argv);
void genError(char *name, char **buffer, size_t nEr);
int c_s(char *str);
char *_get_env(const char *name);
void ctrlC(int s);
void env_x(void);

#endif
