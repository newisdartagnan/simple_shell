#ifndef _MAIN_H_
#define _MAIN_H_

#include "headers/builtin.h"
#include "headers/shellio.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PROMPT "simple shell $ "

extern char **environ;

char **tInterface(char *, const char *, int);
int count_token(char *, const char *);
char **tokenize(int, char *, const char *);
void create_child(char **, char *, int, char **);
void parse_line(char *, size_t, int, char **);
char *path_finder(char *);
int str_len(char *);
int find_index(char *);
char **tokenize_path(int, char *);
char *search_directories(char **, char *);
char *build_path(char *, char *);
void double_free(char **);
void single_free(int, ...);


/* featured functions*/
void error_printing(char *, int, char *);
void exec_error(char *, int, char *);

#endif
