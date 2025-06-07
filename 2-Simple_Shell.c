#include "holberton.h"

void __attribute__ ((constructor)) premain()
{
	printf("$ ");
}
/**
 * main - Simple UNIX shell (Task 2)
 * Return: 0 on success, 1 on error
*/
/*
* Check if in interactive mode
* Check if the command is built-in
* check if the command is "exit"
* Try to execute the program
*/

int main(void)
{
	char *lptr; 
	size_t len ;
	char **command;
	ssize_t read; 
	lptr = NULL;
	envo[0].name = "USER";
	envo[0].value = "Default";
	envo[1].name = "PWD";
	envo[1].value = "~/holberton";
	/* Read lines until EOF (Ctrl+D) */
	 while ((read = getline(&lptr, &len, stdin)) != -1)
	{
		printf("intput: %li chacaters\n", read);
		if (lptr[read-1] == '\n')
		{
			lptr[read-1] = '\0';
		}
		command = split(lptr, " ");
		if (is_built_in(lptr) == true)
		{	
			/* Check if command is exit*/
			if (strcmp(command[0], "exit") == 0)
			{
				exit(-1);
			}
			else if(strcmp(command[0], "env") == 0)
			{
				env();
				exit(3);
			}
			else
			{
				command[0] =strcpy(command[0], _which(command[0]));
				execute(command);
				printf("$ ");
			}	
	 	}
		else
		{
			printf("name: %s value: %s\n", envo[1].name, envo[1].value);
			if (strcmp(command[0], "cd") == 0)
			{
				printf("cd found\n");
				_chdir(command[1]);
				printf("%s\n",envo[1].value);
			}
			printf("name: %s value: %s\n", envo[1].name, envo[1].value);
			exit(1);
		}
		
	}
	 free(lptr);
	printf("\n");
	return (0);
} 