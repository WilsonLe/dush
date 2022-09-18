#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void executeCommand(char* programPath, char* inputString, int MAX_NUM_ARG){
    // TODO: parse programPath into array to execute execv


    // call execv
    execv(programPath, args);
}