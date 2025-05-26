#include "holberton.h"
node* append(node *head , char *string)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        return (NULL);
    }
    new->str = strdup(string);
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        node* tmp = head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
    return (head);
}