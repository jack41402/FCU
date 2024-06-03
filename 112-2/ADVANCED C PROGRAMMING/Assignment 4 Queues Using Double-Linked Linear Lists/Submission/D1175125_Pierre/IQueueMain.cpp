#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IQueue.hpp"

using namespace std;

int main() {
    srand(0); // Seed the random number generator with current time

    int trialCount = rand() % 10 + 1; // Random trial count between 1 and 10

    cout << "Trial count: " << trialCount << endl << endl;

    Queue queue; // Create a queue outside the loop

    for (int trial = 0; trial < trialCount; ++trial) {
        cout << ">>>> Trial " << trial + 1 << ": enqueue and dequeue operations" << endl;

        // Enqueue part
        int enqueues = rand() % 100; // Random number of enqueues between 0 and 99
        cout << "Enqueue " << enqueues << " elements to the queue." << endl;
        for (int i = 0; i < enqueues; ++i) {
            int num = rand() % 100; // Random number between 0 and 99
            queue.enqueue(num); // Enqueue the element
        }
        queue.displayAfterEnqueue(); // Display the queue content after enqueueing

        // Dequeue part
        int maxDequeues = min(enqueues, rand() % (queue.getSize() + 1)); // Limit dequeues to the smaller of enqueues or the current queue size
        cout << "Dequeue " << maxDequeues << " elements from the queue." << endl;
        for (int i = 0; i < maxDequeues; ++i) {
            queue.dequeue(); // Dequeue elements
        }
   
        queue.display(); // Display the queue content after dequeueing
        cout << endl << endl;
    }

    return 0;
}
