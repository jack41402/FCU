#include <stdio.h>

int main(void) {
	int operand1=0, operand2 , result=0 ; // The first and the secod operand. 
	int i, j; // Loop variables.
	
	// ***** Complete program of the following steps£º 
	// Input the second operand, a two-digit non-zero octal number. 
	printf ("Enter a two-digit non-zero octal number for the 2nd operand: ") ;
	scanf ("%o" , &operand2) ;
	printf ("%d\n" , operand2) ;
	printf ("Two-digit Octal Multiplication Table in Vertical Format:\n\n") ;
	// Print the two-digit octal multiplication table in the vertical format
	for (i=1 ; i<=8 ; ++i)
	{
		for (j=1 ; j<=8 ; ++j) printf ("      %2o" , operand1++) ;
		printf ("\n") ;
		for (j=1 ; j<=8 ; ++j) printf ("   x  %2o" , operand2) ;
		printf ("\n") ;
		for (j=1 ; j<=8 ; ++j) printf ("  ------") ;
		printf ("\n") ;
		for (j=1 ; j<=8 ; ++j) printf ("    %4o" , result++*operand2) ;
		printf ("\n\n") ;
	}
  return 0;
}
