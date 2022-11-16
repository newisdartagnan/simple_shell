#ifndef _BUILTIN_H_
#define _BUILTIN_H_

int built_in(char **, char *);
void (*check_built_ins(char *))(char *);
void cmd_x(char *);
void exit_x(char *ipt);
void env_x(char *);
/**
 * struct builtin_d - create the built-ins functions
 * @nam: name
 * @func: a pointer
 */
typedef struct usine
{
        char *name;
        void (*func)(char *);
} usine_f;
#endif
