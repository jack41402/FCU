#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printMatrix(int** matrix, int m, int n, int lowband, int upband){
	int i, j;
	for(i = 0 ; i < m ; i++){
		for(j = 0 ; j < n ; j++){
			if(j >= i - lowband && j <= i + upband){
				printf("%4d", matrix[i][j]);
			}else{
				printf("    ");
			}
		}
		printf("\n    ");
	}
	printf("\n");
}
void transposeMatrix(int** x, int** y, int m, int n, int lowband, int upband){
	int i, j;
	for(i = 0 ; i < m ; i++){
		for(j = 0 ; j < n ; j++){
			y[j][i] = x[i][j];
		}
	}	
}
int main(){
	int m, n, r, s, lowband, upband;
	printf(">>>>> Enter matrix size of matrix A, m and n (between 1 and 20, including): ");
	scanf("%d %d", &m, &n);
	printf("\n");
	printf(">>>>> Enter the lower and the upper bandwidth of matrix A, r and s: ");
	scanf("%d %d", &r, &s);
	printf("\n");
	int** matrix_A = (int**)malloc(m * sizeof(int*));
	int i, j;
	for(i = 0 ; i < m ; i++){
		matrix_A[i] = (int**)malloc(n * sizeof(int));
		for(j = 0 ; j < n ; j++){
			matrix_A[i][j] = (j >= i - r && j <= i + s) ? rand() % 100 : 0;
		}
	}
	int** matrix_B = (int**)malloc(n * sizeof(int*));
	for(i = 0 ; i < n ; i++){
		matrix_B[i] = (int**)malloc(m * sizeof(int));
	}
	transposeMatrix(matrix_A, matrix_B, m, n, r, s);
	printf("Matrix A, %dX%d with lower bandwidth %d and upper bandwidth %d:\n    ", m, n, r, s);
	printMatrix(matrix_A, m, n, r, s);
	printf("Matrix B, %dX%d with lower bandwidth %d and upper bandwidth %d:\n    ", n, m, s, r);
	printMatrix(matrix_B, n, m, s, r);
	for(i = 0 ; i < m ; i++){
		free(matrix_A[i]);
	}
	free(matrix_A);
	for(i = 0; i < n ; i++){
		free(matrix_B[i]);
	}
	free(matrix_B);
	return 0;
}
