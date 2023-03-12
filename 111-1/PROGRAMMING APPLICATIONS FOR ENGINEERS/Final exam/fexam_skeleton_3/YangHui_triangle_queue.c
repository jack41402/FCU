#include <stdlib.h>
#include <stdio.h>
#include "queue_fixed_array.h"

/*
Print Yang-Hui triangle for a non-negative integer n with a queue Q
Pseudo code:
  1. Initialize queue Q.
  2. Set k to 0.
  3. If k<=n,
    3.1. Set last = 0, i = 0;
    3.2 If i<k,
      3.2.1. curr = dequeue(Q);     
      3.2.2. Print last+curr;
      3.2.3. enqueue(Q, last+curr);
      3.2.4. last = curr;
      3.2.5. i=i+1;
      3.2.6. Go to Step 3.2;
    3.3. Otherwise,
      3.3.1. last = 1;
      3.3.2. Print last and a newline;
      3.3.3. enqueue(Q, last);
      3.3.4. k = k + 1;
      3.3.5. Go to step 3.
  4. Otherwise, clear queue Q.
*/

int main(void) {
    Queue Q; // Declare a queue.
    int last, curr; // Record the coefficients of Yang Hui's triangle. 
    int n; // n>=0. 
    int i, k; // Loop variable.
	
    do {
        printf(">>>> Enter an integer (0 to 19, stop when less 0):"); 
        scanf("%d", &n); 
    } while (n>19); 

    // ***** Complete the program.
    initial (&Q) ;
    for (k=0 ; k<=n ; ++k)
    {
    	for (i=0 , last=0 ; i<k ; ++i)
    	{
    		curr = dequeue (&Q) ;
    		printf ("%6d" , last+curr) ;
    		enqueue (&Q , last+curr) ;
    		last = curr ;
		}
		last = 1 ;
		printf ("%6d\n" , last) ;
		enqueue (&Q , last) ;
	}
	clear (&Q) ;
    return 0;
}
