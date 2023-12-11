/* LU-decomposition. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Return the minimum value of x and y.
int min(int x, int y) {
	if (x<=y) return x;
	else return y;
}

/* A: nxn matrix,
   L: nxn lower triangular matrix,
   U: nxn upper triangular matrix.
   Compute A=LU.
*/
void LU_decompose_dynamic(int n, float **A, float **L, float **U) {
  int i, j, k;
    
  for (k=0; k<n; k++) { // To compute submatrix A(k+1).
    for (j=k; j<n; j++) U[k][j-k] = A[k][j]; // Compute elements of the k-th row of matrix U
    for (i=k; i<n; i++) L[i][k] = A[i][k] / A[k][k]; // Compute elements of the k-th column of matrix L
    for (i=k+1; i<n; i++) // Compute elements of submatrix A(k+1):
      for (j=k+1; j<n; j++) A[i][j] = A[i][j] - L[i][k] * U[k][j-k];
  }
}

int main(void) {
  float **A, **A1, **L, **U; // Pointers to two-dimensional arrays A, L, U, and A1.
  int n; // Size of the square matrices.
  int check; // Flag to check the correctness of the program.
  int i, j, k; // Loop variables.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter square matrix size n: "); // Input the matrix size.
  scanf("%d", &n);
  
  A = (float **) malloc(n * sizeof(float *)); // Allocate the first dimension of matrix A.
  A1 = (float **) malloc(n * sizeof(float *)); // Allocate the first dimension of matrix A1.
  L = (float **) malloc(n * sizeof(float *)); // Allocate the first dimension of matrix L.
  U = (float **) malloc(n * sizeof(float *)); // Allocate the first dimension of matrix U.
  for (i=0; i<n; i++) {
  	A[i] = (float *) malloc(n * sizeof(float)); // Allocate the second dimension of matrix A.
  	A1[i] = (float *) malloc(n * sizeof(float)); // Allocate the second dimension of matrix A1.
  	L[i] = (float *) malloc((i+1) * sizeof(float)); // Allocate the second dimension of matrix L.
  	U[i] = (float *) malloc((n-i) * sizeof(float)); // Allocate the second dimension of matrix U.
  }
    
  // Get values for the elements of matrix A.
  // Matrix element A[i][j], 0<A[i][j]<=1; A1[i][j] is the copy of A[i][j] for program verification.
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {A[i][j] = (rand() % 10000 + 1) / 10000.0; A1[i][j] = A[i][j];}
  
  printf("\nMatrix A:\n"); // Output matrix A.
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%8.4f ", A[i][j]);
    printf("\n");
  }
  
  LU_decompose_dynamic(n, A, L, U); // Peform LU-decomposition. 
  
  printf("\nMatrix L:\n"); // Output matrix L.
  for (i=0; i<n; i++) {
    for (j=0; j<=i; j++) printf("%8.4f ", L[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix U:\n"); // Ouput matrix U.
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("         "); // Do not print the lower triangular elements.
    for (j=i; j<n; j++) printf("%8.4f ", U[i][j-i]);
    printf("\n");
  }
  
  check = 1; // Intial flag to true. 
  for (i=0; i<n && check; i++)
    for (j=0; j<n && check; j++) {
      A[i][j] = 0;
      for (k=0; k<=min(i,j); k++) A[i][j] += L[i][k] * U[k][j-k]; // Compute A[i][j] for A<=LU 
      check = check && (fabs(A[i][j]-A1[i][j])<0.0001); // Compare A[i][j] and A1[i][j], allow error 0.0001.
    }
  
  if (check) printf("\nThe LU-decomposition program is correct.\n"); // The program is correct.
  else printf("\nThe LU-decomposition program is incorrect.\n"); // The program is incorrect.
  
  return 0; 
}
