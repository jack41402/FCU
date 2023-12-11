#include <iostream>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "vector_inheritance.h"

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

// Matrix to vector converter.
Vector::Vector(const Matrix &n) {
  int i;
  if (n.getCol()==1) {
    row = n.getRow();
    col = 1;
    allocateMatrix();
    for (i=0; i<row; i++) m[i][0] = n.getElement(i, 0);
  }
  else {
    std::cout << "The matrix is not a column vector." << endl << endl;
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

// Inner product of two vectors
double Vector::operator*(const Vector &v) const {
  double ip = 0.0;
  int i;
  
  if (row>0 && v.row>0) {
    if (row==v.row) {
      for (i=0; i<row; i++) {
        ip += m[i][0] * v.m[i][0];
      }
    }
    else {
      cout << "Vector lengths do not match." << endl << endl;
      ip = -999;
    }
  }
  else {
    cout << "Vector length must be a positive integer." << endl << endl;
    ip = -999;
  }
  return ip;
}
