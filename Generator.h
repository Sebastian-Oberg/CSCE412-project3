#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>

/**
 * @brief Generates random IP address
 *
 * @return String representing a random IP address
 */
std::string generateRandomIP();

/**
 * @brief Generates random job type
 *
 * @return 'P' for processing and 'S' for streaming
 */
char generateRandomJobType();

#endif
