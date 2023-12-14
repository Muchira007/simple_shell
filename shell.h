#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int prompt(void);
void comd_exec(char *str_Buffer, char *args[], int count);
void _print(const char *composition);
void _strtoken(char *line);
void _execute(char *token, char *tokenArgs, char *fpath);
void pathFinder(char *token);
extern char **environ;

#endif
