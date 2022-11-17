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
void parse_line(char *, size_t, int, char **);
char *path_finder(char *);
int str_len(char *);
int find_index(char *);
char **tokenize_path(int, char *);
char *search_directories(char **, char *);
char *build_path(char *, char *);
void double_free(char **);


#endif
