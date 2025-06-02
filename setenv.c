#include "holberton.h"
// extern  var envo;
int set_env(char *name, char *value, int overwrite)
{
    if (name == NULL || strlen(name) == 0 || value == NULL)
    {
        return (-1);
    }
    bool flag;
    flag = false;
    int len, i;
    len = sizeof(envo) / sizeof(var);
    /* serach in the environment for the variable name*/
    
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
		for (i = 0; i < len; i++)
		{
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