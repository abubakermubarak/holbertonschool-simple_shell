#include "holberton.h"
var envo[10];

int set_env(char *name, char *value, int overwrite)
{
    if (name == NULL || strlen(name) == 0 || value == NULL)
    {
        return (-1);
    }
    bool flag;
    flag = false;
    int len, i;
    
    /* serach in the environment for the variable name*/
    for (len = 0; envo[len].name != NULL; len++);
    for (i = 0; i < len; i++)
    {
        var tmp= envo[i];
        char *tmpN=(char*)tmp.name;
        if (strcmp(tmpN, name)== 0)
        {
            flag = true;
            if (overwrite != 0)
            {
                envo[i].value = value;
            }
        }
    }
    if (!flag)
	{
        printf("variable not found\n");
		for (i = 0; i < len; i++)
		{
            printf("loop entred\n");
            printf("name: %s; value:%s\n", name, value);
			if (envo[i].name == NULL) // Find the first empty slot
			{
				envo[i].name = name;
				envo[i].value = value;
				return (0); // Successfully added
			}
		}
		// If no empty slot is found
		return (-1); // Indicate failure to add (array is full)
	}
    // free(new_var);
    return (0);
}
