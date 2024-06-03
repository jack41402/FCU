#include <iostream>
#include <ctime>
#include <cstdlib>
#include "IQueue.h"

using std::cout;
using std::endl;
using std::rand;

int main() {
    srand(static_cast<unsigned int>(time(NULL)));//generate random number
    int T_count = rand() % 10 + 1;//T_count as a random number between 1 and 10    
    cout << "Trial count: " << T_count << "\n" << endl;//print out Trial count: then the number of the trial count, go to the next line
    for (int i = 1; i <= T_count; ++i) {//run the code from one till the number of T_count
        cout << ">>> Trial " << i << ": enqueue and dequeue operations" << endl;//print >>>>Trial, the number of the trial count : enqueue and dequeue operations
        IQueue queue;//define an instance for the queue
        int en = rand() % 99 + 1; //random number between 1 and 100
        int de = rand() % (en-1) + 1; //random number between 1 and en minus one
        
        cout << "Enqueue " << en << " elements to the queue." << endl;//print Enqueue, the number of en, elements to the queue.
        for (int j = 0; j < en; ++j) {//run the code from 0 to the number of en
            queue.enqueue(rand() % 100); //enqueue random elements
        }
        cout << "Current queue size: " << queue.getSize() << " Content of queue from head to tail:" << endl;//print out Current queue size: the size of enqueue Content of queue from head to tail:
        queue.printHeadToTail();//print out the queue
        
        cout << "\n\nDequeue " << de << " elements from the queue." << endl;//go to the line after that, then print Dequeue the number of de, elements from the queue
        for (int j = 0; j < de; ++j) {//run the code from 0 to the number of de
            queue.dequeue(); // Dequeue elements
        }
        cout << "Current queue size: " << queue.getSize() << " Content of queue from head to tail:" << endl;//print Current queue size: the size of dequeue, Content of queue from head to tail:
        queue.printHeadToTail();//print out the queue
        cout << "--------------------------------------------------------------\n\n";//print -------------------------------------------------------------- go to the line after that
    }

    return 0;
}

