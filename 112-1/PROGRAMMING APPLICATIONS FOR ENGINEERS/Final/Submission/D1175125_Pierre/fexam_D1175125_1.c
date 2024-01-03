#include <stdio.h>
#include <stdlib.h>

// Return the maximum value of x and y.
int max(int x, int y) {
	if (x>y) return x;
	else return y;
}

// Return the minimum value of x and y.
int min(int x, int y) {
	if (x<y) return x;
	else return y;
}

int main(void) {
	unsigned m, n; // Matrix size of A.
	unsigned r, s; // Lower bandwidth and upper bandwidth of matrix A.
//	int **A;  // Pointer to the elements of matrix A.
//	int **B;  // Pointer to the elements of matrix B. 
	int i, j; // Loop variables.

	srand(time(NULL)); // Seed of the random number generator.
	
	// a. Enter four positive integers m, n, r, and s that, respectively, specify the matrix size, 
	//    the lower bandwidth, and the upper bandwidth of matrix A, where 1<=m,n<=20.
	
	// Input the size of matrix A.
	printf(">>>>> Enter matrix size of matrix A, m and n (between 1 and 20, including): ");
	scanf("%u %u", &m, &n); 
	// Input the lower bandwidth and the upper bandwidth of matrix A.
	printf("\n>>>>> Enter the lower and the upper bandwidth of matrix A, r and s: ");
	scanf("%u %u", &r, &s);
	printf("\n");
	// ***** Complete the program of the following steps.
	
    // b. Use dynamic memory allocation to create exact memory space for the non-zero banded 
	//    elements of matrices A and B and then randomly generate values of the non-zero elements 
	//    of matrix A such that the values generated are between 0 and 99 (including).
	int A[m][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){A[i][j]=0;}
	}
	for(i=0;i<m;i++){
		for(j=max(0,i-r);j<=min(n-1,i+s);j++){A[i][j]=(rand() % 99); 
		}
	}
	printf("Matrix A, %dX%d with lower bandwidth %d and upper bandwidth %d:\n", m, n, r, s);
	for(i=0;i<m;i++){
		printf("     ");
		for(j=0;j<max(0,i-r);j++){printf("   ");
		}
		for(j=max(0,i-r);j<=min(n-1,i+s);j++){printf("%2d ",A[i][j] ); 
		}
		printf("\n");
	}
	// c. Perform matrix transposition to set matrix B to be the transposed matrix of A. 
	//    You may write the matrix transposition code in the main program directly.
	int B[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){B[i][j]=A[j][i];}
	}
	// d. Output matrix A and B, but fill in the lower off-band elements using space characters.
		printf("Matrix B, %dX%d with lower bandwidth %d and upper bandwidth %d:\n", n, m, s, r);
	for(i=0;i<n;i++){
		printf("     ");
		for(j=0;j<max(0,i-s);j++){printf("   ");
		}
		for(j=max(0,i-s);j<=min(m-1,i+r);j++){printf("%2d ",B[i][j] ); 
		}
		printf("\n");
	}
	// e. Release memory space of matrix elements of A and B.

	return 0;
}
