#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
extern char **environ;
char **get_tokens(char *str_line);
void my_exe(char **args, char **environ);
void remove_newline(char **str_line, ssize_t *read_bytes);
void free_args(char **args);
#endif
