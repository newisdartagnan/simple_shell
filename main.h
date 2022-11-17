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
#define PROMPT " "

extern char **environ;


/* featured functions*/
void error_printing(char *, int, char *);
void exec_error(char *, int, char *);

#endif
