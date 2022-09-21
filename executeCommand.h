#ifndef EXECUTECOMMAND
#define EXECUTECOMMAND

/**
 * @brief execute non-built-in command
 *
 * @param programPath the path of the program
 * @param inputString the processed input string
 * @param output the redirect file
 * @param childPid the process ID of the child process
 * @return none
 */
void executeCommand(char *programPath, char *inputString, char *output, int *childPid);

#endif