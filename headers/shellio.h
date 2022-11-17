#ifndef _SHELLIO_H_
#define _SHELLIO_H_

int _write_char(char);
int _strcmp(char *, char *);
char *_strdup(char *);
int print_number(int);
void print_string(char *, int);

/* prototypes */

char **tInterface(char *, const char *, int);
int count_token(char *, const char *);
char **tokenize(int, char *, const char *);
void create_child(char **, char *, int, char **);

#endif
