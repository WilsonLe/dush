#include <string.h>
#include <stdio.h>

char *parsePath(char **path, char *program)
{
	char *currentPath = path[0];
	char *programPath = strcat(currentPath, program);
	return programPath;
};