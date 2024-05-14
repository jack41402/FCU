#include <iostream>
#include <stdlib.h>
#include<iomanip>
#include "IQueue_D1228817.h" 
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
    
    Q.clear();//1
    k=0;//2
    
 	while(k<=n){
 	//3
 	
    	last=i=0;//3.1
    	
    	//3.2
    		
    		while(i<k){
    			
    		curr=Q.dequeue();
    		cout<<setw(4)<<last+curr;
    		Q.enqueue(last+curr);
    		last=curr;
    		i+=1;
    		//go to step 3.2
    		
			}
    		
		
		if(i>=k){//3.3
			last=1;
			cout<<setw(4)<<last<<endl;
			Q.enqueue(last);
			k+=1;
			//go to step 3
		}
	
}
	
	
		Q.clear();//4
	
	 
 	
   
    
	
    

	 
    printf("-------------------------------\n"); // Print a separate line. 
  } while (1); // Continue the loop. 
  


} 

