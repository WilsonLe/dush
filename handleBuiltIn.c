#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "bootstrap.h"

int handleBuiltInCommands(char *inputString, char ***path, char *redirectPath, int MAX_PATH, int MAX_PATH_CHAR, int MAX_INPUT_CHAR, int *numPath)
{
    char *copyInputString = strdup(inputString);
    char *copyPtr = copyInputString;
    int numArg = 0;
    for (int i = 0; i < strlen(copyInputString); i++)
    {
        if (copyInputString[i] == ' ')
        {
            numArg += 1;
        }
    }
    char *cmd = strsep(&copyInputString, " ");
    if (strcmp(cmd, "exit") == 0)
    {
        if (numArg == 0)
        {
            exit(0);
        }
        else
        {
            free(copyPtr);
            return 1;
        }
    }
    else if (strcmp(cmd, "cd") == 0)
    {
        if (numArg == 1)
        {
            chdir(copyInputString);
            free(copyPtr);
            return 0;
        }
        else
        {
            free(copyPtr);
            return 1;
        }
    }
    else if (strcmp(cmd, "path") == 0)
    {
        int count = 0;
        *(numPath) = 0;

        char *argStr;
        while ((argStr = strsep(&copyInputString, " ")) != NULL)
        {
            char *_argStr = strdup(argStr);
            if (strcmp(&(argStr[strlen(argStr) - 1]), "/") != 0)
            {
                strcat(_argStr, "/");
            }
            (*path)[count] = _argStr;
            count += 1;
            *(numPath) += 1;
            // intentionally not free this because will be freed when teardownPath
            // free(_argStr)
        }
        free(copyPtr);
        return 0;
    }
    else
    {
        free(copyPtr);
        return -1;
    }
}