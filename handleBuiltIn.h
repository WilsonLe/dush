#ifndef HANDLEBUILTIN
#define HANDLEBUILTIN

/**
 * @brief execute non-built-in command
 *
 * @param programPath the path of the program
 * @param path all executable path
 * @param redirectPath the redirect output file
 * @param MAX_PATH the maximum number of path
 * @param MAX_PATH_CHAR maximum character in a path
 * @param MAX_INPUT_CHAR maximum input size
 * @param numPath the number of paths
 * @return the exit code: 0 OK, 1 wrong built-in syntax, -1 not built in syntax
 */
int handleBuiltInCommands(char *inputString, char ***path, char *redirectPath, int MAX_PATH, int MAX_PATH_CHAR, int MAX_INPUT_CHAR, int *numPath);

#endif