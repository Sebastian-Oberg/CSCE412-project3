#include "LoadBalancer.h"
#include "Generator.h"
#include <cstdlib>
#include <iostream>

/**
 * @brief Constructs a LoadBalancer given # of servers
 * @param numServers - number of servers to initialize
 */
LoadBalancer::LoadBalancer(int numServers)
    : discardedRequestsCount(0)
{
    for (int i = 0; i < numServers; ++i)
    {
        servers.push_back(WebServer());
    }

    std::cout << "LoadBalancer initialized with " << numServers << " servers." << std::endl;
}

/**
 * @brief Adds request to load balancer's queue
 * If queue is full, increment the discardedRequestsCount
 * @param req - the request to add
 */
void LoadBalancer::addRequestToQueue(const Request &req)
{
    if (requestQueue.isQueueFull())
    {
        ++discardedRequestsCount;
        std::cout << "Request discarded due to full queue." << std::endl;
    }

    else
    {
        requestQueue.enqueueRequest(req);
    }
}

/**
 * @brief Distributes load to available servers
 */
void LoadBalancer::distributeLoad()
{
    for (auto &server : servers)
    {
        if (!server.isBusy() && !requestQueue.isQueueEmpty())
        {
            Request req = requestQueue.dequeueRequest();
            server.handleRequest(req);
        }
    }
}

/**
 * @brief Runs simulation given number of time units
 * @param timeUnits - Number of time units
 */
void LoadBalancer::runSimulation(int timeUnits)
{
    for (int t = 0; t < timeUnits; ++t)
    {
        distributeLoad();

        for (auto &server : servers)
        {
            server.tick();
        }

        if (rand() % 10 < 3)
        {
            Request newRequest(generateRandomIP(), generateRandomIP(), rand() % 15 + 1, generateRandomJobType());
            addRequestToQueue(newRequest);
        }
    }
}

/**
 * @brief Gets current size of request queue
 * @return Number of requests in queue
 */
int LoadBalancer::getQueueSize() const
{
    return requestQueue.size();
}

/**
 * @brief Get number of active servers
 * @return Number of active servers
 */
int LoadBalancer::getActiveServerCount() const
{
    int activeCount = 0;

    for (const auto &server : servers)
    {
        if (server.isBusy())
        {
            ++activeCount;
        }
    }
    return activeCount;
}

/**
 * @brief Get number of discarded requests
 * @return Number of discarded requests
 */
int LoadBalancer::getDiscardedRequestsCount() const
{
    return discardedRequestsCount;
}
