#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
char* _which(char* file)
{
    char *path = getenv("PATH");
    printf("%s\n", path);
    char *dir = malloc(sizeof( char *));
    int i = 0;
    dir = strtok(path, ":");
    printf("%s", dir[0]);
}
int main(void)
{
    _which("ls");
}