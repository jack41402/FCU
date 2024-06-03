#include <iostream>
#include "IQueue.h"
#include <cstdlib>
#include <ctime>   
using namespace std;

int main() {
    
    int trail;
    int enqueue, dequeue;
    int elem;
	srand(0);
    trail  = rand() % 10 + 1;
    IQueue queue;
   	cout << "Trial count: " << trail <<endl;
    for (int i = 0; i < trail; ++i) {
        enqueue = rand() % 100;
        cout << "\n>>>>Trial " << i + 1 << ": enqueue and dequeue operations"<<endl;
        cout << "Enqueue " <<  enqueue << " elements to the queue."<<endl;
		for (int j = 0; j < enqueue; ++j) {
            elem = rand() % 100; 
            queue.enqueue(elem);
        }
        cout << "Current queue size: " << queue.getSize() << ". Content of the queue from head to tail:"<<endl; 
        queue.printHeadToTail();
        
        dequeue = rand() % queue.getSize();
        cout << "\n\nDequeue " <<  dequeue << " elements to the queue."<<endl;
        for (int j = 0; j < dequeue; ++j) {
            queue.dequeue();
        }
		cout << "Current queue size: " << queue.getSize() << ". Content of the queue from head to tail"<<endl; 
        queue.printHeadToTail();
        cout << "------------------------------------------------------------------\n"<< endl;
    }

    return 0;
}

