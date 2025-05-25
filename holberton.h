#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
int execute(char *argv[]);
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;
list_t* split(char *string, char *delimiter);
int is_input(char *command);  /* Returns True or False */

/* Prints the shell prompt ($) */
void print_prompt(void);

/* Reads command from standard input */
ssize_t read_command(char **lineptr, size_t *n);

/* Creates a child process to run a command */
int execute(char *argv[]);

/* Tokeniz the input line into arguments */
void tokenize_command(char *line, char *argv);

/* Checks if a command is a built-in */
int is_builtin(char *command);  /* Returns True or False */

/* Fork and Executes a built-in command */
int execute_builtin(char *command);

/* Execute command */
int execute(char *argv[]);

/*Checks if the string is found in the Global Variable */
bool in_path(char *string);

/*Find a path */
char *_which(const char *filename);
void print_int_array(int *a, int n);
void print_char_array(char **list, int n);
void print_linked_list(list_t *head);
#endif