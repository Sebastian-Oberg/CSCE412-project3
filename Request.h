#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @brief Represents network request with source and destination IP addresses, processing duration, job type
 */
struct Request
{
    std::string ip_in;
    std::string ip_out;
    int time;
    char job_type;

    /**
     * @brief Constructs Request object with parameters
     *
     * @param src - Source IP address
     * @param dest - Destination IP address
     * @param processing_time - Time required for processing
     * @param type - Job type
     */
    Request(std::string src, std::string dest, int processing_time, char type);
};

#endif