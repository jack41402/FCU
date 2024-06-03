#include <iostream>
#include <stdlib.h>
#include "IQueue_D1262062.h" 
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
    
	Q.clear();
	for(int k = 0; k<=n; k++){
		int i = 0;
		int last = 0;
		if(i<k){
			curr = Q.dequeue();
			cout << last + curr;
			Q.enqueue(last + curr);
			last = curr;
			i++;
		}
		else{
			last = 1;
			cout << last << endl;
			Q.enqueue(last);
			k++; 
		}
	}
    // ***** Implement YangHui Triangle algorithm.
	Q.clear();
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

