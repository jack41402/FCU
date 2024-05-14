#include <iostream>
#include <stdlib.h>
#include "IQueue_D1265315.h.h" 

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
	if(k<=n){
	last =0;
	i = 0;
	if(i<k){
		curr = Q.dequeue();
		printf("%d %d",last,curr);
		Q.enqueue(last+curr);
		last = curr;
		i = i+1; 
	}
	else{
		last = 1;
		printf("%d-------------------------------\n",last);
		Q.enqueue(last);
		k = k+1;
	}
}
	Q.clear();
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

