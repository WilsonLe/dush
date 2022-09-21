#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bootstrap.h"
#include "path.h"
#include "parser.h"
#include "validator.h"
#include "handleBuiltIn.h"
#include "executeCommand.h"
#include <unistd.h>

// if user called programs throw error, dush just need to call continue

int main(int argc, char **argv)
{
	// setbuf(stdout, NULL);
	int hasError = 0;

	char *exitString = "exit";

	const int MAX_PATH = 256;
	const int MAX_PATH_CHAR = 256;
	long int MAX_INPUT_CHAR = 256;

	int numPath = 0;
	int buildInExitCode = 0;
	char **path;

	char *inputString = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);

	setup(&path, MAX_PATH, MAX_PATH_CHAR, &numPath);

	if (argc == 2)
	{
		char *filename = argv[1];
		FILE *fp;
		// char* line = NULL;
		size_t len = 0;
		size_t read;

		fp = fopen(filename, "r");
		while ((read = getline(&inputString, &len, fp)) != -1)
		{
			// printf("Retrieved line of length %d:\n", (int)read);
			// printf("Line %s:\n", inputString);
			inputString[(int)read - 1] = '\0';
			// printf("%s", line);
			// execute on each line
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

				// handleBuiltInCommands(inputString, path): Khoi
				buildInExitCode = handleBuiltInCommands(command, &path, redirectPath, MAX_PATH, MAX_PATH_CHAR, MAX_INPUT_CHAR, &numPath);

				// any command that made it here is not a built in command
				char *programPath = parsePath(path, command, numPath, MAX_PATH_CHAR, MAX_INPUT_CHAR);

				if (programPath == NULL)
					continue;

				if (buildInExitCode == -1)
				{
					executeCommand(programPath, parsedInputString, redirectPath);
				}
				else if (buildInExitCode == 1)
				{
					char error_message[30] = "An error has occurred\n";
					write(STDERR_FILENO, error_message, strlen(error_message));
				}

				free(command);
				free(redirectPath);
			}
			free(commands);
		}
		fclose(fp);
	}
	else if (argc == 1)
	{
		while (1)
		{
			// user input
			printf("$ ");
			getline(&inputString, &MAX_INPUT_CHAR, stdin);
			// start edit from here

			char *validatedInputString = validateInputString(inputString);

			char *parsedInputString = parseInputString(validatedInputString);
			if (strlen(parsedInputString) == 0)
				continue;

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

				// handleBuiltInCommands(inputString, path): Khoi
				buildInExitCode = handleBuiltInCommands(command, &path, redirectPath, MAX_PATH, MAX_PATH_CHAR, MAX_INPUT_CHAR, &numPath);

				// any command that made it here is not a built in command
				char *programPath = parsePath(path, command, numPath, MAX_PATH_CHAR, MAX_INPUT_CHAR);
				if (programPath == NULL)
					continue;

				if (buildInExitCode == -1)
				{
					executeCommand(programPath, parsedInputString, redirectPath);
				}
				else if (buildInExitCode)
				{
					char error_message[30] = "An error has occurred\n";
					write(STDERR_FILENO, error_message, strlen(error_message));
				}
				free(command);
				free(redirectPath);
			}
			free(commands);
		}
	}
	else
	{
		char error_message[30] = "An error has occurred\n";
		write(STDERR_FILENO, error_message, strlen(error_message));
	}
	free(inputString);
	teardown(&path, MAX_PATH);
	return 0;
};
