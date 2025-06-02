#include "holbeton.h"

int _setenv(char *name, char *value, int overwtite, var *head)
{
    if (name == NULL || strlen(name) == 0 || value == NULL)
    {
        return (-1);
    }
    bool flag = false;
    /* serach in the linkedlist for the variable name*/
    var *tmp = head;
    while (tmp->next != NULL)
    {
        if (strcmp(tmp->name, name)== 0)
        {
            flag = true;
            if (overwtite != 0)
            {
                tmp->value = value;
                /*need to impelement how update the value in enviromant file*/
            }
        }
        tmp = tmp->next;
    }
    if (flag == false)
    {
        add_var(head, name, value);
    }
    return (0);
}