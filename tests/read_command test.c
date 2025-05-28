#include <stdio.h>

int main(void)
{
    char *lptr = NULL;
    size_t *len;
    ssize_t count;
    count = read_command(lptr,len, stdin);
    if (count == -1)
    {
        printf("Eof or Ctrl + D\n");
    }
    if (lptr[0] == '\n')
    {
        printf("just hit Enter\n");
    }
    
}