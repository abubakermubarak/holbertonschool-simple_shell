#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Simple UNIX shell (Task 2)
 * Return: 0 on success, 1 on error
 */
int main(void)
{
    char *lptr = NULL;
    size_t len = 0;
    ssize_t read;
    char *argv[2];
    pid_t pid;
    int status;

    while (1)
    {
        printf("$ ");
        fflush(stdout); /* Ensure prompt shows before getline */

        read = getline(&lptr, &len, stdin);
        if (read == -1)
        {
            /* Ctrl+D handling */
            if (feof(stdin))
            {
                printf("\n");
                free(lptr);
                exit(0);
            }
            perror("ERROR: Getline Failed");
            free(lptr);
            exit(1);
        }

        /* Remove newline from input */
        if (lptr[read - 1] == '\n')
            lptr[read - 1] = '\0';

        if (lptr[0] == '\0') /* Empty input (Press: Enter) */
            continue;

        pid = fork();
        if (pid == -1)
        {
            perror("ERROR: Fork Failed");
            free(lptr);
            exit(1);
        }

        if (pid == 0)
        {
            argv[0] = lptr;
            argv[1] = NULL;

            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("ERROR: Command Not Found");
                exit(1);
            }
        }
        else
        {
            if (wait(&status) == -1)
            {
                perror("ERROR: Wait Failed");
                free(lptr);
                exit(1);
            }
        }
    }

    return (0);
}
