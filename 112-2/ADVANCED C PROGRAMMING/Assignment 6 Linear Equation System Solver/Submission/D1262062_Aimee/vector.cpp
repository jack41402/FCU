#include <iostream>

using namespace std;

#include "vector.h"

Vector::Vector(int n): Matrix(n,1) {}

Vector::Vector(const Matrix &M, const int c) {
	int r;
	if (c <= 0 && c < M.getCol()) {
		row = M.getRow();
		col = 1;
		allocateMatrix();
		for(r=0; r<row; r++) m[r][0] = M.getElement(r, c);
	}
	else {
	    cout << "The column index is out of range." << endl << endl;
	    row = 0;
	    col = 0;
	    m = NULL;
	}
}

Vector::Vector(const Vector &v) {
	if(v.row > 0 && v.col == 1) {
		row = v.row;
		col = v.col;
		allocateMatrix();
		for(int r=0; r<row; r++)
        	m[r][0] = v.m[r][0];
	}
	else {
    	row = 0;
    	col = 0;
    	m = NULL;
	}	
}

void Vector::setSize(int r) {
	if(r>0){
		Matrix::setSize(r, 1);
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}

SMatrix Vector::vector_replace(int c, const SMatrix& M) const{
	SMatrix result(M);
    if (c >= 0 && c < M.getCol() && M.getRow() == row) {
        for (int i=0; i<row; ++i) {
            result.setElement(i, c, getElement(i, 0));
        }
    } 
	else {
        cout << "Invalid replacement operation." << endl;
    }
    return result;
}


