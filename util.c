#include "holberton.h"

void print_int_array(int *a, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		if (i == 0)
			printf("%d", a[i]);
		else
			printf(", %d", a[i]);
	}
	printf("\n");
}
void print_char_array(char ** list, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%s", list[i]);
	
	}
	printf("\n");
}
void print_linked_list(list_t *head)
{
    list_t *current = head;

    while (current != NULL)
    {
        printf("%s", current->str);  // print the string
        current = current->next;     // move to the next node
    }

    printf("\n");
}