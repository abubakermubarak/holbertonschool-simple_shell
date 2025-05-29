#include "holberton.h"
int execute_builtin(char *path, char *argv[])
{
    //if (execve(argv[0], argv, NULL) == "exit")
    //{
        //printf("exit");
    if(strcmp(argv[0], "exit") == 0){

        int status = _atoi(argv[1]);
        if(status == 0)
        {
            exit(-1);
        }
            exit(status);
    }

    else{
        execve(argv[0], argv, NULL);
        printf("%s\n", argv[0]);
    }

    return(0);
}