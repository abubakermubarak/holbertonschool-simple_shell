#include "holberton.h"

bool is_built_in(char *command)
{
    int i,l, len;
    st t;
    char *path = getenv("PATH");
    char **dir = split(path, ":");
    len = sizeof(dir);
    char* paths[len];
    for (i = 0; i<len-1; i++)
    {
        l = strlen(dir[i]);
        /* Add the new character at the end*/
        dir[i][l] = '/';
        /* Add the null terminator */
        dir[i][l + 1] = '\0';
        paths[i]=strcat(dir[i],command);
    }
    i = 0;
    while (paths[i])
    {
        
        if (stat(paths[i], &t) == 0)
        {
            
            return (true);
        }
        i++;
    }
    return (false);
}