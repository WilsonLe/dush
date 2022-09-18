#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *trim(char *str)
{
	char *end;

	// Trim leading space
	while (isspace((unsigned char)*str))
		str++;

	if (*str == 0) // All spaces, return str
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;

	// Write new null terminator character
	end[1] = '\0';

	return str;
}

char *parseInputString(char *inputString)
{
	char *trimmedInputString = trim(inputString);
	return trimmedInputString;
}

void parseRedirection(char *parsedInputString, char **command, char **redirectPath)
{
	char *_command = strtok(parsedInputString, ">");

	if (_command == NULL)
	{
		printf("Error Occurred\n");
		return;
	}

	char *_trimmedCommand = trim(_command);

	strcpy(*command, _trimmedCommand);

	char *_redirectPath = strtok(NULL, ">");
	if (_redirectPath == NULL)
	{
		*redirectPath = NULL;
	}
	else
	{
		char *_trimmedRedirectPath = trim(_redirectPath);
		strcpy(*redirectPath, _trimmedRedirectPath);
	}
}

void parseParallel(char *parsedInputString, char ***commands, int numCommands)
{
	char *command = strtok(parsedInputString, "&");
	char *trimmedCommand = trim(command);
	(*commands)[0] = trimmedCommand;
	for (int i = 1; i < numCommands; i++)
	{
		command = strtok(NULL, "&");
		trimmedCommand = trim(command);
		(*commands)[i] = trimmedCommand;
	}
}

int countNumCommands(char *parsedInputString)
{
	char *_parsedInputString = strdup(parsedInputString);
	int numCommands = 1;
	char *firstCommand = strtok(_parsedInputString, "&");

	char *command = strtok(NULL, "&");
	while (command != NULL)
	{
		numCommands++;
		command = strtok(NULL, "&");
	}
	free(_parsedInputString);
	return numCommands;
}