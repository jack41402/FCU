#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Return the minimum value of x and y.
int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: pointer to rxr lower triangular matrix,
   B: pointer to rxr upper triangular matrix,
   C: pointer to rxr matrix.
   Compute C=AB.
*/
void matrix_product_triangular(int r, int **A, int **B, int **C) {
  int i, j, k; // Loop variables.
    
  for (i=0; i<r; i++)
    for (j=0; j<r; j++) { // Compute the inner product of the i-th of A and j-th column of B.
      C[i][j] = 0; // Initial c[i][j] to 0.
      // Omit the operation if a[i][k] is 0 or b[k][j] is 0.
      // Elements of matrix B on the k-th row is shifted k positions to the left.
      for (k=0; k<=min(i,j); k++) C[i][j] += A[i][k] * B[k][j-k]; 
    }
}

int main(void) {
  int **A, **B, **C; // Pointers of two-dimensional arrays.
  int r; // Size of square matrices.
  int i, j, k; // Loop variable.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter the square matrix size r: "); // Input size of square matrix.
  scanf("%d", &r);
  
  // Allocate memory space for matrices A, B, and C
  A = (int **) malloc(sizeof(int*) * r); // Pointers to rows of matrix A.
  for (i=0; i<r; i++) A[i] = (int *) malloc(sizeof(int) * (i+1)); // Rows of lower triangular matrix A.
  B = (int **) malloc(sizeof(int*) * r); // Pointers to rows of matrix B.
  for (i=0; i<r; i++) B[i] = (int *) malloc(sizeof(int) * (r-i)); // Rows of upper triangular matrix B.
  C = (int **) malloc(sizeof(int*) * r); // Pointers to rows of matrix C.
  for (i=0; i<r; i++) C[i] = (int *) malloc(sizeof(int) * r); // Rows of full matrix C.
  
  // Get values for the lower triangular elements of matrix A.
  for (i=0; i<r; i++) // Randomly generate elements of A, between 1 and 100.
    for (j=0; j<=i; j++) A[i][j] = rand() % 100 + 1; // Starts from column 0.
    
  // Get values for the upper triangular elements of matrix B.
  for (i=0; i<r; i++) // Randomly generate elements of B, between 1 and 100.
    for (j=0; j<r-i; j++) B[i][j] = rand() % 100 + 1; // Starts from column i, shift i positions to the left.
    
  // Compute C = A X B.  
  matrix_product_triangular(r, A, B, C); // Triangular matrix multiplication.
  
  printf("\nMatrix A:\n"); // Output elemetns of matrix A.
  for (i=0; i<r; i++) {
    for (j=0; j<=i; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n"); // Output elemetns of matrix B.
  for (i=0; i<r; i++) {
    for (j=0; j<i; j++) printf("    ");
    // Elements on the i-th of matrix B is shift i positions to the left.
    for (j=i; j<r; j++) printf("%3d ", B[i][j-i]); 
    printf("\n");
  }
  
  printf("\nMatrix C:\n"); // Output elemetns of matrix C.
  for (i=0; i<r; i++) {
    for (j=0; j<r; j++) printf("%6d ", C[i][j]);
    printf("\n");
  }
  
  // Deallocate memory space of matrices A, B, and C 
  for (i=0; i<r; i++) {free(A[i]); free(B[i]); free(C[i]);} // Free rows of matrices A, B, and C.
  free(A); // Free pointers to rows of matrix A.
  free(B); // Free pointers to rows of matrix B.
  free(C); // Free pointers to rows of matrix C.
  
  return 0; 
}
