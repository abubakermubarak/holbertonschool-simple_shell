#include "holberton.h"
#include <unistd.h>

int execute(char *argv[])
{
    int status;
    pid_t pid;
    
    printf("command path: %s\n", argv[0]);
    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (pid == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
        {
            perror("Error:");
            return (-1);
        }
    }
    else    
    {
        wait(&status);
    }
    return (0);
}