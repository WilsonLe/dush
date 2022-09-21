#ifndef PATH
#define PATH

/**
 * @brief parse input program into full path to the program
 *
 * @param path list of directory to look for input program
 * @param program name of program
 * @param numPath the number of paths
 * @param MAX_PATH_CHAR the maximum size of a path
 * @param MAX_INPUT_CHAR the maximum input size
 */
char *parsePath(char **path, char *program, int numPath, const int MAX_PATH_CHAR, const int MAX_INPUT_CHAR);

#endif