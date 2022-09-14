#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
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

		// handleBuiltInCommands(inputString, path)
		if (strcmp(inputString, exitString) != 0)
		{
			// call exit system call
			printf("Exited");
			break;
		}

		// any command that made it here is not a built in command

		// string programPath = pathParser()

		// exec on the program path

		// data handling
		printf("You typed: %s\n", inputString);
	}
	return 0;
}