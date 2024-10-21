#include <iostream>
#include "LoadBalancer.h"
#include "Generator.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int num_servers, num_cycles;

    std::cout << "Enter the number of servers: ";
    std::cin >> num_servers;

    if (num_servers <= 0)
    {
        std::cerr << "Error: Number of servers must be greater than 0." << std::endl;
        return 1; // Return exit code if input is invalid
    }

    // Get user input
    std::cout << "Enter the number of clock cycles: ";
    std::cin >> num_cycles;

    LoadBalancer loadBalancer(num_servers);

    // large number of initial requests
    for (int i = 0; i < num_servers * 100; ++i)
    {
        std::string ip_in = generateRandomIP();
        std::string ip_out = generateRandomIP();
        int processing_time = rand() % 15 + 1;
        char job_type = generateRandomJobType();
        Request new_request(ip_in, ip_out, processing_time, job_type);
        loadBalancer.addRequestToQueue(new_request);
    }

    std::cout << "Starting queue size: " << loadBalancer.getQueueSize() << std::endl;
    std::cout << "Task time range is between 1 and 15 clock cycles." << std::endl;
    loadBalancer.runSimulation(num_cycles);
    std::cout << "Ending queue size: " << loadBalancer.getQueueSize() << std::endl;

    int active_servers = loadBalancer.getActiveServerCount();
    int inactive_servers = num_servers - active_servers;
    std::cout << "Active servers: " << active_servers << std::endl;
    std::cout << "Inactive servers: " << inactive_servers << std::endl;

    int discarded_requests = loadBalancer.getDiscardedRequestsCount();
    std::cout << "Rejected/Discarded requests: " << discarded_requests << std::endl;
    std::cout << "Completed successfully." << std::endl;
    return 0;
}
