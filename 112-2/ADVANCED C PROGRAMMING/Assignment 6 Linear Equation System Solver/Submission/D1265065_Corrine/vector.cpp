//
//  vector.cpp
//  Assignment6_D1265065
//
//  Created by Corrine  on 2024/5/20.
//
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ios;

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
    cout << "The column index is out of range." << endl << endl;
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

// Replace a column of a matrix by the vector
Matrix Vector::vector_replace(int colIndex, const Matrix &m) {

    if (this->getRow() != m.getRow()) {
        cout << "Vector and matrix row sizes must match";
    }

    Matrix result = m;
    for (int i = 0; i < m.getRow(); ++i) {
        result.setElement(i, colIndex, this->getElement(i, 0));
    }

    return result;
}
