#include <stdio.h>

int main(void) {
	// (1) Declare integer arrays A[9][9] for coefficients and C[9] 
	//     for constants (the maximum value of n is 9). 
	int n; // Rank of a linear equation system.
	int A[9][9]; // Maximum 9 coefficients for each of maximum 9 equations.
	int C[9]; // Maximum 9 constants.
	int non_zero_coeff[9]; // Flag to indicate a non_zero coefficient in an equation or for a variable.
	int leading_term; // Flag to indicate whether a leading term or not. 
	int i, j; // Loop variables.
	int B=0, b=0;
	do {
		// (2) Input the rank of the linear equation system n, where 1<=n<=9.
		do {
			printf("Enter the rank of linear equation system (1 to 9 and 0 to stop): "); // Print a message.
			scanf("%d", &n); // Number of coefficients of a linear equation.
		} while (n<0 || n>9);
		if (n==0) return 0; // Program terminates, if n is 0.
		
		// ***** Complete program of the following steps.
		do{
			for(i=0; i<n; i++){
				printf("Enter %d coefficients and a constant for equation %d (Between -99 and 99): ", n, i);
				
				for(j=0; j<n; j++){
						scanf("%d", &A[i][j]);
						b+=A[i][j];
				}
				scanf("%d", &non_zero_coeff[i]);
			}
			printf("\n");
			
			if(b==0){
				printf("Coefficients for equation %d are all zeroes. Stop!\n");
			}
			for(j=0; j<n; j++){
				B=0;
				for(i=0; i<n; i++){
					B+=A[i][j];
					if(B==0){
						b=0;
						printf("Coefficients for equation %d are all zeroes. Stop!\n", i);
					}
				}
			}
			
		}while(b==0);
		
	for(i=0; i<n; i++){
		
		printf("          ");
	
		for(j=0; j<n; j++){
			if(A[i][j]!=0){
				if(i==0&&A[i][j]==1){
					printf(" X%d ", j);
				}
				else if(i==0&&A[i][j]==-1){
					printf(" -X%d ", j);
				}
				else if(i==0&&A[i][j]>0){
						printf(" %dX%d ",A[i][j], j);
				}
				else if(i==0&&A[i][j]<0){
					printf(" %dX%d ",A[i][j], j);
				}
				else if(A[i][j]>0){
					printf("+ %2d X%d ", A[i][j], j);
				}
				else {
					printf("- %2d X%d ", A[i][j]*-1, j);
				}
			
			}
			else{
				printf("        ");
			}
				
		}
		printf("= %d", non_zero_coeff);
		printf("\n");
	}
		
		
	
	
		printf("\n----------------------------------\n"); // Print a separating line. 
	} while (1); // Repeat the loop.
}

