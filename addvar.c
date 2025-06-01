#include "holbeton.h"

var *add_var(var *head,char *name, char *value)
{
    var new_var = malloc(sizeof(var));
    if (new_var == NULL)
    {
        return (NULL);
    }
    new_var->name = name;
    new_var->value = value;
    new_var->next = NULL;
    if (*head == NULL)
    {
        return (new_var);
    }
    var *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_var;
    return(head);
}