#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exchange the values of x and y.
// Paramters x and y are call-by-address.
void swap(int *x, int *y) {
  int temp;
  
  temp = *x;
  *x = *y;
  *y = temp;
}

// A is an rxr square matrix.
// Set matrix A to be the transposition of matrix A itself.
void transpose_in_place(int r, int A[100][100]) {
  int i, j; // Loop variable.
  
  // The loop only scan half of the matrix elemets except the diagonl.
  // Two elemetns at the symmetric positions are exchanged.
  for (i=0; i<r; i++)
    for (j=0; j<i; j++)
      swap(&A[i][j], &A[j][i]);
}

int main(void) {
  int A[100][100]; // Assume maximum 100 by 100 elements.
  int r; // Size of the square matrix.
  int i, j; // Loop variables.
  
  srand(time(NULL)); // Seed of the random number generator.
  
  printf("Enter square matrix size r: "); // Input the square matirx size.
  scanf("%d", &r);
    
  for (i=0; i<r; i++)
    for (j=0; j<r; j++) A[i][j] = rand() % 100; // Randomly generate elements of A, between 0 and 99.
  
  printf("Square matrix A before transpostion:\n"); // Output matrix A before transpostion.
  for (i=0; i<r; i++) {
    for (j=0; j<r; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  transpose_in_place(r, A); // Perforem in-place transposition.
  
  printf("\nSquare matrix A after in-place transposition:\n");
  for (i=0; i<r; i++) {
    for (j=0; j<r; j++) printf("%3d ", A[i][j]);
    printf("\n");
  }
  
  return 0; 
}
