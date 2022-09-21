#ifndef BOOTSTRAP
#define BOOTSTRAP

/**
 * @brief allocate memory for path, which is a 2d array
 *
 * @param path variable pointer
 * @param MAX_PATH max number of path
 * @param MAX_PATH_CHAR max number of char in a path
 */
void setupPath(char ***path, const int MAX_PATH, const int MAX_PATH_CHAR);

/**
 * @brief deallocate memory for path, which is a 2d array
 *
 * @param path variable pointer
 * @param MAX_PATH max number of path
 */
void teardownPath(char ***path, const int MAX_PATH);

/**
 * @brief inject default values to path
 *
 * @param path path to be injected
 * @param numPath the number of path
 */
void injectDefaultPath(char ***path, int *numPath);

/**
 * @brief setup program before running
 *
 * @param path variable pointer
 * @param MAX_PATH max number of path
 * @param MAX_PATH_CHAR max number of char in a path
 * @param numPath the number of path
 */
void setup(char ***path, const int MAX_PATH, const int MAX_PATH_CHAR, int *numPath);

/**
 * @brief teardown program after running
 *
 * @param path variable pointer
 * @param MAX_PATH max number of path
 */
void teardown(char ***path, const int MAX_PATH);

#endif