#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "IQueue_D1228792.h" 
using namespace std;
int main(void) {
  IQueue Q; // Declare a queue variable.
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
	while(k<=n){
		last = 0;
		i = 0;
		while(i<k){
			curr = Q.dequeue();
			cout<<setw(4)<<last+curr;
			Q.enqueue(last+curr);
			last = curr;
			i++;
		}
		last = 1;
		cout<<setw(4)<<last<<"\n";
		Q.enqueue(last);
		k++;
	}
	Q.clear();
	
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

