#include "Request.h"

/**
 * @brief Constructs request object with parameters
 *
 * @param src - Source IP address
 * @param dest - Destination IP address
 * @param processing_time - Time required for processing in clock cycles
 * @param type Job - type
 */
Request::Request(std::string src, std::string dest, int processing_time, char type)
    : ip_in(src), ip_out(dest), time(processing_time), job_type(type) {}
