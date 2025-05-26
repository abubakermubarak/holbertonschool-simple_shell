#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>      /* For perror */
#include <sys/types.h>  /* For pid_t */
#include <sys/wait.h> 
#include <sys/stat.h>
typedef struct stat st;
typedef struct node
{
    char *str;
    struct node* next;
}node;
int execute(char *argv[]);
char** split(char *string, char *delimiter);
node* append(node *head , char *string);
node* get_path(char **path);
bool is_built_in(char *command);
char * _which(char * filename);
void env(void);
#endif