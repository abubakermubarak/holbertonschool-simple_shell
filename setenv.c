#include "holberton.h"
extern  var envo;
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
        if (strcmp(envo[i]->name, name)== 0)
        {
            flag = true;
            if (overwrite != 0)
            {
                envo[i].value = value;
            }
        }
    }
    if (flag == false)
    {
        var *new_var = malloc(sizeof(var));
        if (new_var == NULL)
        {
            return (-1);
        }
        new_var->name = name;
        new_var->value = value;
        envo[i] = new_var;
    }
    free(new_var);
    return (0);
}