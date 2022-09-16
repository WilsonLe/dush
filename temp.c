#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char *input = "123456789";
	char currentPath[9]; // add spare bytes to prevent stack overflow when doing strcpy
	printf("%d\n", strlen(input));
	printf("%d\n", sizeof currentPath);
	if (sizeof input > sizeof currentPath)
	{
		printf("Error occured\n");
		return -1;
	}
	strcpy(currentPath, input);
	printf("%s\n", currentPath);
	return 0;
}