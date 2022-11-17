#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A: mxn matrix,
   B: nxp matrix,
   C: mxp matrix.
   Compute C=AB.
*/
void matrix_product(int m, int n, int p, int A[100][100], int B[100][100], int C[100][100]) {
  int i, j, k;
    
  for (i=0; i<m; i++)
    for (j=0; j<p; j++) {
      C[i][j] = 0; // Initial element C[i][j] to 0.
      // C[i][j] is the inner product of the i-th row of matrix A and the j-th column of matrix B.
      for (k=0; k<n; k++) C[i][j] += A[i][k] * B[k][j]; 
    }
}

int main(void) {
  int A[100][100], B[100][100], C[100][100]; // Assume maximum 100 by 100 elements.
  int m, n, p; // Matrix size. A: m by n, B: n by p, C: m by p. 
  int i, j, k; // Loop variable.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter three integers m, n, p for matrix size: ");
  scanf("%d %d %d", &m, &n, &p);
    
  for (i=0; i<m; i++)
    for (j=0; j<n; j++) A[i][j] = rand() % 100; // Randomly generate elements of A, between 0 and 99.
    
  for (i=0; i<n; i++)
    for (j=0; j<p; j++) B[i][j] = rand() % 100; // Randomly generate elements of B, between 0 and 99.
    
  matrix_product(m, n, p, A, B, C); // Perform matrix multiplication.
  
  printf("\nMatrix A (%d X %d):\n", m, n); // Output elements of matrix A.
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B (%d X %d):\n", n, p); // Output elements of matrix B.
  for (i=0; i<n; i++) {
    for (j=0; j<p; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix C: (%d X %d)\n", m, p); // Output elements of matrix C.
  for (i=0; i<m; i++) {
    for (j=0; j<p; j++) printf("%6d ", C[i][j]);
    printf("\n");
  }
  
  return 0; 
}
