#ifndef PARSER
#define PARSER

/**
 * @brief parse input string into valid answer
 *
 * @param inputString raw input string that needs parsing
 * @return parsed input string
 */
char *parseInputString(char *inputString);

/**
 * @brief parse input sstring into commands with args and redirection path
 *
 * @param parsedInputString input string to be parsed
 * @param command result command to be parsed. NULL if no command
 * @param redirectionPath result redirection path to be parsed. NULL if no direction path is specified
 */
void parseRedirection(char *parsedInputString, char **command, char **redirectPath);

/**
 * @brief trim an input string's left and right white spaces
 *
 * @param s input string to be trimmed
 */
char *trim(char *s);
#endif