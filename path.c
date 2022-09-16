#include <string.h>
#include <stdio.h>
#include <unistd.h>

char *parsePath(char **path, char *program, int numPath, const int MAX_PATH_CHAR, const int MAX_INPUT_CHAR)
{
	char *programPath = NULL;

	// add spare bytes to prevent stack overflow when doing strcpy
	char currentPath[MAX_PATH_CHAR + MAX_INPUT_CHAR];

	for (int i = 0; i < numPath; i++)
	{
		currentPath[0] = '\0';
		// double check sizeof path[i] to be smaller than destination current path
		if (strlen(path[i]) > sizeof currentPath)
		{
			printf("Error occured\n");
			return NULL;
		}
		strcpy(currentPath, path[i]);

		// double check sizeof path[i] + program path to be smaller than destination current path
		if (strlen(path[i]) + strlen(program) > sizeof currentPath)
		{
			printf("Error occured\n");
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
		printf("Invalid program\n");
		return NULL;
	}

	return programPath;
};