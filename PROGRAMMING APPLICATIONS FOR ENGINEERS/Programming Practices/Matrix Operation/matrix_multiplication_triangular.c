#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Return the minimum value of x and y.
int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: rxr lower triangular matrix,
   B: rxr upper triangular matrix,
   C: rxr matrix.
   Compute C=AB.
*/
void matrix_product_triangular(int r, int A[100][100], int B[100][100], int C[100][100]) {
  int i, j, k; // Loop variables.
    
  for (i=0; i<r; i++)
    for (j=0; j<r; j++) { // Compute the inner product of the i-th of A and j-th column of B.
      C[i][j] = 0; // Initial c[i][j] to 0.
      // Omit the operation if a[i][k] is 0 or b[k][j] is 0.
      for (k=0; k<=min(i,j); k++) C[i][j] += A[i][k] * B[k][j]; 
    }
}

int main(void) {
  int A[100][100], B[100][100], C[100][100]; // Assume maximum 100 by 100 elements.
  int r; // Size of square matrices.
  int i, j, k; // Loop variable.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter the square matrix size r: "); // Input size of square matrix.
  scanf("%d", &r);
  
  // Get values for the lower triangular elements of matrix A.
  for (i=0; i<r; i++)
    for (j=0; j<=i; j++) A[i][j] = rand() % 100 + 1; // Randomly generate elements of A, between 1 and 100.
    
  // Get values for the upper triangular elements of matrix B.
  for (i=0; i<r; i++)
    for (j=i; j<r; j++) B[i][j] = rand() % 100 + 1; // Randomly generate elements of B, between 1 and 100.
    
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
    for (j=i; j<r; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix C:\n"); // Output elemetns of matrix C.
  for (i=0; i<r; i++) {
    for (j=0; j<r; j++) printf("%6d ", C[i][j]);
    printf("\n");
  }
  
  return 0; 
}
