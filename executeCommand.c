#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void executeCommand(char* programPath, char* inputString){
    char* copyInputString = strdup(inputString);
    char* copyPtr = copyInputString;

    // To be changed to the input of users
    char* output = "out.txt";

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

    int rc = fork();

    if (rc == -1){
        printf("fork failed");
    }
    else if (rc == 0){
        freopen(output, "w", stdout);
        execv(programPath, args);
    }
    else {
        wait(NULL);
        printf("print something");
        free(copyPtr);
        free(args);
    }
}