#include "Generator.h"
#include <cstdlib>
#include <string>

/**
 * @brief Generates random IP address (format is XXX.XXX.XXX.XXX)
 *
 * @return A string that represents a randomly generated IP address
 */
std::string generateRandomIP()
{
    return std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256);
}

/**
 * @brief Generates a random job type
 *
 * Returns either 'P' for processing or 'S' for streaming at random
 *
 * @return char 'P' or 'S'
 */
char generateRandomJobType()
{
    return (rand() % 2 == 0) ? 'P' : 'S';
}
