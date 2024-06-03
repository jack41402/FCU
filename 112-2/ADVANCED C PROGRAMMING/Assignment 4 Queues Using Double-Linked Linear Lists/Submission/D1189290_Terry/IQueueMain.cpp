#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IQueue.h" 

int main() {
    IQueue Q;
    int trial_count; // Trial count;
    
    std::srand(static_cast<unsigned int>(std::time(NULL))); // Seed of random number generator.
    
    trial_count = std::rand() % 10 + 1; // Trial count, at most 10 trials.
    printf("Trial count: %d\n\n", trial_count); // Print trial count.
    
    for (int i = 0; i < trial_count; ++i) {
        printf(">>>> Trial %d: enqueue and dequeue operations\n", i + 1);
        
        int enqueue_count = std::rand() % 100 + 1; // Number of enqueue operations.
        printf("Enqueue %d elements to the queue.\n", enqueue_count);
        for (int j = 0; j < enqueue_count; ++j) {
            Q.enqueue(std::rand() % 100); // Push elements to the queue.
        }
        printf("Current queue size: %d. Content of queue from head to tail:\n", Q.getSize());
        Q.printHeadToTail(); // Print elements from head to tail.
        
        int dequeue_count = std::rand() % Q.getSize(); // Number of dequeue operations.
        printf("\n\nDequeue %d elements from the queue.\n", dequeue_count);
        for (int j = 0; j < dequeue_count; ++j) {
            Q.dequeue(); // Pop elements from the queue.
        }
        printf("Current queue size: %d. Content of queue from head to tail:\n", Q.getSize());
        Q.printHeadToTail(); // Print elements from head to tail.
        
        printf("-------------------------------------------------------------------\n\n"); // Print separate line.
    }
    
    return 0;
}

