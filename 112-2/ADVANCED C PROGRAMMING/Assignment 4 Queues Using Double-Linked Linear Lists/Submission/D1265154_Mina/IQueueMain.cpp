#include <iostream>
#include <ctime>
#include <cstdlib>
#include "IQueue.h"

using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));// Seed the random number generator with the current time.
	int count = rand()%10+1;// Generate a random count for the number of trials.
	int insert_num, delete_num;
	int i, j;
	IQueue Q;

	cout << ">>>> Trial count: " << count << endl << endl; 
	for(i=1;i<=count;i++){
		cout << "Trial " << i << ": enqueue and dequeue operations" << endl; 
		insert_num = rand()%99+2;// Display the number of elements to enqueue.
		cout << "Enqueue " << insert_num << " elements to the queue." << endl; 
		for(j=1;j<=insert_num;j++) Q.enqueue(rand()%99+1);
		cout << "Current queue size: " << Q.getSize() << ". Content of queue from head to tail:" << endl; 
		Q.printHeadToTail();
		if(Q.getSize()%20 != 0) cout << endl << endl << endl;
		else cout << endl << endl;
		
		do{
			delete_num = rand()%100+1;// Generate a random number of elements to dequeue.
		}while(delete_num >= insert_num);
		cout << "Dequeue " << delete_num << " elements to the queue." << endl; 
		for(j=1;j<=delete_num;j++) Q.dequeue();
		cout << "Current queue size: " << Q.getSize() << ". Content of queue from head to tail:" << endl;
		Q.printHeadToTail();
		if(Q.getSize()%20 != 0) cout << endl;
		cout << "-----------------------------------------------------------------------------------" << endl << endl;
	}
	
	return 0;
}
