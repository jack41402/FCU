#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A is an mxn matrix and B is an nxm matrix.
// Set matrix B to be the transposition of matrix A.
void transpose(int m, int n, int A[100][100], int B[100][100]) {
  int i, j; // Loop variables.
  
  for (i=0; i<m; i++)
    for (j=0; j<n; j++)
      B[j][i] = A[i][j]; // Put elements of matrix A in martix B.
}

int main(void) {
  int A[100][100], B[100][100]; // Assume maximum 100 by 100 elements.
  int m, n; // Matrix size m by n.
  int i, j; // Loop variables.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter matrix size m and n: ");
  scanf("%d %d", &m, &n); // Input matrix size m and n.
    
  for (i=0; i<m; i++)
    for (j=0; j<n; j++) A[i][j] = rand() % 100; // Randomly generate elements of A, between 0 and 99.
  
  transpose(m, n, A, B); // Perform matrix transposition. B=A^T.
  
  printf("\nMatrix A:\n"); // Output elements of matrix A.
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n"); // Output elements of matrix B.
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  return 0; 
}
