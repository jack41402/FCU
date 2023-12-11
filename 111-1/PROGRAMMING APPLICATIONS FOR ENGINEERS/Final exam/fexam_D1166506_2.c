#define epsilon 0.0001
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Print system of equations.
void print_equations(double **A, double *C, int n) {
	int i, j; // Loop variables.
	for (i=0; i<n; i++) {
		printf("    %5.2f X_0", A[i][0]);
		for (j=1; j<n; j++)
			if (A[i][j]>=0) printf(" + %5.2f X_%d", A[i][j], j);
			else if (A[i][j]<0) printf(" - %5.2f X_%d", -A[i][j], j);
		printf(" = %4.2f\n", C[i]);
	}
}

// Replace the i-th column of A by vector C, the resulting matrix B is returned.
// n is the matrix size.
double ** replace(int n, double ** A, double * C, int pos) {
	double ** B;
	int i , j,k; // loop variable 	
	// ***** Complete this function.
	B = (double **) malloc (n * sizeof (double *)) ;
	for (i=0 ; i<n ; ++i)
	{
		B[i] = (double *) malloc (n * sizeof (double)) ;
	}
	for (j=0 ; j<n ; ++j)
	{
		for (k=0 ; k<n ; ++k)
		{
			if (j==pos)
			{
				B[j][k] = C[k] ;
//				printf ("%.2lf \n" , C[k]) ;
				continue ;
			}
			B[j][k] = A[j][k] ;
		}
	}
//	printf ("Matrix B\n") ;
//	for (i=0 ;i<n ; ++i)
//	{
//		printf ("    ") ;
//		for (j=0 ; j<n ; ++j)
//		{
//			printf ("%2.2lf " , B[i][j]) ;
//		}
//		printf ("\n") ;
//	}
//	printf ("\n\n") ;
	return B;
}

// Compute determinant of a square matrix.
// smatrix is the pointer to the input matrix; m: matrix size.
double determinant(double **smatrix, int m) { 
	double **cofactor; // Pointer of the cofactor.
	double det=0; // Determinant value.
	double temp , sign=1 ;
	int j, p, q; // Loop variables.
	cofactor = (double **) malloc (m * sizeof (double *)) ;
	for (j=0 ; j<m ; ++j)
	{
		cofactor[j] = (double *) malloc (m * sizeof (double)) ;
	}
	// ***** Complete this function.
	for (p=0 ; p<m ; ++p)
	{
		temp = 1 ;
//		printf ("%d\n" , p) ;
		for (q=0 ; q<m ; ++q)
		{
//			printf ("%.2lf\n" , smatrix[q][(p+q)%m]) ;
			temp *= smatrix[q][(p+q)%m] ;
		}
		det += temp ;
	}
	for (p=0 ; p<m ; ++p)
	{
		temp = 1 ;
//		printf ("%d\n" , p) ;
		for (q=m-1 ; q>=0 ; --q)
		{
//			printf ("%.2lf %d %d\n" , smatrix[q][(p-q+m)%m] , q , (p-q+m)%m) ;
			temp *= smatrix[q][(p-q+m)%m] ;
		}
		det -= temp ;
	}
//	printf ("%lf\n\n" , det) ;
	return det ;
}

int main(void) {
	int n; // Degree of linear system, 1 to 12.
	double **A; // Coefficient matrix of n-variable linear system.
	double *C; // Constant (column) vector of n-variable linear system.
	double *X; // Solution (column) vector of n-variable linear system.
	double *prod; // Matrix-vector product of AX.
	double det; // Determinat of matrix A. 
	double temp ;
	int verify = 1;
	int i, j; // Loop variable.
	
	srand(1000); 
	
	// Enter the degree of linear system.
	do {
		printf("Enter the degree of linear system (1 to 12): ");
		scanf("%d", &n); // Degree of linear system.
	} while (n<1 || n>12);

	// ***** Complete the program to perform the follwing steps.
	
	// Allocate memory space for coefficient matrix A, constant vector C, and solution vector X.
	A = (double **) malloc (n * sizeof (double *)) ;
	for (i=0 ; i<n ; ++i)
	{
		A[i] = (double *) malloc (n * sizeof (double)) ; 
	}
	C = (double *) malloc (n * sizeof (double)) ;
	X = (double *) malloc (n * sizeof (double)) ;
	// Use random number generator with seed 1000 to generate elements of A and C. Elements 
	// of A and C are between -1.0000 and 1.0000.
	for (i=0 ; i<n ; ++i)
	{
		for (j=0 ; j<n ; ++j)
		{
			A[i][j] = (rand()%20000+1)/10000.0 - 1 ;
		}
	}
	for (i=0 ; i<n ; ++i)
	{
		C[i] = (rand()%20000+1)/10000.0 - 1 ;
	}
	// Output matrix A, vector C, and the system of equations. 
	// Print floating point elements two digits after the decimal points.
	printf ("\n>>>> Matrix A:\n") , fflush(stdout) ;
	for (i=0 ;i<n ; ++i)
	{
		printf ("    ") ;
		for (j=0 ; j<n ; ++j)
		{
			printf ("%2.2lf " , A[i][j]) ;
		}
		printf ("\n") ;
	}
	printf ("\n>>>> Vector C:\n") ;
	printf ("    ") ;
	for (i=0 ; i<n ; ++i)
	{
		printf ("%2.2lf " , C[i]) ;
	}
	printf ("\n") ;
	// Solve the linear system using the determinant approach and output solution vector X. 
	det = determinant(A , n) ;
//	printf ("DET: %2.2lf\n" , det) ;
	for (i=0 ; i<n ; ++i)
	{
		X[i] = determinant (replace (n , A , C , i) , n)/det ;
//		printf ("%2.2lf\n" , X[i]) ;
	}
	printf ("\n>>>> The linear system is:\n") ;
	print_equations (A , C , n) ;
	
	printf ("\n>>>> The solution of the linear system is: ") ;
	for (i=0 ; i<n ; ++i) printf (" %.2lf" , X[i]) ;
	// Verify the solution by checking the absolute value of all elements of vector AX-C 
	// being less than epsilon, where epsilon is 0.0001.
	for (i=0 ; i<n ; ++i)
	{
		temp = 0 ;
		for (j=0 ; j<n ; ++j)
		{
			temp += A[i][j]*X[j] ;
		}
		if (fabs(temp-C[i])>epsilon) verify=0 ;
	}
	if (verify) printf ("\n\n>>>> The solution is correct.\n") ;
	else printf ("\n\n>>>> The solution is incorrect.\n") ; 
  return 0;    
}

