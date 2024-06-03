#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "IQueue.h"
using namespace std;
int main(){
	IQueue queue;
	srand(time(NULL));
	int i,k,n,enqueueCount,dequeueCount,currentSize;
	n = rand()%10+1;
	cout<<"Trial count: "<<n;//generate n randly;
	for(i=1;i<=n;i++){
		currentSize = queue.getSize();//generate currentSize randly;
		enqueueCount = rand()%100+1;//generate enqueueCount randly;
		
		//enqueue
		cout<<"\n>>>> Trial "<<i<<": enqueue and dequeue operations\n";
		cout<<"Enqueue "<<enqueueCount<<" elements to the queue.\n";
		cout<<"Current queue size : "<<enqueueCount+currentSize<<". Content of queue from head to tail:\n";
		for(k=0;k<enqueueCount;k++){
			queue.enqueue(rand()%99+1);
		}
		queue.printHeadToTail();
		
		//dequeue
		dequeueCount = rand()%queue.getSize();//generate dequeueCount randly;
		cout<<"\n\n\nDequeue "<<dequeueCount<<" elements to the queue.\n";
		cout<<"Current queue size : "<<enqueueCount+currentSize-dequeueCount<<". Content of queue from head to tail:\n";
		for(k=0;k<dequeueCount;k++){
			queue.dequeue();
		}
		queue.printHeadToTail();
		
		cout<<"\n----------------------------------------------------------------------\n";
	}
	return 0;
}
