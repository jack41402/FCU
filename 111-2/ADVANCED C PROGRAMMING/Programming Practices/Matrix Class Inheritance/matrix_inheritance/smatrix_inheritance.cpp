#include <iostream>
#include <math.h>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "smatrix_inheritance.h"

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
  double d=0.0;
  int j, p, q;
  
  if (row == 1) {d = m[0][0];}
  else if (row > 1) {
    SMatrix cofactor;
    cofactor.setSize(row - 1);
    for (j=0; j<row; j++) {
      for (p=0; p<row-1; p++) {
        for (q=0; q<row-1; q++) {
          if (q<j) cofactor.setElement(p, q, m[p+1][q]);
          if (q>=j) cofactor.setElement(p, q, m[p+1][q+1]);
        }
      }          
      d = d + pow(-1, j % 2 ) * m[0][j] * cofactor.determinant();
    }
  }
  else std::cout << "The matrix is empty." << endl << endl;
  return d;
}
