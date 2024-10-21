#include "WebServer.h"
#include <iostream>

/**
 * @brief Constructs WebServer and initializes to idle state
 */
WebServer::WebServer() : is_busy(false), time_left(0), current_request("", "", 0, 'P')
{
}

/**
 * @brief Starts processing request
 *
 * @param req - request to process
 */
void WebServer::handleRequest(const Request &req)
{
    is_busy = true;
    time_left = req.time;
    current_request = req;
    std::cout << "Processing request from " << req.ip_in << " to " << req.ip_out << " with time " << req.time << std::endl;
}

/**
 * @brief updates server's state to reduce remaining processing time
 */
void WebServer::tick()
{
    if (is_busy)
    {
        time_left--;
        if (time_left <= 0)
        {
            is_busy = false;
            std::cout << "Request from " << current_request.ip_in << " completed." << std::endl;
        }
    }
}

/**
 * @brief Checks if server is busy
 * @return True if server is busy. Else, false
 */
bool WebServer::isBusy() const
{
    return is_busy;
}
