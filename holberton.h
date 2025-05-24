#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
int execute(char *argv[]);
char** tokenizr(char *string, char *delimiter);
#endif