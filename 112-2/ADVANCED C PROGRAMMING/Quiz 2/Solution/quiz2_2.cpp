#include <iostream>
#include <stdlib.h>
#include "IQueue.h" 

int main(void) {
  IQueue Q; // Declar a queue variable.
  int last, curr; // Variables to recore two adjacent coefficients. 
  int n; // Degree of the binomaial expression.
  int i, k; // Loop variables. 
	
  do {
    do {
      printf(">>>> Enter an integer n (0<=n<=20, stop when n<0): "); 
      scanf("%d", &n); 
      if (n<0) return 0; // If n==0, stop the program. 
    } while (n>20); 
	
    Q.clear(); // Reset Q to empty. 

    for (k=0; k<=n; k++) { // Print binominal coefficient for k from 0 to n. 
      last = 0; // Set last to 0 
      for (i=0; i<k; i++) { // Print k corfficient.    
        curr = Q.dequeue(); // Dequeue an element from Q.
        printf("%3d ", last+curr); // Print a coefficient.
        Q.enqueue(last+curr); // Enqueue this coefficient to Q.
        last = curr; // Set curr to be last. 
      }
      last = 1; // Print coefficient 1.
      printf("%3d \n", last); // Print 1 and a newline.
      Q.enqueue(last); // Enqueue this coefficient to Q.	
    }
    Q.clear(); // Clear Q. 
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

