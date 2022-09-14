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

	printf("> ");
	getline(&inputString, &bufsize, stdin);
	while (1)
	{
		if (strcmp(inputString, exitString) != 0)
		{
			// call exit system call
			printf("Exited");
			break;
		}
		printf("You typed: %s\n", inputString);
		printf("> ");
		getline(&inputString, &bufsize, stdin);
	}
	return 0;
}