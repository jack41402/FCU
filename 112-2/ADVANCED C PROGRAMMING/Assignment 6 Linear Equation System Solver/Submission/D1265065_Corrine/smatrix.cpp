//
//  smatrix.cpp
//  Assignment6_D1265065
//
//  Created by Corrine  on 2024/5/20.
//

#include "smatrix.h"
#include <iostream>
#include <cmath>
using namespace std;
// Default square matrix constructor
SMatrix::SMatrix(int size) : Matrix(size, size) {}

// Copy constructor from a matrix
SMatrix::SMatrix(const Matrix &m) : Matrix(m) {
    if (m.getRow() != m.getCol()) {
        cout << "Matrix must be square";
    }
}

// Copy constructor from a square matrix
SMatrix::SMatrix(const SMatrix &other) : Matrix(other) {}

// Set the size of a square matrix
void SMatrix::setSize(const int size) {
    Matrix::setSize(size, size);
}

// Determinant function
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
