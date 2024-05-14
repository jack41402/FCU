#include <iostream>
#include <stdlib.h>
#include "IQueue_D1271450.h" 

int main(void) {
  IQueue Q; // Declar a queue variable.
  int last, curr; // Variables to recore two adjacent coefficients. 
  int n,e; // Degree of the binomaial expression.
  int i, k; // Loop variables. 
	
  do {
    do {
      printf(">>>> Enter an integer n (0<=n<=20, stop when n<0): "); 
      scanf("%d", &n); 
      if (n<0) return 0; // If n==0, stop the program. 
    } while (n>20); 
    Q.clear();
    k=0;
    if(k<=n){
    	last=0;
    	i=0;
	}
	else {
			for(k=0;k<=n;++k){
			last=1;
		    printf("&d\n",last);
		    Q.enqueue(last);
		}
		printf("\n");
		while(i<k){
			for(i=1;i<=n-k;++i){
			curr=Q.dequeue();
	 	    printf("&d", last+curr);
	 	    e=last+curr;
		    Q.enqueue(e);
		    last=curr;
		}
		printf("\n");
		}
	Q.clear();
	}
    
    // ***** Implement YangHui Triangle algorithm.
	 
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

