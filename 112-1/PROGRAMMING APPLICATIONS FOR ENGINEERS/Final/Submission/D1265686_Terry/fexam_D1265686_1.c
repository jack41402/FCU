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
	int i, j ,k; // Loop variables.

	srand(time(NULL)); // Seed of the random number generator.
	
	// a. Enter four positive integers m, n, r, and s that, respectively, specify the matrix size, 
	//    the lower bandwidth, and the upper bandwidth of matrix A, where 1<=m,n<=20.
	
	// Input the size of matrix A.
	printf(">>>>> Enter matrix size of matrix A, m and n (between 1 and 20, including): ");
	scanf("%u %u", &m, &n); 
	// Input the lower bandwidth and the upper bandwidth of matrix A.
	printf("\n>>>>> Enter the lower and the upper bandwidth of matrix A, r and s: ");
	scanf("%u %u", &r, &s);
	
	// ***** Complete the program of the following steps.
	
    // b. Use dynamic memory allocation to create exact memory space for the non-zero banded 
	//    elements of matrices A and B and then randomly generate values of the non-zero elements 
	//    of matrix A such that the values generated are between 0 and 99 (including).
	
	
	A = (int**) malloc(sizeof(int*) * m);
	for(i=0;i<m;++i)
	{
		A[i] = (int*) malloc(sizeof(int*) * min(i,r)+1+min(s-1,n-i-1) );
	}
	
	/*
	B = (int**) malloc(sizeof(int*) * n);
	for(i=0;i< n ;++i)
	{
		B[i] = (int*) malloc(sizeof(int*) * min(i,s) + 1 + min(r,m-i-1) );
	}
	*/
	
	B = (int**) malloc(sizeof(int*) * n);
	for(i=0;i< n ;++i)
	{
		B[i] = (int*) malloc(sizeof(int*) * m );
	}
	
	
	for(i=0;i<m;++i)
	{
		for(j=0;j< min(i,r)+1+min(s-1,n-i-1) ;++j)
		{
			A[i][j]=rand() %100;
		}
	}
	
	
	
	
	// c. Perform matrix transposition to set matrix B to be the transposed matrix of A. 
	//    You may write the matrix transposition code in the main program directly.
	
	for(i=0;i<m;++i)
	{
		for(j=0;j< n ;++j)
		{
			B[j][i] = A[i][j];
		}
	}
	
	
	// d. Output matrix A and B, but fill in the lower off-band elements using space characters.
	
	printf("\nMatrix A, %u X %u with lower bandwidth %u and upper bandwidth %u:\n",m ,n ,r ,s);
	
	for(i=0;i<m;++i)
	{
		for(k=0;k<max(0,-m-1+r+i);++k)
		{
			printf("    ");
		}
		for(j=0;j< min(i,r)+1+min(s-1,n-i-1) ;++j)
		{
			printf("%3d ",A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	
	printf("Matrix B, %u X %u with lower bandwidth %u and upper bandwidth %u:\n",n ,m ,s ,r);
	
	/*
	for(i=0;i<n;++i)
	{
		for(k=0;k<max(0,-n-1+s+i);++k)
		{
			printf("    ");
		}
		for(j=0;j< min(i,s) + 1 + min(r,m-i-1) ;++j)
		{
			printf("%3d ",B[i][j]);
		}
		printf("\n");
	}
	*/
	
	for(i=0;i<n;++i)
	{
		for(k=0;k<max(0,-n-1+s+i);++k)
		{
			printf("    ");
		}
		for(j=0;j< min(i,s)+1+min(r-1,m-i-1) ;++j)
		{
			printf("%3d ",B[i][j]); 
		}
		printf("\n");
	}
	
	
	// e. Release memory space of matrix elements of A and B.
	
	for(i=0;i<m;++i)
	{
		free(A[i]);
	}
	free(A);
	
	for(i=0;i<n;++i)
	{
		free(B[i]);
	}
	free(B);
	
	return 0;
}
