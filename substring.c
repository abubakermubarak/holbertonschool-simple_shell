#include "holberton.h"
list_t* split(char *string, char *delimiter)
{
    int i=0;
    int lenn=sizeof(string);
    list_t *head = NULL;
    list_t *tail = NULL;
    list_t *sub_strings = (list_t*)malloc(sizeof(list_t));
    printf("sizeof %ld\n",sizeof(list_t));
    char *token;
    token = strtok(string, delimiter);
    list_t *temp = head;
    while (token != NULL) {

        list_t *new_node= (list_t*)malloc(sizeof(list_t));
        new_node->str=strdup(token);
        new_node->num=i;
        new_node->next = NULL;

        if (head ==NULL){
            tail=new_node;
            head=new_node;
        }
        else {
            tail->next=new_node;
        }
        token = strtok(NULL, " - ");
        // free(temp);
        i++;
    }
    return (head);
}