#include <stdlib.h>
#include <stdio.h>

void setupPath(char ***path, const int MAX_PATH, const int MAX_PATH_CHAR)
{
	*path = (char **)malloc(sizeof(char *) * MAX_PATH);
	for (int i = 0; i < MAX_PATH; i++)
	{
		(*path)[i] = (char *)malloc(sizeof(char) * MAX_PATH_CHAR);
	}
};

void teardownPath(char ***path, const int MAX_PATH)
{
	for (int i = 0; i < MAX_PATH; i++)
	{
		free((*path)[i]);
	}
	free(*path);
};

void setup(char ***path, const int MAX_PATH, const int MAX_PATH_CHAR)
{
	setupPath(path, MAX_PATH, MAX_PATH_CHAR);
};

void teardown(char ***path, const int MAX_PATH)
{
	teardownPath(path, MAX_PATH);
};
