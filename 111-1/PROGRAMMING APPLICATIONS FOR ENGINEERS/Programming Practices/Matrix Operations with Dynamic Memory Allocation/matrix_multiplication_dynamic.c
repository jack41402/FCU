#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A: pointer to mxn matrix,
   B: pointer to nxp matrix,
   C: pointer to mxp matrix.
   Compute C=AB.
*/
void matrix_product(int m, int n, int p, int **A, int **B, int **C) {
  int i, j, k;
    
  for (i=0; i<m; i++)
    for (j=0; j<p; j++) {
      C[i][j] = 0; // Initial element C[i][j] to 0.
      // C[i][j] is the inner product of the i-th row of matrix A and the j-th column of matrix B.
      for (k=0; k<n; k++) C[i][j] += A[i][k] * B[k][j]; 
    }
}

int main(void) {
  int **A, **B, **C; // Pointers of two-dimensional arrays.
  int m, n, p; // Matrix size. A: m by n, B: n by p, C: m by p. 
  int i, j, k; // Loop variable.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter three integers m, n, p for matrix size: ");
  scanf("%d %d %d", &m, &n, &p);
  
  // Allocate memory space for matrices A, B, and C
  A = (int **) malloc(sizeof(int*) * m); // Pointers to rows of matrix A.
  for (i=0; i<m; i++) A[i] = (int *) malloc(sizeof(int) * n); // Rows of matrix A.
  B = (int **) malloc(sizeof(int*) * n); // Pointers to rows of matrix B.
  for (i=0; i<n; i++) B[i] = (int *) malloc(sizeof(int) * p); // Rows of matrix B.
  C = (int **) malloc(sizeof(int*) * m); // Pointers to rows of matrix C.
  for (i=0; i<m; i++) C[i] = (int *) malloc(sizeof(int) * p); // Rows of matrix C.
    
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
  
  // Deallocate memory space of matrices A, B, and C 
  for (i=0; i<m; i++) free(A[i]); // Free rows of matrix A.
  free(A); // Free pointers to rows of matrix A.
  for (i=0; i<n; i++) free(B[i]); // Free rows of matrix B.
  free(B); // Free pointers to rows of matrix B.
  for (i=0; i<m; i++) free(C[i]); // Free rows of matrix C.
  free(C); // Free pointers to rows of matrix C.
  
  return 0; 
}
