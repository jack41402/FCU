#include "smatrix.h"
#include <cmath>
#include <iostream>

using namespace std;

SMatrix::SMatrix(int n) : Matrix(n, n){
}

SMatrix::SMatrix(const Matrix& M) : Matrix(M){
}

SMatrix::SMatrix(const SMatrix& S){
	this->row = S.row;
	this->col = S.col;
	this->allocateMatrix();
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			this->m[i][j] = S.m[i][j];
		}
	}
}

void SMatrix::setSize(const int n){
	Matrix::setSize(n, n);
}

double SMatrix::determinant() const {
    double d = 0;
    if(this->row == 1){
        d = m[0][0];
    }
    else if(this->row > 1){
        SMatrix cofactor;
        cofactor.setSize(this->row - 1);
        for(int j = 0; j < row; j++) {
            for(int p = 0; p < row-1; p++) {
                for(int q = 0; q < row-1; q++) {
                    if(q < j) cofactor.setElement(p, q, m[p+1][q]);
                    if(q >= j) cofactor.setElement(p, q, m[p+1][q+1]);
                }
            }          
            d += pow(-1, j % 2) * m[0][j] * cofactor.determinant();
        }
    }
    else{
        cout << "The matrix is empty.\n\n";
    }
    return d;
}
