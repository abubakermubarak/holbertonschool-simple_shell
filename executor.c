#include "holberton.h"

/**
 * execute_command - Executes a single-word command
 * @line: the command entered
 */
void execute_command(char *line)
{
	char *argv[2];

	if (access(line, X_OK) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", line);
		exit(127);
	}

	argv[0] = line;
	argv[1] = NULL;

	if (execve(argv[0], argv, environ) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
