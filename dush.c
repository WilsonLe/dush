#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// if there is user input parsing error, call this function then call continue in while loop
void printError() {}

// if user called programs throw error, dush just need to call continue

int main()
{
	int hasError = 0;

	char *inputString;
	char *exitString = "exit";
	const int MAX_PATH = 256;
	const int MAX_PATH_CHAR = 256;
	char path[MAX_PATH][MAX_PATH_CHAR];

	size_t bufsize = __INT_MAX__;
	size_t characters;

	inputString = (char *)malloc(bufsize * sizeof(char));

	if (inputString == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	while (1)
	{
		// user input
		printf("> ");
		getline(&inputString, &bufsize, stdin);

		// start edit from here

		// data validation (white spaces, tabs): Minh & Khoi (save for last, for now work without validation)

		// check parallel symbol, fit test cases' features
		// string[] list of commands with arguments parseParallelSymbol(inputString): Khoi

		// check redirection symbol, fit test cases' features
		// for each command with argument
		// [command, output path string] parseRedirectionSymbol(command with argument): Minh

		// handleBuiltInCommands(inputString, path): Khoi

		if (strcmp(inputString, exitString) != 0)
		{
			// call exit system call
			printf("Exited");
			break;
		}

		// any command that made it here is not a built in command

		// string programPath = pathParser(): Minh

		// exec on the program path: Khoi
		printf("You typed: %s\n", inputString);
	}

	return 0;
}