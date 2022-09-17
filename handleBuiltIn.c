#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "bootstrap.h"

void handleBuiltInCommands(char* inputString, char **path, int MAX_PATH, int MAX_PATH_CHAR){
    int numArg = 0;
    for (int i = 0; i<strlen(inputString)){
        if (inputString[i] == ' '){
            numArg += 1;
        }
    }
    char* cmd = strsep(&inputString, " ");
    if (strcmp(&cmd, "exit")){
        char* argAfterCmd = strsep(&inputString, " ")
        if (!argAfterCmd){
            char* arg = { NULL };
            execv("exit(1)", arg);
        } else {
            // Raise error
        }
    }
    else if (strcmp(&cmd, "cd")){
        char* arg1 = strsep(&inputString, " ");
        char* arg2 = strsep(&inputString, " ");
        if (arg1 && !arg2){
            chdir("..")
        } else {
            // raise error
        }
    }
    else if (strcmp(&cmd, "path")){
        teardown(&path, MAX_PATH);
        int count = 0;
        setupPath(&path, MAX_PATH, MAX_PATH_CHAR)
        while ((argStr = strsep(&inputString, " ")) != NULL){
            path[count] = argStr;
            count += 1;
        }
    } else {
        // Not a built in function
        return;
    }
}