#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "IQueue.h" // Include the header file for the custom integer queue class

using namespace std;

int main() {
    // Create an integer queue object
    IQueue queue;

    // Set the seed for random number generation using the current time
    srand(time(NULL));

    // Declare variables
    int i, k, TrialCount, enCount, deCount, currentSize;

    // Prompt the user to input the number of trials
    cout << "Trial count: ";
    cin >> TrialCount;

    // Validate that the trial count is within a reasonable range
    while (TrialCount < 1 || TrialCount > 10) {
        cout << "Wrong trial count, please enter again(1~10)!!!\n";
        cout << "Trial count: ";
        cin >> TrialCount;
    }

    // Iterate through the trials
    for (i = 1; i <= TrialCount; i++) {
        // Get the current size of the queue
        currentSize = queue.getSize();

        // Generate random enqueue and dequeue counts
        enCount = rand() % 100 + 1;
        deCount = rand() % enCount + 1;

        // Display detailed information about the current trial
        cout << "\n>>>> Trial " << i << ": enqueue and dequeue operations\n";
        cout << "Enqueue " << enCount << " elements to the queue.\n";
        cout << "Current queue size : " << enCount + currentSize << ". Content of queue from head to tail:\n";

        // Iterate through enqueue operations and add elements to the queue
        for (k = 0; k < enCount; k++) {
            queue.enqueue(rand() % 99 + 1);
        }

        // Print the content of the queue
        queue.printHeadToTail();

        cout << "\n\n\nDequeue " << deCount << " elements to the queue.\n";
        cout << "Current queue size : " << enCount + currentSize - deCount << ". Content of queue from head to tail:\n";

        // Iterate through dequeue operations
        for (k = 0; k < deCount; k++) {
            queue.dequeue();
        }

        // Print the content of the queue
        queue.printHeadToTail();

        cout << "\n----------------------------------------------------------------------\n";
    }

    return 0;
}

