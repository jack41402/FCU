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
	int i, j,x,y; // Loop variables.

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
	A=(int**) malloc(sizeof(int*)*m);
	for(i=0;i<=r;i++) A[i]=(int*) malloc(sizeof(int)*min(s+i+1,n));
	j=1;
	for(i=r+1;i<m;i++) {
		A[i]=(int*) malloc(sizeof(int)*(n-j));
		j++;
	}
	B=(int**) malloc(sizeof(int*)*n);
	for(i=0;i<=s;i++) A[i]=(int*) malloc(sizeof(int)*min(r+i+1,m));
	j=1;
	for(i=r+1;i<n;i++) {
		A[i]=(int*) malloc(sizeof(int)*(m-j));
		j++;
	}
	x=1;
	for(i=0;i<m;i++){
		if(i<=r){
			for(j=0;j<min(s+i+1,n);j++) A[i][j]=rand()%100;
		}
		else{
			for(j=0;j<(n-x);j++) A[i][j]=rand()%100;
			x++;
		}
	}
	printf("\nMatrix A, %uX%u with lower bandwidth %d and upper bandwidth %d\n",m,n,r,s);
	x=1;
	for(i=0;i<m;i++){
		printf("     ");
		if(i<=r){
			for(j=0;j<min(s+i+1,n);j++) printf("%2d  ",A[i][j]);
		}
		else{
			for(j=0;j<x;j++) printf("    ");
			for(j=0;j<(n-x);j++) printf("%2d  ",A[i][j]);
			x++;
		}
		printf("\n");
	}
	// c. Perform matrix transposition to set matrix B to be the transposed matrix of A. 
	//    You may write the matrix transposition code in the main program directly.
	x=1;
	y=1;
	for(i=0;i<m;i++){
		if(i<=r){
			for(j=0;j<min(s+i+1,n);j++) {
				if(j<=min(r,s)) B[j][i]=A[i][j];
				else B[j][i-(j-min(r,s))]=A[i][j];
			}
			y++;
		}
		else{
			for(j=0;j<(n-x);j++) B[j+x][i]=A[i][j];
			x++;
		}
	}
	printf("\nMatrix B, %uX%u with lower bandwidth %d and upper bandwidth %d\n",n,m,s,r);
	x=1;
	for(i=0;i<n;i++){
		printf("     ");
		if(i<=s){
			for(j=0;j<min(r+i+1,m);j++) printf("%2d  ",B[i][j]);
		}
		else{
			for(j=0;j<x;j++) printf("    ");
			for(j=0;j<(m-x);j++) printf("%2d  ",B[i][j]);
			x++;
		}
		printf("\n");
	}
	for(i=0;i<m;i++) free(A[i]);
	free(A);
	for(i=0;i<n;i++) free(B[i]);
	free(B);
	// d. Output matrix A and B, but fill in the lower off-band elements using space characters.
	
	// e. Release memory space of matrix elements of A and B.

	return 0;
}
