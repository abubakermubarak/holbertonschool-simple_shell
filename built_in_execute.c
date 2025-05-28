#include "holberton.h"
int execute_builtin(char *command)
{
    /* check if the command is exit*/
    if (strcmp(command, "exit") == 0)
    {
        exit();
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