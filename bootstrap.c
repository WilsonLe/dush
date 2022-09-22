/*
* This file is to define functions to initiate the program.
* Name: Khoi Le and Wilson Le
* Date: 9/14/2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void injectDefaultPath(char ***path, int *numPath)
{
	*numPath = 1;
	strcpy((*path)[0], "/bin/");
}

void setup(char ***path, const int MAX_PATH, const int MAX_PATH_CHAR, int *numPath)
{
	setupPath(path, MAX_PATH, MAX_PATH_CHAR);
	injectDefaultPath(path, numPath);
};

void teardown(char ***path, const int MAX_PATH)
{
	teardownPath(path, MAX_PATH);
};
