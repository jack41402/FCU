#include "IQueue.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    srand(time(NULL)); // Initialize random seed

    const int trialCount = rand() % 10 + 1;
    IQueue queue;
    std::cout << "Trial count: " << trialCount << std::endl;
    
    for (int i = 0; i < trialCount; i++) {
        int enqueueOps = rand() % 99 + 1; // Random enqueues
        int dequeueOps = rand() % enqueueOps; // Ensure dequeueOps < queue size

        std::cout << "\n>>>> Trial " << i + 1 << ": enqueue and dequeue operations" << std::endl;
        std::cout << "Enqueue " << enqueueOps << " elements to the queue." << std::endl;
		for (int j = 0; j < enqueueOps; j++) {
            int val = rand() % 99 + 1;
            queue.enqueue(val);
        }
        std::cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail:";
		queue.display();
		std::cout << "\n\n";
		
		std::cout << "Dequeue " << dequeueOps << " elements to the queue." << std::endl;
        for (int j = 0; j < dequeueOps; j++) {
            queue.dequeue();
        }
        std::cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail:";
        queue.display();
		std::cout << "------------------------------------------------------------------------------------------" << std::endl;
    }

    return 0;
}
