#include "holberton.h"

/**
 * main - A very simple UNIX command line interpreter
 *
 * Description:
 * - Displays a prompt ($)
 * - Reads a command (one word only)
 * - Executes it using execve
 * - Print an error if the command doesn't exist
 * - Repeats until Ctrl+D (EOF)
 *
 * Return: Always 0
 */

 void __attribute__ ((constructor)) premain()
 {
	 printf("$ ");
 }
 int main(void)
 {
	/*
	* Check if in interactive mode
	* Check if the command is built-in
	* check if the command is "exit"
	* Try to execute the program
	*/

	 char *lptr = NULL;
	 size_t len = 0;
	 ssize_t read;
	 char *argv[64];
	 int i = 0;
	 int status;
	 /* Read lines until EOF (Ctrl+D) */
	 while ((read = getline(&lptr, &len, stdin)) != -1)
	 {
		
		printf("Entered while\n");
		if (is_built_in(lptr))
		{
			printf("bulit-in\n");
			/*printf("Line 32\n");*/
			pid_t pid = fork();
			if (pid == -1)
			{
				printf("Fork Failed\n");
				exit(2);
			}
			if (pid == 0)
			{
				argv[0] = lptr;
				if (read > 1)
				{

					if (execve(argv[0], argv, NULL) == -1)
					{
						printf("Un executable command\n");
						exit(3);
						// exit -- > can't execute command
					}
					else
					{
						wait(&status);
					}
				}
			}
			/*
			else
			{
				printf("No Input\n");
			}
			*/
			
	 	}
		else
		{
			printf("Not built-in\n");
			exit(1);
		}
	}
	// exit() command not found
 	//printf("Line 39\n");
	 free(lptr);
	 //printf("\n");
	 return (0);
 }
