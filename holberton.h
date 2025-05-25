#ifndef HOLBERTON_H
#define HOLBERTON_H
typedef struct node
{
    char *str;
    struct node* next;
}node;
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
int execute(char *argv[]);
char** split(char *string, char *delimiter);
node* append(node **head , char *string);
#endif