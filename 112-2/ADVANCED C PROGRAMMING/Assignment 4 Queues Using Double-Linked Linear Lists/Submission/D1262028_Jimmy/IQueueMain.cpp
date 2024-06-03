#include "IQueue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    srand(time(NULL)); // Seed for random number generation
    IQueue queue;
    int trialCount = rand() % 10 + 1; // Random number of trials between 1 and 10

    std::cout << "Trial count: " << trialCount << "\n";

    for (int i = 0; i < trialCount; i++) {
        std::cout << "\n>>>> Trial " << (i+1) << ": enqueue and dequeue operations\n";

        // Enqueue operations
        int numEnqueue = rand() % 100 + 1; // Random number of enqueues between 1 and 100
        std::cout << "Enqueue " << numEnqueue << " elements to the queue.\n";
        for (int j = 0; j < numEnqueue; j++) {
            int num = rand() % 99 + 1; // Generates random numbers between 1 and 99
            queue.enqueue(num);
        }
        std::cout << "Current queue size: " << queue.getSize();
        std::cout << ". Content of queue from head to tail:\n";
        queue.printHeadToTail();

        // Dequeue operations, ensuring the number is less than the current queue size
        int numDequeue = rand() % (queue.getSize()); // Generates a number from 0 to size-1
        std::cout << "\n\nDequeue " << numDequeue << " elements from the queue.\n";
        for (int j = 0; j < numDequeue; j++) {
            queue.dequeue();
        }
        std::cout << "Current queue size: " << queue.getSize();
        std::cout << ". Content of queue from head to tail:\n";
        queue.printHeadToTail();

        std::cout << "-------------------------------------------------------------------\n";
    }

    return 0;
}
