#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

/**
 * @brief Manages queue of requests for load balancer
 */
class RequestQueue
{
public:
    /**
     * @brief Adds request to queue
     * @param req - The request to add
     */
    void enqueueRequest(const Request &req);

    /**
     * @brief Removes request from queue
     * @return Request at front of queue
     */
    Request dequeueRequest();

    /**
     * @brief Checks if queue empty
     * @return True if queue empty. Else false
     */
    bool isQueueEmpty() const;

    /**
     * @brief Checks if queue full
     * @return True if queue full. Else, otherwise
     */
    bool isQueueFull() const;

    /**
     * @brief Get size of queue
     * @return Number of requests in queue
     */
    int size() const;

private:
    std::queue<Request> queue;
    const int MAX_QUEUE_SIZE = 1000;
};

#endif
