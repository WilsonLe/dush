#ifndef HANDLEBUILTIN
#define HANDLEBUILTIN

/**
 * @brief execute non-built-in command
 *
 * @param programPath the path of the program
 * @param path all executable path
 * @return none
 */
int handleBuiltInCommands(char* inputString, char **path, int MAX_ARG_LEN, int MAX_INPUT_CHAR);
    
#endif