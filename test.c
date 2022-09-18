#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    // pid_t pid = fork();
    // char* arg[] = { "ls", "-a", "-C", ">", NULL };
    // char s[100];

    // if (pid == -1)
    //     perror("fork error");
    // else if (pid == 0) {
    //     // printf("%s\n", getcwd(s, 100));
    //     execv("/bin/ls", arg);
    //     // printf("%s\n", getcwd(s, 100));
    // } else {
    //     wait(NULL);
    // }


    // char* stri = strdup("abc edef ghi");
    // char* firstword = strsep(&stri, " ");
    // printf("%s\n", firstword);
    // int count = 0;
    // for (int i = 0; i<strlen(stri); i++){
    //     printf("%d\n", strcmp(&stri[i], " "));
    //     if (stri[i] == ' '){
    //         count += 1;
    //     }
    // }
    // // printf("%s", firstword);
    // printf("%d\n", count);

    // char **temp = (char **)malloc(sizeof(char *) * 3);
    // char **arg = (char **)malloc(sizeof(char *) * 3);
    // // printf("%d\n", (int)strlen(*arg));
    // for (int i = 0; i < 3; i++){
    //     (arg)[i] = "abc";
    // }
    // free(temp);
    // temp = arg;
    // temp[2] = "cde";
    // for (int i = 0; i < 3; i++){
    //     printf("%s\n", temp[i]);
    // }
    char* inputString = (char *)malloc(sizeof(char) * 100);
    inputString = "clear";
    char* programPath = "/bin/clear";

    char* copyInputString = strdup(inputString);
    char* copyPtr = copyInputString;
    char* output = "./out.txt";

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
        printf("print something\n");
        free(copyPtr);
		free((args)[numArg+1]);
        free(args);
    }

    return 0;
}
