#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(char* programPath, char** path){
    // pid_t pid = fork();
    // char* arg[] = { "chdir", "/..", NULL };
    // char s[100];

    // if (pid == -1)
    //     perror("fork error");
    // else if (pid == 0) {
    //     printf("%s\n", getcwd(s, 100));
    //     // execv("/bin/chdir", arg);
    //     chdir("..");
    //     printf("%s\n", getcwd(s, 100));
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

    char **temp = (char **)malloc(sizeof(char *) * 3);
    char **arg = (char **)malloc(sizeof(char *) * 3);
    // printf("%d\n", (int)strlen(*arg));
    for (int i = 0; i < 3; i++){
        (arg)[i] = "abc";
    }
    free(temp);
    temp = arg;
    temp[2] = "cde";
    for (int i = 0; i < 3; i++){
        printf("%s\n", temp[i]);
    }
    return 0;
}