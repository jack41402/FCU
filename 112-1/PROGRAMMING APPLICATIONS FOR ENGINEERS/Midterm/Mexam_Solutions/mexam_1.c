#include <stdio.h>

int main(void) {
	int n; // Rank of a linear equation system.
	int A[9][9]; // Maximum 9 coefficients for each of maximum 9 equations.
	int C[9]; // Maximum 9 constants.
	int non_zero_coeff; // Flag to indicate a non_zero coefficient in an equation or for a variable.
	int leading_term; // Flag to indicate whether a leading term or not. 
	int i, j; // Loop variables.
	
	do {
		do {
			printf("Enter the rank of linear equation system (1 to 9 and 0 to stop): "); // Print a message.
			scanf("%d", &n); // Number of coefficients of a linear equation.
		} while (n<0 || n>9);
		if (n==0) return 0; // Program terminates, if n is 0.
		for (i=0; i<n; i++)	{
			// Message to enter coefficients and constant for Equation i.
			printf(">>>> Enter %d coefficients and a constant for Equation %d (between -99 and 99): ", n, i);
			for (j=0; j<n; j++) // Enter n coefficients Equation i.	
				scanf("%d", &A[i][j]); // Enter coefficient A[j] for Equation i.
			scanf("%d", &C[i]); // Enter constant C[i].
		}
		
		// Verify whether there is no equation with all zero coefficients.
		for (i=0; i<n; i++) {
			non_zero_coeff = 0; // Assume all coefficients of Equation i are zeros. 
			for (j=0; j<n; j++) if (A[i][j]!=0) non_zero_coeff = 1; // A coefficient is not zero.
			if (non_zero_coeff==0) {
				printf("\n<<<< Coefficients of Equation %d are all zeros. Stop!\n", i);
				break;
			}
		}
		
		// Verify whether there is no variable Xj with all zero coefficients.
		if (non_zero_coeff) { // Continue to check not all coefficients of variable are zeros.  
			for (j=0; j<n; j++) {
				non_zero_coeff = 0; // Assume all coefficients of variable Xj are zeros. 
				for (i=0; i<n; i++) if (A[i][j]!=0) non_zero_coeff = 1; // A coefficient is not zero.
				if (non_zero_coeff==0) {
				printf("\n<<<< Coefficients of variable X%d are all zeros. Stop!\n", j);
				break;
				}
			}
		}
		
		// Print linear equation system. 
		if (non_zero_coeff) { // Continue to print linear equation system.
			printf("\n<<<< The linear equation system of rank %d is:\n", n);
			
			for (i=0; i<n; i++) {
				leading_term = 1; // Set leading_term flag to true.
				printf("          "); // Print 10 leading blanks.
				for (j=0; j<n; j++) { // Each term occupies 8-character position.
					if (A[i][j]==0) printf("        "); // Coefficient is 0 and print a blank term.
					else if (leading_term) { // The first term of an equation.
						if (A[i][j]==1) printf("     X%d ", j); // Coefficient is 1, not print coefficient.
						else if (A[i][j]==-1) printf("    -X%d ", j); // Coefficient is -1, print minus sign.
						else printf(" %3d X%d ", A[i][j], j); // Neither 1 nor -1, print the coefficient.
						leading_term = 0; // No more leading term.
					}
					else if (!leading_term) { // Not a leading term.
						if (A[i][j]==1) printf("+    X%d ", j); // Coefficent is 1, not print it£¬addition.
						else if (A[i][j]==-1) printf("-    X%d ", j); // Coefficent is -1, not print it£¬subtraction.
						else if (A[i][j]>0) printf("+ %2d X%d ", A[i][j], j); // Print coefficient, addition.
						else if (A[i][j]<0) printf("- %2d X%d ", -A[i][j], j); // Print coefficient, subtraction.
					}
				}
				printf("= %3d\n", C[i]); // Print constant term, alligned to the right.
			}
		}

		printf("\n----------------------------------\n"); // Print a separating line. 
	} while (1); // Repeat the loop. 
}

