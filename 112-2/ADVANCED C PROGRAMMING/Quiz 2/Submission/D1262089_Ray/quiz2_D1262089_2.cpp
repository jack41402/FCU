#include <iostream>
#include <iostream>
#include <iomanip>
#include "IQueue_D1262089.h" 

int main(void) {
  IQueue Q; // Declar a queue variable.
  int last, curr; // Variables to recore two adjacent coefficients. 
  int n; // Degree of the binomaial expression.
  int i, k; // Loop variables. 
  using std::cout;
  using std::cin;
  using std::setw;
  using std::endl;
	
  do {
    do {
      cout<<">>>> Enter an integer n (0<=n<=20, stop when n<0): "<<endl; 
      cin>>n;
      if (n<0) return 0; // If n==0, stop the program. 
    } while (n>20); 
    
    // ***** Implement YangHui Triangle algorithm.
    
    Q.clear();

    k=0;
    if(k<=n){
    	i=0;
    	last=0;
    	if(i<k){
    	   curr = Q.dequeue();
    	   cout<<last+curr;
    	   Q.enqueue(last+curr);
    	   curr=last;
    	   i++;
	    }
    }else{
		last = 1;
		cout<<last<<endl;
		Q.enqueue(last);
		i++;
	}
    Q.clear();

    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
} 
