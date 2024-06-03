#include "IQueue.h"
#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand(time(0));//so the number will be different every time
	IQueue q;
	int i, enNum, deNum;
    int trial = rand() % 10 + 1;//random number between 1 to 10

	printf("Trial count: %d\n\n", trial);
	
    for(i = 1; i <= trial; i++) {
        cout << ">>>> Trial " << i << ": enqueue and dequeue operations\n";
        enNum = rand() % 99 + 1;//random number between 1 to 99
        cout << "Enqueue " << enNum << " elements to the queue.\n";
        while(enNum--) {
            q.enqueue((rand() % 99 + 1));
        }
        q.printHeadToTail();
        printf("\n\n");

        deNum = rand() % q.getSize() + 1;//random number between 1 to the size of the queue
        cout << "Dequeue " << deNum << " elements to the queue.\n";
        while(deNum--) {
            q.dequeue();
        }
        q.printHeadToTail();
        cout << "------------------------------------------------------------------\n\n";
    }
}
