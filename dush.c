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
#include <sys/wait.h>

// if user called programs throw error, dush just need to call continue

int main(int argc, char **argv)
{
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
		if (fp == NULL)
		{
			char error_message[30] = "An error has occurred\n";
			write(STDERR_FILENO, error_message, strlen(error_message));
			exit(1);
		}

		while ((read = getline(&inputString, &len, fp)) != -1)
		{
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
			if (commands[0] == NULL)
				continue;

			pid_t *pids = (pid_t *)malloc(sizeof(pid_t) * numCommands);
			int *stat_loc = (int *)malloc(sizeof(int) * numCommands);

			for (int i = 0; i < numCommands; i++)
			{
				char *commandAndRedirectPath = commands[i];

				char *command = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);
				char *redirectPath = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);
				int numRedirs = 0;
				int numOutputSpaces = 0;

				parseRedirection(commandAndRedirectPath, &command, &redirectPath, &numRedirs, &numOutputSpaces);

				// user did input > but did not specify a value after >
				if (numRedirs > 1)
				{
					char error_message[30] = "An error has occurred\n";
					write(STDERR_FILENO, error_message, strlen(error_message));
					continue;
				}
				else if (numRedirs == 1)
				{
					if (numOutputSpaces != 0)
					{
						char error_message[30] = "An error has occurred\n";
						write(STDERR_FILENO, error_message, strlen(error_message));
						continue;
					}

					if (redirectPath == NULL)
					{
						char error_message[30] = "An error has occurred\n";
						write(STDERR_FILENO, error_message, strlen(error_message));
						continue;
					}
				}

				// handleBuiltInCommands(inputString, path): Khoi
				buildInExitCode = handleBuiltInCommands(command, &path, redirectPath, MAX_PATH, MAX_PATH_CHAR, MAX_INPUT_CHAR, &numPath);

				// any command that made it here is not a built in command
				char *programPath = parsePath(path, command, numPath, MAX_PATH_CHAR, MAX_INPUT_CHAR);

				if (programPath == NULL)
					continue;

				if (buildInExitCode == -1)
				{
					executeCommand(programPath, command, redirectPath, &(pids[i]));
				}
				else if (buildInExitCode == 1)
				{
					char error_message[30] = "An error has occurred\n";
					write(STDERR_FILENO, error_message, strlen(error_message));
				}

				free(command);
				free(redirectPath);
			}

			for (int i = 0; i < numCommands; i++)
				waitpid(pids[i], &(stat_loc[i]), 0);

			free(pids);
			free(stat_loc);
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
			if (commands[0] == NULL)
				continue;

			pid_t *pids = (pid_t *)malloc(sizeof(pid_t) * numCommands);
			int *stat_loc = (int *)malloc(sizeof(int) * numCommands);

			for (int i = 0; i < numCommands; i++)
			{
				char *commandAndRedirectPath = commands[i];
				// call fork then exec

				char *command = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);
				char *redirectPath = (char *)malloc(sizeof(char) * MAX_INPUT_CHAR);
				int numRedirs = 0;
				int numOutputSpaces = 0;
				parseRedirection(commandAndRedirectPath, &command, &redirectPath, &numRedirs, &numOutputSpaces);

				// user did input > but did not specify a value after >
				if (numRedirs > 1)
				{
					char error_message[30] = "An error has occurred\n";
					write(STDERR_FILENO, error_message, strlen(error_message));
					continue;
				}
				else if (numRedirs == 1)
				{
					if (numOutputSpaces != 0)
					{
						char error_message[30] = "An error has occurred\n";
						write(STDERR_FILENO, error_message, strlen(error_message));
						continue;
					}

					if (redirectPath == NULL)
					{
						char error_message[30] = "An error has occurred\n";
						write(STDERR_FILENO, error_message, strlen(error_message));
						continue;
					}
				}

				// handleBuiltInCommands(inputString, path): Khoi
				buildInExitCode = handleBuiltInCommands(command, &path, redirectPath, MAX_PATH, MAX_PATH_CHAR, MAX_INPUT_CHAR, &numPath);

				// any command that made it here is not a built in command
				char *programPath = parsePath(path, command, numPath, MAX_PATH_CHAR, MAX_INPUT_CHAR);
				if (programPath == NULL)
					continue;

				if (buildInExitCode == -1)
				{
					executeCommand(programPath, command, redirectPath, &(pids[i]));
				}
				else if (buildInExitCode)
				{
					char error_message[30] = "An error has occurred\n";
					write(STDERR_FILENO, error_message, strlen(error_message));
				}
				free(command);
				free(redirectPath);
			}

			for (int i = 0; i < numCommands; i++)
				waitpid(pids[i], &(stat_loc[i]), 0);

			free(pids);
			free(stat_loc);
			free(commands);
		}
	}
	else
	{
		char error_message[30] = "An error has occurred\n";
		write(STDERR_FILENO, error_message, strlen(error_message));
		exit(1);
	}
	free(inputString);
	teardown(&path, MAX_PATH);
	return 0;
};
