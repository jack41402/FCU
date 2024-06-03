#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IQueue.h"

int main() {
	IQueue queue;//define a IQueue class 
	int i, j, k, e; //define the variables
	
	srand(time(NULL));//seed for random number generation
	int trials = rand() % 10 + 1;//random number of trials between 1 and 10

	for (i = 1; i <= trials; i++) {
		std::cout << ">>>> Trial " << i << ": enqueue and dequeue operations" << "\n";
		
		//enqueue operations
		int enqueues = rand() % 100 + 1;//random number of enqueues between 1 and 100
		std::cout << "Enqueue " << enqueues << " elements to the queue." << "\n";
		for (j = 0; j < enqueues; j++) {
			e = rand() % 99+1;//generate random numbers between 1 and 99
			queue.enqueue(e);
		}
		std::cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail:" << "\n";
		queue.printHeadToTail();
		
		//dequeue operation and ensure the number is less than the current queue size
		int dequeues = rand() % queue.getSize();//generate a number from 0 to size
		std::cout << std::endl << "Dequeue " << dequeues << " elements from the queue." << "\n";
		
		for (k = 0; k < dequeues; k++) {
			queue.dequeue();
		}

		std::cout << "Current queue size: " << queue.getSize() << ". Content of queue from head to tail:" << "\n";
		queue.printHeadToTail();
		std::cout << "------------------------------------------------" << "\n" << "\n";
	}
	return 0;
}

