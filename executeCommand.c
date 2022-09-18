#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void executeCommand(char* programPath, char* inputString){
    // TODO: parse programPath into array to execute execv
    char* copyInputString = strdup(inputString);
    char* copyPtr = copyInputString;
    int numArg = 0;
    for (int i = 0; i<strlen(copyInputString); i++){
        if (copyInputString[i] == ' '){
            numArg += 1;
        }
    }

    char** args = (char **)malloc(sizeof(char *) * (numArg+2));
    args[0] = strsep(&copyInputString, " ");
    for (int i = 1; i<numArg+1; i++){
        args[i] = strsep(&copyInputString, " ");
    }
    args[numArg+1] = NULL;
    // call execv
    execv(programPath, args);
}