#include<iostream>
#include<math.h>
#include"smatrix.h"
//Square matrix constructor with size definition
SMatrix::SMatrix(int a){
	if (a>0){
		row = a;
		col = a;
		allocateMatrix();
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	} 
}
//Matrix to square matrix converter
SMatrix::SMatrix(const Matrix& n){
	int i, j;
	if (n.getRow()==n.getCol()){
		row = n.getRow();
		col = row;
		allocateMatrix();
		for (i = 0; i<row; i++){
			for (j = 0; j<col; j++){
				m[i][j] = n.getElement(i, j);
			}
		}
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//Vector copy constructor
SMatrix::SMatrix(const SMatrix& s){
	int i, j;
	if (s.getRow()>0 && s.getCol()>0){
		row = s.getRow();
		col = s.getCol();
		allocateMatrix();
		for (i = 0; i<row; i++){
			for (j = 0; j<col; j++){
				m[i][j] = s.getElement(i, j);
			}
		} 
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//Redefine square matrix size
void SMatrix::setSize(const int a){
	if (a>0){
		if (m!=NULL){
			deallocateMatrix();
		}
	row = a;
	col = a;
	allocateMatrix();
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//Compute determinant of a square matrix
double SMatrix::determinant()const{
	double a = 0.0;
	int i, j, k;
	if (row==1){
		a = m[0][0];
	}
	else if (row>1){
		SMatrix cofactor;
		cofactor.setSize(row - 1);
		for (i = 0; i<row; i++){
			for (j = 0; j<row-1; j++){
				for (k = 0; k<row-1; k++){
					if (k<i){
						cofactor.setElement(j, k, m[j+1][k]);
					}
					if (k>=i){
						cofactor.setElement(j, k, m[j+1][k+1]);
					}
				}
			}
			a = a + pow(-1, i%2)*m[0][i]*cofactor.determinant();
		}
	}
	return a;
}
