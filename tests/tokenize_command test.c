#include <stdio.h>

int main(void)
{
    char *argv = NULL;
    char *line = "This is a test";
    // char*line = "ls";
    // char* line = "ls -l";
    //char* line = " ";
    //char* line = NULL;
    tokenize_command(line, argv);
    for (int i = 0; argv[i] != NULL; i++)
    {
        printf("%s\n", argv[i]);
    }
}