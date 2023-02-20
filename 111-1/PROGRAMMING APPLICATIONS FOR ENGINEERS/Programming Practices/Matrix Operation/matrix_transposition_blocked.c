#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Both A and B are nxn matrices, and block size b divides n.
// Set matrix B to be the transposition of matrix A using blocked transpostion algorithm.
void transpose_blocked(int n, int b, int A[100][100], int B[100][100]) {
  int i0, j0, i1, j1; // Loop variables.
  
  for (i0=0; i0<n/b; i0++) // i0 and j0 are block indecies 
    for (j0=0; j0<n/b; j0++)
      for (i1=0; i1<b; i1++) // i1 and j1 are block element indecies.
        for (j1=0; j1<b; j1++)
          // Copy the (i1, j1)-th element in block (i0, j0) of matrix A to
          // the (j1, i1)-the element in block (j0, i0) of matrix B.
          // That is, the blocks of A and then for each block traspose its elements.
          B[j0*b+j1][i0*b+i1] = A[i0*b+i1][j0*b+j1]; 
}

int main(void) {
  int A[100][100], B[100][100]; // Assume maximum 100 by 100 elements.
  int n, b; // Square matrix size and block size.
  int i, j; // Loop variables.
  
  srand(time(NULL));
  
  printf("Enter square matrix size n: "); // Input the square matrix size. 
  scanf("%d", &n);
  do {
    printf("Enter block size b (b is a factor of n): "); // Input the bloack size.
    scanf("%d", &b);  // b must be a factor of n.
  } while (n%b!=0);
    
  for (i=0; i<n; i++)
    for (j=0; j<n; j++) A[i][j] = rand() % 100; // Randomly generate elements of A, between 0 and 99.
  
  transpose_blocked(n, b, A, B); // Perform matrix transposition. B=A^T.
  
  printf("\nMatrix A:\n"); // Output elements of matrix A.
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  printf("\nMatrix B:\n"); // Output elements of matrix A.
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%3d ", B[i][j]);
    printf("\n");
  }
  
  return 0; 
}
