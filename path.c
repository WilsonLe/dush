/*
* This file is to define a function to generate the full path of the command.
* Name: Khoi Le and Wilson Le
* Date: 9/14/2022
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>

char *parsePath(char **path, char *programWithArgs, int numPath, const int MAX_PATH_CHAR, const int MAX_INPUT_CHAR)
{
	char *programPath = NULL;

	char *_programWithArgs = strdup(programWithArgs);

	char *program = strtok(_programWithArgs, " ");

	if (strcmp(program, "cd") == 0 || strcmp(program, "exit") == 0 || strcmp(program, "path") == 0)
	{
		return program;
	}

	if (access(program, X_OK) == 0)
	{
		return program;
	}

	// add spare bytes to prevent stack overflow when doing strcpy
	char currentPath[MAX_PATH_CHAR + MAX_INPUT_CHAR];

	for (int i = 0; i < numPath; i++)
	{
		currentPath[0] = '\0';
		// double check sizeof path[i] to be smaller than destination current path
		if (strlen(path[i]) > sizeof currentPath)
		{
			char error_message[30] = "An error has occurred\n";
			write(STDERR_FILENO, error_message, strlen(error_message));
			return NULL;
		}
		strcpy(currentPath, path[i]);

		// double check sizeof path[i] + program path to be smaller than destination current path
		if (strlen(path[i]) + strlen(program) > sizeof currentPath)
		{
			char error_message[30] = "An error has occurred\n";
			write(STDERR_FILENO, error_message, strlen(error_message));
			return NULL;
		}
		strcat(currentPath, program);

		if (access(currentPath, X_OK) == 0)
		{
			programPath = currentPath;
			break;
		}
	}

	if (programPath == NULL)
	{
		char error_message[30] = "An error has occurred\n";
		write(STDERR_FILENO, error_message, strlen(error_message));
		return NULL;
	}

	return programPath;
};