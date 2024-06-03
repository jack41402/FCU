#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IQueue.h" 

int main(){
	IQueue Q;
	int trail_count;
	int enqueue;
	int dequeue;
	int i,j;
	
	srand(time(NULL)); 
	trail_count = rand()%10 + 1;
	printf("Trail count : %d\n\n",trail_count);
	for(i=1;i<=trail_count;i++){
		std::cout << ">>>> Trial " << i << ": enqueue and dequeue operations\n";
		enqueue = rand()%100 + 1;
		std::cout << "Enqueue " << enqueue << " elements to the queue." << std::endl;
		for(j=0;j<enqueue;j++) Q.enqueue(rand()%100);
		std::cout << "Current queue size: " << Q.getSize() << ". Content of queue from head to tail:" << std::endl;
		Q.printHeadToTail();
		
		dequeue = rand()% Q.getSize();
		std::cout << std::endl << std::endl << "Dequeue " << dequeue << " to the queue." <<std::endl;
		for(j=0;j<dequeue;j++) Q.dequeue();
		std::cout << "Current queue size: " << Q.getSize() << ". Content of queue from head to tail:" <<std::endl; 
		Q.printHeadToTail();
		
		std::cout << "-------------------------------------------------------------------------------" << std::endl; 
	} 
	return 0; 
} 
