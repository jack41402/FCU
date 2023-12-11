#include <stdio.h>
#include <math.h>

int main(void) {
	int n; // Number of coefficients of a linear equation.
	int coeff[10]; // Maximum 10 coefficients.
	int c; // Constant term.
	int i; // Loop variables.
	
	do {
		int leading_term=0 , space=0; // Flag to indicate whether a leading term or not. 
		// Input the number of variables, n.
		printf("Enter the number of coefficients (1 to 10): "); // Print a message.
		scanf("%d", &n); // Number of coefficients of a linear equation.
		if (n==0) return 0; // Program terminates, if n is 0.
		
		// ***** Complete program of the following steps:
		// Input n integers of the coefficients and a constant term.
		for (i=1 ; i<=n ; ++i)
		{
			printf ("Enter coefficient a%d: " , i) ;
			scanf ("%d" , &coeff[i-1]) ;
		}
		printf ("Enter constant term: ") ;
		scanf ("%d" , &c) ;
		printf ("The linear equation of %d variable%s is:\n" , n , (n>1) ? "s" : "") ;
		// Print the linear equation with the pretty printing format, 
		// i.e., not printing zero coefficient terms, not printing 
		// coefficient of value 1 or -1, and not printing "+" sign 
		// for a negative coefficient.
		for (i=0 ; i<n ; ++i)
		{
			if (coeff[i]==0) continue ;
			if (!space) printf ("    ") , space = 1 ;
			if (!leading_term && coeff[i]<0) printf ("-") ; 
			if (leading_term) printf (" %s" , (coeff[i]>0) ? "+" : "-") ;
			if (coeff[i]!=1 && coeff[i]!=-1) printf (" %d " , abs(coeff[i])) ;
			printf ("%sX_%d" , (leading_term&&abs(coeff[i])==1) ? " " : "" , i+1) ;
			if (coeff[i]!=0) leading_term = 1 ;
		}
		// Check invalid linear equation when there is no non-zero coefficient.
		if (!leading_term) printf ("**** Not a linear equation. No non-zero coefficients.\n") ;
		else printf (" = %d\n" , c) ;
		printf("\n----------------------------------\n");
	} while (1);
}

