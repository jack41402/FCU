#include <iostream>
#include <cstdlib>
#include<ctime>
#include"IQueue.h"
using namespace std;

void Trial(IQueue *queue, int trial_cnt){//Perform enqueue and dequeue for one trial
	int i;//Loop variable
	cout<<endl<<">>>> Trial "<<trial_cnt<<": enqueue and dequeue operations"<<endl;
	int in = rand()%99+1;//Let the elements to be enqueued in each trial be between 1 and 99 
	int out = rand()%(in-1)+1;//Let the elements to be enqueued in each trial be between 1 and "in" 
	
	cout<<"Enqueue "<<in<<" elements to the queue."<<endl;
	
	for(i=0; i<in; i++){
		queue->enqueue(rand()%99+1);//Enqueue an element with a value between 1 and 99. 
	}
	
	cout<<"Current queue size: "<<queue->getSize()<<". Content of queue from head to tail:"<<endl;
	queue->printHeadToTail();
	
	cout<<endl<<endl<<endl<<"Dequeue "<<out<<" elements to the queue."<<endl;
	
	for(i=0; i<out; i++){
		queue->dequeue();//Dequeue and element
	}
	cout<<"Current queue size: "<<queue->getSize()<<". Content of the queue from head to tail:"<<endl;
	queue->printHeadToTail();
	
	cout<<endl<<"-------------------------------------------------------------------"<<endl<<endl;
	
	
}

int main() {
	
	srand(time(NULL));
	IQueue queue;
	
	int trial=rand()%10+1;//Set the number of trials to be an integer value between 1 and 10
	int i;//Loop variable
	
	cout<<"Trial count: "<<trial<<endl<<endl;
	for(i=1; i<=trial; i++){
		Trial(&queue, i);
	}
	
	return 0;
}
