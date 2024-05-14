#include <iostream>
#include <stdlib.h>
#include "IQueue_D1172268.h" 

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
	k = 0;
	while(k <= n) {
		i = 0;
		last = 0;
		while(i < k){
			curr = Q.dequeue();
			printf("%3d ", last + curr);
			Q.enqueue(last + curr);
			last = curr;
			i++;
		}
		if(i >= k){
			last = 1;
			printf("%3d \n", last);
			Q.enqueue(last);
			k++;
		}
	}
	if(k > n) Q.clear();
	
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

