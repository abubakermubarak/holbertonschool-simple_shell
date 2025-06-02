#include "holbeton.h"
extern environment;
int _setenv(char *name, char *value, int overwtite)
{
    if (name == NULL || strlen(name) == 0 || value == NULL)
    {
        return (-1);
    }
    bool flag;
    flag = false;
    int len, i;
    len = sizeof(environment);
    /* serach in the environment for the variable name*/
    
    for (i = 0; i < len; i++)
    {
        if (strcmp(environment[i].name, name)== 0)
        {
            flag = true;
            if (overwtite != 0)
            {
                environment[i].value = value;
            }
        }
    }
    if (flag == false)
    {
        var new_var = malloc(sizeof(var));
        if (new_var == NULL)
        {
            return (-1);
        }
        new_var->name = name;
        new_var->value = value;
        environment[i] = new_var;
    }
    return (0);
}