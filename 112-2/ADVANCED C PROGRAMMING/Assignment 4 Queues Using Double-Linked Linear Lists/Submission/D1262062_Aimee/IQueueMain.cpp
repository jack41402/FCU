#include <iostream>
#include <ctime>
#include <cstdlib>
#include "IQueue.h"
#include "Node.h" 

using namespace std;

int main() {
	IQueue iqueue;
	srand(time(NULL));
	int trialCount = rand() % 10 + 1;
	cout << "Trial count: " << trialCount << endl; 
	for(int i = 1; i<=trialCount; i++){
		int enqueue = rand() % 100 + 1;
		int dequeue = rand() % enqueue;
		cout << "\n\n>>>> Trial " << i << ": enqueue and dequeue operatons" << endl;
		for(int j = 0; j<enqueue; j++){
			int data = rand() % 100;
			iqueue.enqueue(data);
		}
		cout << "Enqueue " << enqueue << " elements to the queue." << endl;
		cout << "Current queue size:" << iqueue.getSize() << ". Content of queue form head to tail:" << endl;
		iqueue.printHeadToTail();
		for(int k = 0; k<dequeue; k++){
			iqueue.dequeue();
		}
		cout << "\n\nDequeue " << dequeue << " elements to the queue." << endl;
		cout << "Current queue size:" << iqueue.getSize() << ". Content of queue form head to tail:" << endl;
		iqueue.printHeadToTail();
		for(int m = 0; m<=66; m++) cout << "-";
	}
	return 0;
}
