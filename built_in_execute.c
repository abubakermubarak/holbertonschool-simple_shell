#include "holberton.h"
int execute_builtin(char *command, char *arg)
{
    int status;
    status  = _atoi(arg);
    /* check if the command is exit*/
    if (strcmp(command, "exit") == 0)
    {
        exit(status);
    }
    /* check if the command is env*/
    else if (strcmp(command, "env") == 0)
    {
        env();
    }
    else
    {
        /* Failed to execution*/
        return (-1);
    }
    return(0);
}