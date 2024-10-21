#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

/**
 * @brief Simulates web server that processes network requests
 */
class WebServer
{
public:
    bool is_busy;
    int time_left;
    Request current_request;

    /**
     * @brief Constructs WebServer and initializes to idle state
     */
    WebServer();

    /**
     * @brief Starts processing request
     * @param req - The request to process
     */
    void handleRequest(const Request &req);

    /**
     * @brief Updates server's state
     */
    void tick();

    /**
     * @brief Checks if server is busy
     * @return True - if server is busy. Else, otherwise
     */
    bool isBusy() const;
};

#endif
