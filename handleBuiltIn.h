#ifndef HANDLEBUILTIN
#define HANDLEBUILTIN

/**
 * @brief execute non-built-in command
 *
 * @param programPath the path of the program
 * @param path all executable path
 * @return none
 */
int handleBuiltInCommands(char *inputString, char **path,char *redirectPath, int MAX_PATH, int MAX_PATH_CHAR, int MAX_INPUT_CHAR);

#endif