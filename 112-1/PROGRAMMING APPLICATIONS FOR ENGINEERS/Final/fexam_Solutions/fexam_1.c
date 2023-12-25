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
	int **A;  // Pointer to the elements of matrix A.
	int **B;  // Pointer to the elements of matrix B. 
	int i, j; // Loop variables.

	srand(time(NULL)); // Seed of the random number generator.
	
	// Input the size of matrix A.
	printf(">>>>> Enter matrix size of matrix A, m and n (between 1 and 20, including): ");
	scanf("%u %u", &m, &n); 
	// Input the lower bandwidth and the upper bandwidth of matrix A.
	printf("\n>>>>> Enter the lower and the upper bandwidth of matrix A, r and s: ");
	scanf("%u %u", &r, &s);
	
  	// Allocate dynamic memory for matrix A.
	A = (int **) malloc(sizeof(int*) * m); // Pointers to rows of matrix A.
	// Rows of banded matrix A, the lower bandwidth r and the upper bandwidth s.
	for (i=0; i<m; i++) A[i] = (int *) malloc(sizeof(int) * (min(i, r)+1+min(n-1-i, s)));
	
	// Allocate dynamic memory for matrix B.
	B = (int **) malloc(sizeof(int*) * n); // Pointers to rows of matrix B.
	// Rows of banded matrix B, the lower bandwidth s and the upper bandwidth r.
	for (i=0; i<m; i++) B[i] = (int *) malloc(sizeof(int) * (min(i, s)+1+min(m-1-i, r)));  
	
	// Randomly generate elements of A, between 0 and 99.   
	for (i=0; i<m; i++)
		for (j=max(0, i-r); j<=min(n-1, i+s); j++)
			// If i>ra, the i-th row is shift i-ra position to the left.
			A[i][j-max(0, i-r)] = rand() % 100; 
			
	// Set B to be the transposed matrix of A.
	for (i=0; i<m; i++)
		for (j=max(0, i-r); j<=min(n-1, i+s); j++)
			B[j][i-max(0, j-s)] = A[i][j-max(0, i-r)];
			
	// Output banded matrix A.
	printf("\nMatrix A, %uX%u with lower bandwidth %u and upper bandwidth %u:\n", m, n, r, s);
	for (i=0; i<m; i++) {
		printf("    ");
		// If the i>r, patch i-r blanks for zero elements..
		for (j=0; j<max(0, i-r); j++) printf("    ");
		for (j=max(0, i-r); j<=min(n-1, i+s); j++) printf("%3d ", A[i][j-max(0, i-r)]);
		printf("\n");
	}
	
	// Output banded matrix A.
	printf("\nMatrix B, %uX%u with lower bandwidth %u and upper bandwidth %u:\n", n, m, s, r);
	for (i=0; i<n; i++) {
		printf("    ");
		// If the i>s, patch i-s blanks for zero elements..
		for (j=0; j<max(0, i-s); j++) printf("    ");
		for (j=max(0, i-s); j<=min(m-1, i+r); j++) printf("%3d ", B[i][j-max(0, i-s)]);
		printf("\n");
	}
	
	// Release memory space of matrix elements of A and B.
	for (i=0; i<m; i++) free(A[i]);
	free(A);
	for (i=0; i<n; i++) free(B[i]);
	free(B);

	return 0;
}
