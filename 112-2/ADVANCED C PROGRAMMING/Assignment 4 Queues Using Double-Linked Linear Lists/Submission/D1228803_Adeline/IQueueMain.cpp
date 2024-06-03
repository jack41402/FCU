//IQueueMain.cpp
#include "IQueue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

int main() 
{
    std::srand(static_cast < unsigned int > (std::time(NULL))); //seed random generator
    IQueue queue;
    int i, j; //loop variable
    int value; //current element being processed
    int enqueueCount; //random value between 1 and 10
 	int dequeueCount; //random value between 0 and the current size of the queue
    int trials; //determine how many trials or iterations of enqueue and dequeue operations will be performed
 	trials = std::rand() % 10 + 1;
    std::cout << "Trial count: " << trials << std::endl; //print out Trail count

 
    for (i = 0; i < trials; ++i) //execute the enqueue and dequeue inside its body trials times
    {
        enqueueCount = std::rand() % 100 + 1; //generates a random number between 1 and 10
        dequeueCount = std::rand() % (queue.getSize() + 1); //generates a random number between 0 and the current size of the queue
        //prints a message indicating the current trial number along with enqueue and dequeue
  		std::cout << "\n>>>> Trial " << i + 1 << ": enqueue and dequeue operations" << std::endl;

        //enqueue elements
        //indicating the number of elements being enqueued to the queue in the current trial
        std::cout << "Enqueuing " << enqueueCount << " elements to the queue." << std::endl;
        for (j = 0; j < enqueueCount; ++j) //enqueue elements to the queue
        {
            value = std::rand() % 100; //generates a random integer and calculates the remainder when divided by 100
            queue.enqueue(value); //adds the generated value to the queue 
        }
        //print the current size of the queue followed by its content from head to tail
        std::cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail: " << std::endl;
        queue.printHeadToTail();

        // dequeue elements
        //indicating the number of elements being dequeued to the queue in the current trial
        std::cout << "Dequeuing " << dequeueCount << " elements from the queue." << std::endl;
        for (j = 0; j < dequeueCount; ++j) //dequeue elements to the queue
        {
            if (!queue.isEmpty()) //checks if the queue is empty 
            {
                value = queue.dequeue(); //dequeues an element from the queue and assigns it to value
                std::cout << value << " "; //print space
            } 
            else 
            {
                std::cout << "Queue is empty!"; //print out Queue is empty
            }
        }
        
        //print the current size of the queue followed by its content from head to tail
        std::cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail: " << std::endl;
        std::cout << std::endl;
        queue.printHeadToTail();

        std::cout << "-------------------------------------------------------------------" << std::endl;
    }

    return 0;
}
