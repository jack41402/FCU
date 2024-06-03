#include <iostream>
#include <stdlib.h>
#include "IQueue_D1262058.h" 

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
//    1. Clear Q;
	Q.clear();
//2. Set k to 0;
	k = 0;
	if(k<n){
//3. If k.n, then
//3.1. Set last and i to 0;
 		i = 0;
 		last = 0;
 		if(k<n){
 			curr = Q.dequeue();
 			printf("%3d", last + curr);
 			Q.enqueue(last + curr);
 			last = curr;
 			i++;
//3.2. If i<k, then
//3.2.1 Set curr = dequeue(Q);
//3.2.2 Print last+curr;
//3.2.3 enqueue(Q, last+curr);
//3.2.4 Set last to curr;
//3.2.5 Increment i by 1;
//3.2.6 Go to Step 3.2;
 		}
		else{
 			last = 1;
 			printf("%3d\n", last);
 			Q.enqueue(last);
 			k++;
//3.3 else,
//3.3.1. last = 1;
//3.3.2. print last and a newline;
//3.3.3. enqueue(Q, last);
//3.3.4. Increment k by 1;
//3.3.5. Go to Step 3;
 		}
	}
	else{
//4. else clear Q.
		Q.clear();
	}	
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 

