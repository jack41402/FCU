#include <stdio.h>

int main(void) {
	// (1) Declare integer arrays A[9][9] for coefficients and C[9] 
	//     for constants (the maximum value of n is 9). 
	int n; // Rank of a linear equation system.
	int A[9][9]; // Maximum 9 coefficients for each of maximum 9 equations.
	int C[9]; // Maximum 9 constants.
	int non_zero_coeff; // Flag to indicate a non_zero coefficient in an equation or for a variable.
	int leading_term; // Flag to indicate whether a leading term or not. 
	int i, j, e, k; // Loop variables.
	
	do {
		// (2) Input the rank of the linear equation system n, where 1<=n<=9.
		do {
			printf("Enter the rank of linear equation system (1 to 9 and 0 to stop): "); // Print a message.
			scanf("%d", &n); // Number of coefficients of a linear equation.
		} while (n<0 || n>9);
		if (n==0) return 0; // Program terminates, if n is 0.
		non_zero_coeff = 0;
		// ***** Complete program of the following steps.
		for(i=0; i<n; i++){
			k = 0;
			printf(">>>> Enter %d coefficients and a constant for Equation %d (between -99 and 99): ", n, i);
			if (n == 1){
				scanf("%d %d", &A[i][0],&C[i]);
				if (A[i][0] == 0){
					non_zero_coeff = 1;
					break;
				}
			}
			if (n == 2){
				scanf("%d %d %d", &A[i][0],&A[i][1],&C[i]);
			}
			if (n == 3){
				scanf("%d %d %d %d", &A[i][0],&A[i][1],&A[i][2],&C[i]);
			}
			if (n == 4){
				scanf("%d %d %d %d %d", &A[i][0],&A[i][1],&A[i][2],&A[i][3],&C[i]);
			}
			if (n == 5){
				scanf("%d %d %d %d %d %d", &A[i][0],&A[i][1],&A[i][2],&A[i][3],&A[i][4],&C[i]);
			}
			if (n == 6){
				scanf("%d %d %d %d %d %d %d", &A[i][0],&A[i][1],&A[i][2],&A[i][3],&A[i][4],&A[i][5],&C[i]);
			}
			if (n == 7){
				scanf("%d %d %d %d %d %d %d %d", &A[i][0],&A[i][1],&A[i][2],&A[i][3],&A[i][4],&A[i][5],&A[i][6],&C[i]);
			}if (n == 8){
				scanf("%d %d %d %d %d %d %d %d %d", &A[i][0],&A[i][1],&A[i][2],&A[i][3],&A[i][4],&A[i][5],&A[i][6],&A[i][7],&C[i]);
			}
			if (n == 9){
				scanf("%d %d %d %d %d %d %d %d %d %d", &A[i][0],&A[i][1],&A[i][2],&A[i][3],&A[i][4],&A[i][5],&A[i][6],&A[i][7],&A[i][8],&C[i]);
			}
			for (j=1; j<n; j++){
				if (A[i][j] == 0 && A[i][j] == A[i][j-1]){
					k+=1;
				}
			}
			if (k == n-1)	non_zero_coeff = 1;
			if (non_zero_coeff == 1){
				printf("\n<<<< Coefficients of Equation %d are all zeros. Stop!\n", i);
				break;
			}
		}	
		if (non_zero_coeff == 1){
			printf("\n----------------------------------\n");
				continue;
		}
		
		for (i=0;i<n;i++){
			k=0;
			for (j=0;j<n;j++){
				if (A[i][j] == 0 && A[i][j] == A[i-1][j]){
					k+=1;
				}
			}
			if (k == n-1)	non_zero_coeff = 1;
			if (non_zero_coeff == 1){
				printf("\n<<<< Coefficients of variable X%d are all zeros. Stop!\n", i);
				break;
			}
		}
		if (non_zero_coeff == 1){
			printf("\n----------------------------------\n");
				continue;
		}
		
		// (3) For equation i, A[i][0] X0 +A[i][1] X1 + ... + A[i][n-1] Xn-1 = Ci, where 0<=i<=n-1, 
		//     input n integers of coefficients and a constant to store them in A[i][j] 
		//     and C[i], where 0<=j<=n-1, such that -99<=A[i][j], C[i]<=99. Verify that 
		//     (a) there is no equation with all zero coefficients, and 
		//     (b) there is no variable Xj with all zero coefficients.
		printf("\n<<<< The linear equation system of rank %d is:\n", n);
		for (i=0; i<n; i++){
			leading_term = 0;
			for (e=0;e<10;e++){
				printf(" ");
			}
			for (j=0;j<n;j++){
				if (A[i][j] != 0){
					if (leading_term == 0){
						if (A[i][j] == 1){
							printf("     X%d ",j);
						}
						else if (A[i][j] == -1){
							printf("    -X%d ",j);
						}
						else{
							printf("%4d X%d ", A[i][j], j);
						}
						leading_term = 1;
					}	
					else{
						if (A[i][j] == 1){
							printf("+    X%d ",j);
						}
						else if (A[i][j] == -1){
							printf("-    X%d ",j);
						}
						else{
							if (A[i][j] < 0){
								printf("- %2d X%d ", A[i][j]*-1, j);
							}
							else{
								printf("+ %2d X%d ", A[i][j], j);
							}
						}
					}
				}
				else{
					printf("        ");
				}
			}
			printf("= %3d\n",C[i]);
		}
		// (4) Print the linear equation one equation in a line, leave 10 leading blanks before
		//     each equation. For each equation, print all terms in the way that 
		//     (a) if a term is of coefficient zero, print blanks only, 
		//     (b) if a term is the first non-zero coefficient term in an equation, do not print 
		//         its operator, but print only the coefficient value and its variable name, 
		//     (c) if a coefficient is either 1 or -1, omit the coefficient value and print 
		//         operator '+' or '-', blanks, and its variable name, 
		//     (d) for coefficients other than 0, 1, and -1, print '+' or '-', coefficient 
		//         value without sign, and its variable name, 
		//     (e) Align operators '+' or '-' for the terms of the same Xi and '=' 
		//         in the vertical direction. 
		// Repeat steps (2) to (4) until the value of n is 0.
	
		printf("\n----------------------------------\n"); // Print a separating line. 
	} while (1); // Repeat the loop.
}

