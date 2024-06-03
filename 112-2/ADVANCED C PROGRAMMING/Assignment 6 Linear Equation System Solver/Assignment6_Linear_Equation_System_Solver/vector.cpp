#include <iostream>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "matrix.h"
#include "vector.h"

// Vector constructor with size definition.
Vector::Vector(int n) {
  if (n>0) {
    row = n;
    col = 1;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Copy constructor from a matrix and a column index
Vector::Vector(const Matrix &n, const int j) {
  int i;
  if (i<=0 && i<n.getCol()) {
    row = n.getRow();
    col = 1;
    allocateMatrix();
    for (i=0; i<row; i++) m[i][0] = n.getElement(i, j);
  }
  else {
    std::cout << "The column index is out of range." << endl << endl;
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Vector copy constructor
Vector::Vector(const Vector &v) {
  int i;
  
  if (v.row>0 && v.col==1) {
    row = v.row;
    col = v.col;
    allocateMatrix();
    for (i=0; i<row; i++) {
      m[i][0] = v.m[i][0];
    }
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Redefine vector size.
void Vector::setSize(int r) {
  if (r>0) {
    if (m != NULL) deallocateMatrix();
    row = r;
    col = 1;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Replace the k-th column of matrix M by this vector
Matrix Vector::vector_replace(int k, const Matrix& M) {
	Matrix result; // The resulting matrix.
	int r = M.getRow(), c = M.getCol();
	int i, j; // Loop variable.
	
  if (k<0 || k>=r) cout << "Column " << k << " does not exist." << endl;
	else if (row!=r) cout << "Column size does not match." << endl; 
	else {
		result.setSize(r, c);
		for (i=0; i<r; i++)
			for (j=0; j<c; j++)
				if (j!=k) result.setElement(i, j, M.getElement(i, j));
				else result.setElement(i, j, this->getElement(i, 0));
	}
	return result;
}
