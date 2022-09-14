#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *inputString;
	char *exitString = "exit";
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

		if (strcmp(inputString, exitString) != 0)
		{
			// call exit system call
			printf("Exited");
			break;
		}

		// data handling
		printf("You typed: %s\n", inputString);
	}
	return 0;
}