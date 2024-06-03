#include <iostream>
#include <math.h>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "smatrix.h"

// Square matrix constructor with size definition.
SMatrix::SMatrix(int n) {
  if (n>0) {
    row = n;
    col = n;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Matrix to square matrix converter.
SMatrix::SMatrix(const Matrix &n) {
  int i, j;
  if (n.getRow()==n.getCol()) {
    row = n.getRow();
    col = row;
    allocateMatrix();
    for (i=0; i<row; i++)
      for (j=0; j<col; j++)
        m[i][j] = n.getElement(i, j);
  }
  else {
    cout << "The matrix is not a square matrix." << endl << endl;
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Vector copy constructor
SMatrix::SMatrix(const SMatrix& s) {
  int i, j;
  
  if (s.getRow()>0 && s.getCol()>0) {
    row = s.getRow();
    col = s.getCol();
    allocateMatrix();
    for (i=0; i<row; i++) {
      for (j=0; j<col; j++) {
        m[i][j] = s.getElement(i, j);
      }
    }
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Redefine square matrix size.
void SMatrix::setSize(const int n) {
  if (n>0) {
    if (m != NULL) deallocateMatrix();
    row = n;
    col = n;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Compute determinant of a square matrix
double SMatrix::determinant() const {
	SMatrix minor;
	double ans = 0.0;
	double det;
	int i, a, b;
	if(col == 1){
		ans = m[0][0];
	}
	else{
		minor.setSize(col-1);
		for(i=0; i<col; i++){
			for(a=1; a<col; a++){
				for(b=0; b<col; b++){
					if(b<i){
						minor.setElement(a-1, b, m[a][b]);
					}
					else if(b>i){
						minor.setElement(a-1, b-1, m[a][b]);
					}
				}
			}
			det = m[0][i] * pow(-1, i%2) * minor.determinant();
			ans += det;
		}
	}
	return ans;
}
