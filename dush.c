#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bootstrap.h"
#include "path.h"

// if there is user input parsing error, call this function then call continue in while loop
void printError(){};

// if user called programs throw error, dush just need to call continue

int main()
{
	// setbuf(stdout, NULL);
	int hasError = 0;

	char *exitString = "exit";

	const int MAX_PATH = 256;
	const int MAX_PATH_CHAR = 256;
	size_t MAX_INPUT_CHAR = 256;
	char **path;

	char *inputString = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);

	setup(&path, MAX_PATH, MAX_PATH_CHAR);

	while (1)
	{
		// user input
		printf("> ");
		getline(&inputString, &MAX_INPUT_CHAR, stdin);

		// start edit from here

		// data validation (white spaces, tabs): Minh & Khoi (save for last, for now work without validation)

		// check parallel symbol, fit test cases' features
		// string[] list of commands with arguments parseParallelSymbol(inputString): Khoi

		// check redirection symbol, fit test cases' features
		// for each command with argument
		// [command, output path string] parseRedirectionSymbol(command with argument): Minh

		// handleBuiltInCommands(inputString, path): Khoi

		// any command that made it here is not a built in command

		// string programPath = pathParser(): Minh
		char *programPath = parsePath(path, inputString);

		// exec on the program path: Khoi
		printf("path: %s\n", programPath);
	}

	teardown(&path, MAX_PATH);
	return 0;
};