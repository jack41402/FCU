#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack_dynamic_array.h"

int main(void) {
  Stack S; // Declare a stack. 
  int trial_count; // Trial count.
  int push_count; // Number of elements to be inserted in a trial. 
  int pop_count; // Number of elements to be removed in a trial. 
  int i, j; // Loop variable. 
	
  initial(&S); // Initialize S.
	
  srand(time(NULL)); // Seed of random runmber generator.
	
  trial_count = rand() % 10 + 1; // Random trial count, maximum 10 trials.
  printf("Trial count: %d\n\n", trial_count); // Print trial count. 
	
	for (i=0; i<trial_count; i++) {
		printf(">>>> Trial %d:\n", i+1);
		push_count = rand() % 100 + 1; // Number of elements to be inserted, maximum 100.
		printf("Insert %d elements to stack S. Content of stack S after inserting elements£º\n", push_count);
		for (j=0; j<push_count; j++) push(&S, rand()%100); // Insert elements to stack S.
		print_stack(S); // Print stack S from bottom to top.
		
		pop_count = rand() % get_size(S) + 1; // Number of elements to be removed, maximum current stack size.
		printf("Remove %d elements to stack S. Content of stack S after removing elements£º\n", pop_count);
		for (j=0; j<pop_count; j++) pop(&S); // Remove elements from stack S.
		print_stack(S); // Print stack S from bottom to top. 
		printf("-------------------------------------------------------------------\n"); // ´òÓ¡·Ö¸ôÏß¡£		
	} 
	
  return 0; 
}
