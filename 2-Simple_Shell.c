#include "holberton.h"

void __attribute__ ((constructor)) premain()
{
	printf("$ ");
}
/**
 * main - Simple UNIX shell (Task 2)
 * Return: 0 on success, 1 on error
*/


int main(void)
 {
	envo[0].name = "USER";
	envo[0].value = "Default";
	envo[1].name = "PWD";
	envo[1].value = "~/holberton";
	/*
	* Check if in interactive mode
	* Check if the command is built-in
	* check if the command is "exit"
	* Try to execute the program
	*/

	 char *lptr = NULL;
	 size_t len = 0;
	 ssize_t read;
	 char **argv;
	 int i = 0;
	 char *path;
	 int status;
	 /* Read lines until EOF (Ctrl+D) */
	 
	 while ((read = getline(&lptr, &len, stdin)) != -1)
	{
		
		printf("intput: %li chacaters\n", read);
		if (lptr[read-1] == '\n')
		{
			lptr[read-1] = '\0';
			//printf("replaced n with \\0\n");
		}
		char **command = split(lptr, " ");
		if (is_built_in(lptr) == true)
		{
			//printf("bulit-in\n");
			
			/* Check if command is exit*/
			if (strcmp(command[0], "exit") == 0)
			{
				printf("exiting......\n");
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
				
				//printf("%s\n", command[0]);
				// argv[0] = strcpy(argv[0], path);
				// printf("Executing command\n");
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
	
	// exit() command not found
 	//printf("Line 39\n");
	 free(lptr);
	printf("\n");
	return (0);
} 