#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IQueue.h"

int main() {
    srand(time(NULL));

    IQueue queue;

    int trialCount = rand() % 10 + 1; // Random trial count between 1 and 10

    for (int trial = 1; trial <= trialCount; trial++) {
        std::cout << ">>>> Trial " << trial << ": enqueue and dequeue operations" << std::endl;

        int enqCount = rand() % 100 + 1; // Random number of enqueue operations between 1 and 100
        std::cout << "Enqueue " << enqCount << " elements to the queue." << std::endl;

        for (int i = 0; i < enqCount; i++) {
            int val = rand() % 100; // Random integer value between 0 and 99
            queue.enqueue(val);
        }

        std::cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail:" << std::endl;
        queue.printHeadToTail();

        int deqCount = rand() % queue.getSize(); // Random number of dequeue operations less than current queue size
        std::cout << std::endl << "Dequeue " << deqCount << " elements from the queue." << std::endl;

        for (int i = 0; i < deqCount; i++) {
            queue.dequeue();
        }

        std::cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail:" << std::endl;
        queue.printHeadToTail();

        std::cout << "------------------------------------------------" << std::endl << std::endl;
    }

    return 0;
}

