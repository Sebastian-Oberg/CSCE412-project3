#include "RequestQueue.h"

/**
 * @brief Adds request to queue
 * @param req - The request to add
 */
void RequestQueue::enqueueRequest(const Request &req)
{
    queue.push(req);
}

/**
 * @brief Removes request from queue
 * @return Request at front of queue
 */
Request RequestQueue::dequeueRequest()
{
    Request req = queue.front();
    queue.pop();
    return req;
}

/**
 * @brief Checks if queue is empty
 * @return True if queue empty. Else, false
 */
bool RequestQueue::isQueueEmpty() const
{
    return queue.empty();
}

/**
 * @brief Checks if queue full
 * @return True if queue is full. Else, false
 */
bool RequestQueue::isQueueFull() const
{
    return queue.size() >= MAX_QUEUE_SIZE;
}

/**
 * @brief Get size of queue
 * @return The number of requests in queue
 */
int RequestQueue::size() const
{
    return queue.size();
}
