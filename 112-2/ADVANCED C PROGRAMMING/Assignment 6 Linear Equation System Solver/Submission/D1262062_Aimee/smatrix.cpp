#include <iostream>
#include <math.h>
#include "smatrix.h"

using namespace std;

SMatrix::SMatrix(int n): Matrix(n,n) {}

SMatrix::SMatrix(const Matrix &M) {
	if(M.getRow() == M.getCol()) {
		row = M.getRow();
		col = row;
		allocateMatrix();
		for(int i=0; i<row; i++) {
	      	for(int j=0; j<col; j++)
	        	m[i][j] = M.getElement(i, j);
	    }
	}	
	else {
		cout << "The matrix is not a square matrix." << endl << endl;
    	row = 0;
    	col = 0;
    	m = NULL;
	}	
}

SMatrix::SMatrix(const SMatrix& s): Matrix(s){}

void SMatrix::setSize(const int n) {
	if(n>0){
		Matrix::setSize(n, n);
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}

double SMatrix::determinant() const {
	double d = 0.0;
	if(row == 1) d = m[0][0];
	else if(row > 1) {
		SMatrix cofactor(row - 1);
        for(int j=0; j<row; j++) {
            for(int p=1; p<row; p++) {
                int colIndex = 0;
                for(int q=0; q<row; q++) {
                    if(q == j) continue;
                    cofactor.setElement(p-1, colIndex, m[p][q]);
                    colIndex++;
                }
            }
            d += pow(-1, j) * m[0][j] * cofactor.determinant();
		}
	}
	else cout << "The matrix is empty." << endl << endl;
	return d;
}
