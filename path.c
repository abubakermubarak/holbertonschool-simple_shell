#include "holberton.h"
#include <sys/stat.h>
node* get_path(char **path)
{
    node *head;
    int len, i;
    len = sizeof(path);
    head  = NULL;
    printf("%i\n", len);
    for (i = 0; i < len - 1; i++)
    {
        printf("enter loop %i\n", i);
        append(head, path[i]);
    }
}
void print_list(node *head)
{
    while (head != NULL)
    {
        printf("%s:", head->str);
        head = head->next;
    }
}
int main(void)
{
    char *path = getenv("PATH");
    char **dir = split(path, ":");
    node *path_list = get_path(dir);
    //print_list(path_list);
}