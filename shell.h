#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* morza estuvo aqui */
#include <string.h>
#define DELIM "=: \n"
int main(int ac, char **av, char **env);
char **tokenizator(char **arg, char *line, int *len);
char *_getcommand(char **env, char *input);
#endif
