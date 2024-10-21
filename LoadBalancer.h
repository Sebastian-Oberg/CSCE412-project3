#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "WebServer.h"
#include "RequestQueue.h"

/**
 * @brief Manages distribution of network requests across web servers
 */
class LoadBalancer
{
public:
    RequestQueue requestQueue;
    std::vector<WebServer> servers;
    int discardedRequestsCount;

    /**
     * @brief Constructs LoadBalancer with number of servers
     * @param numServers - Number of servers initialized
     */
    LoadBalancer(int numServers);

    /**
     * @brief Adds request to load balancer's queue
     * If queue full, increment discardedRequestsCount
     * @param req - request to add
     */
    void addRequestToQueue(const Request &req);

    /**
     * @brief Runs simulation for given number of time units
     * @param timeUnits - number of time units to run
     */
    void runSimulation(int timeUnits);

    /**
     * @brief Get current size of request queue
     * @return Number of requests in queue
     */
    int getQueueSize() const;

    /**
     * @brief Get number of active servers
     * @return Number of active servers
     */
    int getActiveServerCount() const;

    /**
     * @brief Get number of discarded requests
     * @return Number of discarded requests
     */
    int getDiscardedRequestsCount() const;

private:
    /**
     * @brief Distributes load across available servers
     */
    void distributeLoad();
};

#endif
