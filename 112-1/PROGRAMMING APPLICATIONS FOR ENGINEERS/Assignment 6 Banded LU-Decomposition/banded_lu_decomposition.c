/* Banded LU-decomposition. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Return maximum vlaue of x and y.
int max(int x, int y) {
  if (x>y) return x;
  else return y;
}

// Return minimum vlaue of x and y.
int min(int x, int y) {
  if (x<y) return x;
  else return y;
}

/* A: nxn matrix,
   r: the lower bandwidth of matrix A,
   s: the upper bandwidth of matrix A,
   Compute A=LU using banded LU decomposition.
*/
void lu_decompose_banded(int n, int r, int s, float A[100][100], float L[100][100], float U[100][100]) {
  int i, j, k;
    
  for (k=0; k<n; k++) { // To compute submatrix A(k+1).
    for (j=k; j<=min(n-1,k+s); j++) U[k][j] = A[k][j]; // Compute elements of the k-th row of matrix U
    for (i=k; i<=min(n-1,k+r); i++) L[i][k] = A[i][k] / A[k][k]; // Compute elements of the k-th column of matrix L
    for (i=k+1; i<=min(n-1,k+r); i++) // Compute elements of submatrix A(k+1):
      for (j=max(k+1,i-r); j<=min(n-1,min(i+s,k+s)); j++) A[i][j] = A[i][j] - L[i][k] * U[k][j];
  }
}

int main(void) {
  float A[100][100], A1[100][100], L[100][100], U[100][100]; // Assume maximum 100 by 100 elements.
  int n; // Size of square matrices.
  int r, s; // Lower bandwidth and upper bandwidth of A.
  int check; // Flag to check the correctness of the program.
  int i, j, k; // Loop variables.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter matrix size n: "); // Input the matrix size.
  scanf("%d", &n); 
  
  // Input the lower bandwidth and the upper bandwidth of matrix A. 
  printf("Enter the lower bandwidth and the of matrix A, (r, s): ");
  scanf("%d %d", &r, &s);  
  
  // Initial matrix A and A1 to 0.
  // In case of the off-band elements.
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {A1[i][j]=0; A[i][j]=0;}
    
  // Generate random values for the elements of matrix A.
  // Matrix element A[i][j], 0<A[i][j]<=1; A1[i][j] is the copy of A[i][j] for p
  // rogram verification.
  for (i=0; i<n; i++)
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) {A[i][j] = A1[i][j] = (rand() % 10000 + 1) / 10000.0;}
  
  printf("Matrix A:\n"); // Output matrix A.
  for (i=0; i<n; i++) {
    for (j=0; j<max(0,i-r); j++) printf("         "); // Off-band elements of the lower band.
    for (j=max(0,i-r); j<=min(n-1,i+s); j++) printf("%8.4f ", A[i][j]);
    printf("\n");
  }
  
  // Decompose A into matrices L and U.
  lu_decompose_banded(n, r, s, A, L, U);
  
  printf("Matrix L:\n"); // Output matrix L.
  for (i=0; i<n; i++) {
    for (j=0; j<i-r; j++) printf("         "); // Off-band elements of the lower band.
    for (j=max(0,i-r); j<=i; j++) printf("%8.4f ", L[i][j]);
    printf("\n");
  }
  
  printf("Matrix U:\n"); // Output matrix U.
  for (i=0; i<n; i++) {
    for (j=0; j<i; j++) printf("         "); // Do not print the lower triangular elements.
    for (j=i; j<=min(n-1,i+s); j++) printf("%8.4f ", U[i][j]);
    printf("\n");
  }
  
  check = 1; // Intial flag to true.
  for (i=0; i<n && check; i++)
    for (j=max(0,i-r); j<=min(n-1,i+s) && check; j++) {
      A[i][j] = 0;
      // Compute A[i][j] for A<=LU.
      for (k=max(0, max(i-r,j-s)); k<=min(n-1,min(i,j)); k++) A[i][j] += L[i][k] * U[k][j];  
      check = check && (fabs(A[i][j]-A1[i][j])<0.0001); // Compare A[i][j] and A1[i][j], allow error 0.0001
    }
  
  if (check) printf("The LU-decomposition program is correct.\n"); // The program is correct.
  else printf("The LU-decomposition program is incorrect.\n"); // The program is incorrect.
  
  return 0; 
}
