#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bootstrap.h"
#include "path.h"
#include "parser.h"
#include "validator.h"

// if there is user input parsing error, call this function then call continue in while loop
void printError(){};

// if user called programs throw error, dush just need to call continue

int main()
{
	setbuf(stdout, NULL);
	int hasError = 0;

	char *exitString = "exit";

	const int MAX_PATH = 256;
	const int MAX_PATH_CHAR = 256;
	long int MAX_INPUT_CHAR = 256;

	int numPath = 0;
	char **path;

	char *inputString = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);

	setup(&path, MAX_PATH, MAX_PATH_CHAR, &numPath);

	while (1)
	{
		// user input
		printf("$ ");
		getline(&inputString, &MAX_INPUT_CHAR, stdin);
		// start edit from here

		char *validatedInputString = validateInputString(inputString);

		char *parsedInputString = parseInputString(validatedInputString);

		// check parallel symbol, fit test cases' features
		int numCommands = countNumCommands(parsedInputString);
		char **commands = (char **)malloc(sizeof(char *) * numCommands);
		for (int i = 0; i < numCommands; i++)
			commands[i] = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);

		parseParallel(parsedInputString, &commands, numCommands);

		for (int i = 0; i < numCommands; i++)
		{
			char *commandAndRedirectPath = commands[i];

			char *command = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);
			char *redirectPath = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);

			parseRedirection(commandAndRedirectPath, &command, &redirectPath);

			printf("command: %s\n", command);
			printf("redirectPath: %s\n", redirectPath);

			// handleBuiltInCommands(inputString, path): Khoi

			// any command that made it here is not a built in command

			char *programPath = parsePath(path, command, numPath, MAX_PATH_CHAR, MAX_INPUT_CHAR);

			// exec on the program path: Khoi
			printf("executing: %s\n", programPath);
			free(command);
			free(redirectPath);
		}

		// intentionally not freeing commands[i] because it's pointers are parts of malloc'd "inputString", which will be freed later.
		free(commands);
	}

	teardown(&path, MAX_PATH);
	free(inputString);
	return 0;
};