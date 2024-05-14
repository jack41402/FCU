#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "IQueue_D1265672.h" 

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
    k = 0;
    do{
    	last = 0;
    	i = 0;
    	while (k>i){
    		curr = Q.dequeue();
    		std::cout << std::setw(3) << last + curr << " ";
    		Q.enqueue(last + curr);
    		last = curr;
    		i++;
		}
		last = 1;
		std::cout << std::setw(3) << last << std::endl;
		Q.enqueue(last);
		k++;
	}while (k <= n);
	Q.clear();
	 
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

