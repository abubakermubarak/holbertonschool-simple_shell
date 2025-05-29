#include "holberton.h"
#include <stdio.h>
int _atoi(char *string)
{
    int i,num,sign;
    i = 0;
    num = 0;
    sign = 1;
    /* skip while spaces and newline*/
    while(string[i] == ' ' || string[i] == '\t' || string[i] == '\n')
    {
        i++;
    }
    /*Check for the sign*/
    if (string[i] == '+' || string[i] == '-')
    {
        if (string[i] == '-')
        {
            sign = -1;
        }
        i++;
    }
    /* loop untill the end of the string or reach non-numeric*/
    while (string[i] && (string[i] >= '0' && string[i] <= '9'))
    {
        num = num * 10 + (string[i] - '0');
        i++;
    }
    return (sign * num);
}
