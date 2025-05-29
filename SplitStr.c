#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * splitStr - Splits a string into tokens using a delimiter
 * @text: The input string
 * @delimiter: The delimiter character (e.g., ",")
 *
 * Return: An array of strings (tokens), NULL-terminated
 */
char **splitStr(char *text, char *delimiter)
{
    char *copy = strdup(text);
    char *token;
    int i = 0;
    int size = 10;  /* Start with space for 10 tokens */
    char **tokens = malloc(sizeof(char *) * size);

    if (!copy || !tokens)
        return (NULL);

    token = strtok(copy, delimiter);
    while (token)
    {
        if (i >= size - 1)
        {
            size *= 2;
            tokens = realloc(tokens, sizeof(char *) * size);
            if (!tokens)
                return (NULL);
        }

        tokens[i] = strdup(token); /* Copy each token */
        i++;
        token = strtok(NULL, delimiter);
    }

    tokens[i] = NULL;  /* Null-terminate the array */
    free(copy);
    return (tokens);
}
