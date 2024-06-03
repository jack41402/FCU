#include <iostream>
#include<time.h>
#include "IQueue.h"
#define N 20
#define Mod 100
using namespace std;
int main() {

	int n;
	printf("Trial count: ");
	cin >> n;
	IQueue list = IQueue();

	srand(0);
	for(int i=1;i<=n;i++){
		cout << endl;
		printf(">>>> Trial %d:enqueue and dequeue operations\n", i);
		int m = rand() % N+1;
		printf("Enqueue %d elements to the queue.\n",m);
		for (int j = 0; j < m; j++) {
			int elem = rand() % Mod;
			list.enqueue(elem);
		}
		printf("Current queue size: %d. Content of queuefrom head to tail:\n", list.getSize());
		list.printHeadToTail();

		printf("\n");
		//É¾³ýÔªËØ
		int de = rand() % m;
		printf("Dequeue %d elements to the queue.\n",de);
		while (de--) list.dequeue();
		printf("Current queue size: %d. Content of queuefrom head to tail:\n", list.getSize()); 
		list.printHeadToTail();
	}
	return 0;

}
