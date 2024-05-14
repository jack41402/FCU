#include <iostream>
#include <stdlib.h>
#include "IQueue_D1265154.h" 
using namespace std;
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
if(k<=n){
   	last=0;
   	for(i=0;i<k;i++){
   	//	curr = dequeue(Q);
   		printf("last+curr;");
   	//	enqueue(Q, last+curr);
   		last = curr;
	   }
	   
	   }
   
   
   
  
	 
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

