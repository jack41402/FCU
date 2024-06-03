#include<iostream>
using std::cout;
#include"IQueue.h"
#include<time.h>
#include<stdlib.h>

int main(){
	IQueue Q;
	int enqueue_count;
	int dequeue_count;
	int trial_count;
	
	int i, j;
	srand(time(NULL));
	trial_count = rand()%10+1;
	cout<<"Trial count:" <<trial_count;
	
	for(i=0; i<trial_count; i++){
		cout<<"\n\n>>> Trial " <<i+1<<": enqueue and dequeue operations\n";
		enqueue_count = rand()%100+1;
		cout<<"Enqueue "<<enqueue_count<<" elements to the queue.\n";
		for(j=0; j<enqueue_count; j++)
			Q.enqueue(rand()%100);
		cout<<"Current queue size: "<<Q.getSize();
		printf(" Content of queue from head to tail:\n");
		Q.printHeadToTail();
		dequeue_count = rand()%Q.getSize();
		cout<<"\n\nDequeue "<<dequeue_count<<" elements to the queue.\n";
		for(j=0; j<dequeue_count; j++)
			Q.dequeue();
		cout<<"Current queue size: "<<Q.getSize();
		cout<<". Content of queue from head to tail: \n";
		Q.printHeadToTail();
		cout<<"------------------------------";	
	}
	
	return 0;
}



