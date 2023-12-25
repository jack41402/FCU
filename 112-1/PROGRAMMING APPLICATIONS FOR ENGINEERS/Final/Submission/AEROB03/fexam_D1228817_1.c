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
	
	A=(int**) malloc(sizeof(int*)*m);
	for(i=0; i<m; i++) A[i]=(int*) malloc(sizeof(int)*(1+min(i, r)+min(m-1-i, s)));
	
	printf("Matrix A, %uX%u with lower bandwidth %u and upper bandwidth %u:\n", m, n, r, s);
	
	for(i=0; i<m; i++){
		for(j=0; j<1+min(i, r)+min(m-1-i, s); j++) A[i][j]= rand()%100;
	}
	
	for(i=0; i<m; i++){
		if(i>r){
			 for(j=0; j<i-r; j++) printf("    ");
		} 
		for(j=0; j<1+min(i, r)+min(m-1-i, s); j++) printf("%4u", A[i][j]);
		printf("\n");
	}
	
	B=(int**) malloc(sizeof(int*)*n);
	for(i=0; i<n; i++) B[i]=(int*) malloc(sizeof(int)*(1+min(i, s)+min(n-1-i, r)));
	
	for(i=0; i<m; i++){
		for(j=0; j<min(i, r)+1; j++) B[j][i]=A[i][j];
	}
	
	printf("\n\nMatrix B, %uX%u with lower bandwidth %u and upper bandwidth %u:\n", n, m, s, r);
	
		for(i=0; i<n; i++){
		if(i>s){
			 for(j=0; j<i-s; j++) printf("    ");
		} 
		for(j=0; j<1+min(i, s)+min(n-1-i, r); j++) printf("%4u", B[i][j]);
		printf("\n");
	}
	
	for(i=0; i<m; i++) free(A[i]);
	free(A);
	for(i=0; i<n; i++) free(B[i]);
	free(B);

	return 0;
}
