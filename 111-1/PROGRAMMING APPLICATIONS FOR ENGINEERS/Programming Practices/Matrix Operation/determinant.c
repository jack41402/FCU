#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Counter to record the number of function determinant() being called.
unsigned long cnt=0;

// Compute determinant of a square matrix.
// smatrix is the pointer to the input matrix; m: matrix size.
double determinant(double **smatrix, int m) { 
  double **cofactor; // Pointer of the cofactor.
  double det=0;// Determinant value.
  int j, p, q; // Loop variables.
  
  if (m == 1) {det = smatrix[0][0];} // Base case: when m is 1.
  else { // Recursive case: when m >1.
    // Dynamically allocat memory for the cofactor, size is m-1 by m-1.    
    cofactor = (double **) malloc(sizeof(double *) * (m-1));
    for (j=0; j<m-1; j++) cofactor[j] = (double *) malloc(sizeof(double) * (m-1)); 
    
    for (j=0; j<m; j++) { // Expand the determinant along row 0.
      for (p=0; p<m-1; p++) { // The size of cofactor is m-1 by m-1.
        for (q=0; q<m-1; q++) { // The row and column indices of the cofacter are between 0 and m-2.
          // The elements on row 0 of smatrix are removed and 
          // the elements on column j of smatrix are removed.
          // Copy elements in row p+1 of smatrix to row p of the cofactor.
          // For the elements on the left-hand-side of column j, keep them in the same column.
          // For the elements on the right-hand-side of column j, move them one column to the left.
          if (q<j) cofactor[p][q] = smatrix[p+1][q]; // Elements on the left-hand-side of column j.
          if (q>=j) cofactor[p][q] = smatrix[p+1][q+1]; // Elements on the right-hand-side of column j.
        }
      }
      // Compute the determinant of smatrix according its definition.
      det += pow(-1, j % 2 ) * smatrix[0][j] * determinant(cofactor, m-1);
    }
    
    // Release memory allocated to the cofactor.
    for (j=0; j<m-1; j++) free(cofactor[j]); 
    free(cofactor);
  }
  cnt++; // Increment 1, the number of times determinant being called.
  return det;
}

int main(void) {
  double **A; // Pointer of a square matrix.
  clock_t start, finish; // To recall the starting and finishing time of determinant().
  int i, j, n; // Loop variables.
  
  srand(time(NULL)); // Initial random number seed.
  
  // Enter the row and column size. 
  do {
    printf("Enter the row and column size of square matrix: ");
    scanf("%d", &n);
  } while (n<1 || n>12); // n is between 1 and 12.
  
  // Dynamically allocate memory for sequre matrix A.
  // In the mean time, randomly generate the elements of square matrix A.  
  A = (double **) malloc(sizeof(double *) * n);
  for (i=0; i<n; i++) {
    A[i] = (double *) malloc(sizeof(double) * n);
    for (j=0; j<n; j++) A[i][j] = rand() % 10000 / 10000.0;
  }
  
  // Print square matrix A and the determinant of A.
  printf("Square matrix A (n=%d):\n\n", n);
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) printf("%8.4f", A[i][j]);
    printf("\n");
  }
  
  start = clock(); // Recall the starting time.
  printf("\nDeterminant: %8.4f\n\n", determinant(A, n)); // Compute and output the determinant of A,
  finish = clock(); // Recall the finishing time.
  
  // Output the number of times determinant() being called. 
  printf("The number of function calls to determinant() is %d.\n", cnt);
  // Output the CPU time.
  printf("The computing time of determinant() is : %6.4E seconds\n\n",
         (double)(finish - start) / CLOCKS_PER_SEC);
  
  // Release memory allocated to square matrix A.
  for (i=0; i<n; i++) free(A[i]);
  free(A);

  return  0;
}
