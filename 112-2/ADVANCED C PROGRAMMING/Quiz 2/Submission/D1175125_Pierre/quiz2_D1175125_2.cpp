#include <iostream>
#include <stdlib.h>
#include "IQueue_D1175125.h" 

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
	 for(i=0;i<=n;i++){
	 	last = 0;
	 	for(k=0;k<=1;k++){
	 		curr = Q.isEmpty() ? 0 : Q.dequeue();
	 		if(k==0||k==i)curr = 1;
	 		std::cout<<curr<<" ";
	 		Q.enqueue(last + curr);
	 		last = curr;
		 }
		 std::cout<<std::endl;
	 }
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

