#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IQueue.h" 

int main() {
	IQueue Q;
  	int trial_count; // Trial count;
  	int enqueue_count; // Number of enqueue opearation each trial.
  	int dequeue_count; // Number of dequeue opearation each trial.
  	int i, j; // Loop variable.
  	
  	srand(0); // Seed of random number generator.
	
  	trial_count = rand() % 10 + 1; // Trial count, at most 10 trials.
  	printf("Trial count: %d\n\n", trial_count); // Print trial count.
	
  for (i=0; i<trial_count; i++) {
    printf(">>>> Trial %d: enqueue and dequeue operations\n", i+1);

    enqueue_count = rand() % 100 + 1; // Number of enqueue operations.
    printf("Enqueue %d elements to the queue.\n", enqueue_count);
    for (j=0; j<enqueue_count; j++) Q.enqueue(rand()%100); // Push elements to the stack.
    printf("Current queue size: %d. Content of queue from head to tail:\n", Q.getSize());
    Q.printHeadToTail(); // Print elements from head to tail.	

    dequeue_count = rand() % Q.getSize(); // Number of dequeue operations.
    printf("\n\nDequeue %d elements to the queue.\n", dequeue_count);
    for (j=0; j<dequeue_count; j++) Q.dequeue(); // Push elements to the stack.
    printf("Current queue size: %d. Content of queue from head to tail:\n", Q.getSize());
    Q.printHeadToTail(); // Print elements from head to tail.	
    
    printf("-------------------------------------------------------------------\n\n"); // Print separate line.
  } 
	
  return 0; 

	 
}
