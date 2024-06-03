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
    
    // ***** Implement YangHui Triangle algorithm.
	 Q.clear();
	 k=0;
	 if (k<=n){
	 	last = 0;
	 	i = 0;
	 	if (i<k){
	 		curr = Q.dequeue;
	 		std::cout<<last+curr;
	 		Q = Q.enqueue(last + curr);
	 		last = curr;
	 		i++;
		 }
		else{
	 		last = 1;
	 		std::cout<<last<<"\n";
	 		Q = Q.enqueue(last);
	 		k++;
	 	}
	 	else{
	 		Q.clear(); 
		 }
	 }
	 
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

