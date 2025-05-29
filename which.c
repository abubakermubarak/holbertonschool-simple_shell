
#include "holberton.h"


char * _which(char * filename)
{
 st t;
int len, i;
char *path = getenv("PATH");
    //filename=ls
char **dir = split(path, ":");
len = sizeof(dir);
char* paths[len];

for (i = 0; i<len-1; i++)
{
    int l = strlen(dir[i]);

    // Add the new character at the end
    dir[i][l] = '/';

    // Add the null terminator
    dir[i][l + 1] = '\0';
    paths[i]=strcat(dir[i],filename);

}

i=0;
while (paths[i])
    {
        //printf("%s:", paths[i]);
        if (stat(paths[i], &t) == 0)
        {
            //printf(" FOUND\n");
            return paths[i];
        }
        i++;
    }
    return NULL;
}
/*
int main(void)
{
    char *path = _which("ls");
    printf("%s\n", path);
}
*/