#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "bootstrap.h"

int handleBuiltInCommands(char* inputString, char **path, int MAX_PATH, int MAX_PATH_CHAR, int MAX_INPUT_CHAR){
    char* copyInputString = strdup(inputString);
    char* copyPtr = copyInputString;
    int numArg = 0;
    for (int i = 0; i<strlen(copyInputString); i++){
        if (copyInputString[i] == ' '){
            numArg += 1;
        }
    }
    char* cmd = strsep(&copyInputString, " ");
    if (strcmp(cmd, "exit") == 0){
        if (numArg == 0){
            exit(1);
        } else {
            free(copyPtr);
            return 1;
        }
    }
    else if (strcmp(cmd, "cd") == 0){
        if (numArg == 1){
            chdir(copyInputString);
            free(copyPtr);
            return 0;
        } else {
            free(copyPtr);
            return 1;
        }
    }
    else if (strcmp(cmd, "path") == 0){
        teardown(&path, MAX_PATH);
        int count = 0;
        setupPath(&path, MAX_PATH, MAX_PATH_CHAR);
        char* argStr;
        while ((argStr = strsep(&copyInputString, " ")) != NULL){
            path[count] = argStr;
            count += 1;
        }
        free(copyPtr);
        return 0;
    } else {
        free(copyPtr);
        return -1;
    }
}