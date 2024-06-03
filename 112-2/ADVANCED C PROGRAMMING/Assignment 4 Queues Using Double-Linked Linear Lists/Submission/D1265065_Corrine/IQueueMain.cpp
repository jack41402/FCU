//
//  main.cpp
//  Assignment_4_D1265065
//
//  Created by Corrine  on 2024/4/29.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "IQueue.h"
using namespace std;
int main() {
    srand(time(NULL));//seed the random number generator to ensure different sequences of random numbers on each program run.
    int trial_count= rand() % 10 + 1;// Generate a random number between 1 and 10 to determine the number of trials
    IQueue queue;
    cout << "Trial count: " << trial_count << endl;// Print the number of trials
    // Loop through each trial
    for (int i = 1; i <= trial_count; i++){
        int enqueues = rand() % 100 + 1;// Generate a random number of elements to enqueue
        int dequeues = rand() % enqueues;// Generate a random number of elements to dequeue, ensuring it's less than or equal to the number of enqueued elements
        // Print information about the current trial
        cout << ">>>> Trial " << i << ": enqueue and dequeue operations" << endl;
        cout << "Enqueue " << enqueues << " elements to the queue." << endl;
        int prevSize = queue.getSize();// Store the size of the queue before enqueuing new elements
        for (int j = 0; j < enqueues; j++) {// Enqueue new random elements
                    queue.enqueue(rand() % 100); // Assuming integers from 0 to 99
                }
        // Print the current queue size and its contents from head to tail
        cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail." << endl;
        queue.printHeadToTail();
        cout << endl << endl;
        // Dequeue random elements from the queue
        cout << "Dequeue " << dequeues << " elements to the queue." << endl;
        for (int j = 0; j < dequeues; j++){
            queue.dequeue();
        }
        // Print the current queue size and its contents after dequeue operations
        cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail." << endl;
        queue.printHeadToTail();
        for(int j = 0; j <= 66; j++) cout << "-" ;
        cout << endl << endl;
    }
    return 0;
}
