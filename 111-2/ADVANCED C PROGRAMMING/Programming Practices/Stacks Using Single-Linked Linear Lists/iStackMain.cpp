#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IStack.h" 

int main() {
	IStack S;
  	int trial_count; // Trial count;
  	int push_count; // Number of push opearation each trial.
  	int pop_count; // Number of pop opearation each trial.
  	int i, j; // Loop variable.
  	
  	srand(time(NULL)); // Seed of random number generator.
	
  	trial_count = rand() % 10 + 1; // Trial count, at most 10 trials.
  	printf("Trial count: %d\n\n", trial_count); // Print trial count.
	
  for (i=0; i<trial_count; i++) {
    printf(">>>> Trial %d: push and pop operations\n", i+1);

    push_count = rand() % 100 + 1; // Number of push operations.
    printf("Push %d elements to the stack.\n", push_count);
    for (j=0; j<push_count; j++) S.push(rand()%100); // Push elements to the stack.
    printf("Current satck size: %d. Content of stack from top to bottom:\n", S.getSize());
    S.printTopToBottom(); // Print elements from top to bottom.	

    pop_count = rand() % S.getSize(); // Number of pop operations.
    printf("\n\nPop %d elements to the stack.\n", pop_count);
    for (j=0; j<pop_count; j++) S.pop(); // Push elements to the stack.
    printf("Current satck size: %d. Content of stack from top to bottom:\n", S.getSize());
    S.printTopToBottom(); // Print elements from top to bottom.
    
    printf("-------------------------------------------------------------------\n\n"); // Print separate line.
  } 
	
  return 0; 	 
}
