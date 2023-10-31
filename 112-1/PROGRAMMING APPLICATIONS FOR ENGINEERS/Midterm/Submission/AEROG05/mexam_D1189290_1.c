#include <stdio.h>

int main(void) {
	// (1) Declare integer arrays A[9][9] for coefficients and C[9] 
	//     for constants (the maximum value of n is 9). 
	int n; // Rank of a linear equation system.
	int A[9][9]; // Maximum 9 coefficients for each of maximum 9 equations.
	int C[9]; // Maximum 9 constants.
	int non_zero_coeff; // Flag to indicate a non_zero coefficient in an equation or for a variable.
	int leading_term; // Flag to indicate whether a leading term or not. 
	int i, j; // Loop variables.
	
	do {
		// (2) Input the rank of the linear equation system n, where 1<=n<=9.
		do {
			printf("Enter the rank of linear equation system (1 to 9 and 0 to stop): "); // Print a message.
			scanf("%d", &n); // Number of coefficients of a linear equation.
		} while (n<0 || n>9);
		if (n==0) return 0; // Program terminates, if n is 0.
		for(i=0;i<n;i++){
			printf("Enter %d coefficients and a constant for Equation %d (between -99 and 99): ",n,i);
			non_zero_coeff=0;
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
			if(A[i][j]!=0){
			non_zero_coeff=1;
			}
		}
			scanf("%d",&C[i]);
		if(non_zero_coeff==0){
			printf("Coefficients of Equation %d are all zeros. Stop!",i);
			return 0;
		}
		for(j=0;j<n;j++){
			if(A[j][i]!=0){
				break;
			}
			if(j==n-1){
			printf("Coefficients of variables X%d are all zeros. Stop!",j);
			return 0;
		}
		}
	}
	printf("\n");
	printf("The linear equation system of rank %d is:\n");
	for(i=0;i<n;i++){
		printf("    ");
		leading_term=1;
		for(j=0;j<n;j++){
			if(A[i][j]!=0){
				if(!leading_term){
					if(A[i][j]>0){
						printf(" + ");
					}else{
						printf(" - "); 
					}
					}else{
					leading_term=0;
					if(A[i][j]<0){
						printf("-");
					}
					else printf(" ");
				}
				if(abs(A[i][j]!=1)){
					printf("%2d",abs(A[i][j]));
				}else{
					printf(" ");
				}
				printf("X%d",j);
			}
		}
		if(C[i]>=0){
			printf(" = %d\n",C[i]);
		}else{
			printf(" = %d\n",C[i]);
		}
	}
		printf("\n----------------------------------\n"); // Print a separating line. 
	} while (1); // Repeat the loop.
}

