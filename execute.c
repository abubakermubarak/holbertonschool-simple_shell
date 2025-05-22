#include "main.h"
#include <string.h>
int execute(char *line, size_t *len, char *argv[])
{
    ssize_t read;
    pid_t pid;
    while ((read = getline(&lptr, &len, stdin)) != -1)
    {
        if (read > 0 && lptr[read - 1] == '\n')
        {
            lptr[read - 1] = '\0';
        }
        argv[0] = lptr;
        argv[3] = NULL;
        pid = fork();
        if (pid == -1)
        {
            exit(1)
        }
        if (pid == 0)
        {
            if (lptr[0] != '\n')
            {
                if (execve(argv[0], argv, NULL) == -1)
                {
                    perror("ERRor");
                }
            }        
        }
    }
}