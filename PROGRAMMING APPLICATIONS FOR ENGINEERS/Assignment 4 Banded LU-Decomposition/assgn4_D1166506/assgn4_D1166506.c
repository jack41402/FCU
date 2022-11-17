#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int n , r , s , flag=1 ;
double A[100][100]={0} , L[100][100]={0} , U[100][100]={0} , temp[100][100]={0};

int min (int a , int b)
{
    return (a>b) ? b : a ;
}

int max (int a , int b)
{
    return (a>b) ? a : b ;
}

void LU_decompose()
{
    for (int k=0 ; k<n ; k++)
    {
        for (int j=k ; j<=min (n-1 , k+s) ; j++) U[k][j] = A[k][j] ; // Compute elements of the k-th row of matrix U
        for (int i=k ; i<=min (n-1 , k+r) ; i++) L[i][k] = A[i][k] / A[k][k] ; // Compute elements of the k-th column of matrix L
        for (int i=k+1 ; i<=min (n-1 , k+r) ; i++) // Compute elements of submatrix A(k+1):
            for (int j=max (k+1 , i-r) ; j<=min (n-1 , min (i+s , k+s)) ; j++) A[i][j] = A[i][j] - L[i][k] * U[k][j] ;
    }
}

int main()
{
    printf ("Enter matrix size n: ") , fflush(stdout) ;
    scanf ("%d" , &n) ;
    printf ("Enter the lower bandwidth and the of matrix A, (r, s): ") , fflush(stdout) ;
    scanf ("%d %d" , &r , &s) ;
    srand (0) ;

    printf ("\n\nMatrix A:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<max (0 , i-r) ; ++j) printf ("        ") ;
        for (int j=max (0 , i-r) ; j<=min (n-1 , i+s) ; ++j)
        {
            A[i][j] = (rand() % 10000 + 1) / 10000.0 ;
            temp[i][j] = A[i][j] ;
            printf ("%8.4lf" , A[i][j]) ;
        }
        printf ("\n") ;
    }
    LU_decompose() ;
    printf ("\n\nMatrix L:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<max (0 , i-r) ; ++j) printf ("        ") ;
        for (int j=max (0 , i-r) ; j<=i ; ++j) printf ("%8.4lf" , L[i][j]) ;
        printf ("\n") ;
    }
    printf ("\n\nMatrix U:\n") ;
    for (int i=0 ; i<n ; ++i)
    {
        for (int j=0 ; j<i ; ++j) printf ("        ") ;
        for (int j=i ; j<=min(n-1 ,i+s) ; ++j) printf ("%8.4lf" , U[i][j]) ;
        printf ("\n") ;
    }

    for (int i=0 ; i<n && flag ; ++i)
        for (int j=0 ; j<n && flag ; ++j)
        {
            A[i][j] = 0 ;
            for (int k=0 ; k<=min(i , j) ; ++k) A[i][j] += L[i][k] * U[k][j]; // Compute A[i][j] for A<=LU
            flag = flag && (fabs(A[i][j]-temp[i][j])<1e-4); // Compare A[i][j] and A1[i][j], allow error 0.0001.
        }

    if (flag) printf("\nThe LU-decomposition program is correct.\n"); // The program is correct.
    else printf("\nThe LU-decomposition program is incorrect.\n"); // The program is incorrect.
    return 0;
}
