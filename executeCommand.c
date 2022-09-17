#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void executeCommand(char* programPath, char* inputString, int MAX_NUM_ARG){
    int lenPath = strlen(path);
    char *tempPath = "";

    // TODO: parse programPath into array to execute execv

    if (access(strcat(tempPath, programPath), X_OK) != -1){
        // call execv
    }
}