#include "holberton.h"

bool is_built_in(char *command)
{
    int i,l, len;
    st t;
    /*
    if (command[strlen(command)] != '\0')
    {
        command[strlen(command)] = '\0';
    }
    */
    char *path = getenv("PATH");
    char **dir = split(path, ":");
    len = sizeof(dir);
    char* paths[len];
    printf("before loop\n");
    for (i = 0; i<len-2; i++)
    {
        l = strlen(dir[i]);
        /* Add the new character at the end*/
        dir[i][l] = '/'; /* bin/*/
        /* Add the null terminator */
        dir[i][l + 1] = '\0';
        paths[i]=strcat(dir[i],command);/* >> /bin/ls*/
        printf("After strcat\n");    
    }
    i = 0;
    while (paths[i])
    {
        
        if (stat(paths[i], &t) == 0)
        {
            //printf("built-in\n");
            return (true);
        }
        i++;
    }
    //printf("not built-in\n");
    return (false);
}
/*
int main (void)
{
    char *command = "grep";
    is_built_in(command);
}
*/


