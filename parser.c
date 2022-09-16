#include <string.h>

char *parseInputString(char *inputString)
{
	if (strcmp(&inputString[strlen(inputString) - 1], "\n") == 0)
	{
		inputString[strlen(inputString) - 1] = '\0';
	}
	return inputString;
}