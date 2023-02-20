#include <stdio.h>

// ***** Complete this function.
// Recursive factorial function k! for k>=0.
int factorial(int k) {
	if (k==0) return 1;
	else return k*factorial(k-1);
} 

// ***** Complete this function.
// Combination function C(n, k). 
int C(int n, int k) {
	return factorial(n)/(factorial(k)*factorial(n-k));
}

int main(void) {
	int n; // An integer between 0 and 10 (including).
	int i , j ;
	
	do {
		printf("Enter an integer between 0 and 10 (including): ");
		scanf("%d", &n);
	} while (n<0 || n>10);
	
	// ***** Complete the program.
	printf ("\nPascal Triangle, n=%d:\n\n" , n) ;
	for (i=0 ; i<=n ; ++i)
	{
		printf ("    ") ;
		for (j=0 ; j<=i ; ++j)
		{
			printf ("%4d" , C(i , j)) ;
		}
		printf ("\n") ;
	}
	return 0;
}
