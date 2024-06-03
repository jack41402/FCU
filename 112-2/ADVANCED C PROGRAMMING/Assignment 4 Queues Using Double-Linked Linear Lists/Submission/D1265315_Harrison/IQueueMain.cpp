#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include "IQueue.h"
using namespace std;

int main(){
	int i, j, a;
	int trial;
	int enq, deq;// Number of enqueue and dequeue opearation each trial.
    int size;
	IQueue Q;
	
	srand(time(NULL));
	trial = rand() % 10 + 1;
	
	cout<<"Trial count: "<<trial<<"\n\n";	
	for(a=0; a<trial; a++){
		//enqueue
		enq = rand() % 100 + 1;
		cout<<">>>> Trial "<<a+1<<": enqueue and dequeue operations\n";
		for(i=0; i<enq; i++){
			Q.enqueue(rand()%100);
		}
		cout<<"Enqueue "<<enq<< " elements to the queue.\n";
		cout<<"Current queue size: "<<Q.getSize()<<" Content of queue from head to tail:\n";
   		Q.printHeadToTail();
   		
		//dequeue
		deq = rand() % Q.getSize();
		cout<<"\n\nDequeue "<<deq<<" elements to the queue.\n";
    	for (j=0; j<deq; j++) Q.dequeue();
    	cout<<"Current queue size: "<<Q.getSize()<< ". Content of queue from head to tail:\n";
   		Q.printHeadToTail();
		cout<<"-------------------------------------------------------------------\n\n";	
	}
	return 0;
}
