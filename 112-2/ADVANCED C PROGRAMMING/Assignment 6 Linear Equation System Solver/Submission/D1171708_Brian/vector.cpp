#include <iostream>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "vector.h"

// Vector constructor with size definition.
Vector::Vector(int n) {
  if (n > 0) {
    row = n;
    col = 1;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = nullptr;
  }
}

// Copy constructor from a matrix and a column index
Vector::Vector(const Matrix &n, const int j) {
  int i;
  if (j >= 0 && j < n.getCol()) {
    row = n.getRow();
    col = 1;
    allocateMatrix();
    for (i = 0; i < row; i++) m[i][0] = n.getElement(i, j);
  }
  else {
    std::cout << "The column index is out of range." << endl << endl;
    row = 0;
    col = 0;
    m = nullptr;
  }
}

// Vector copy constructor
Vector::Vector(const Vector &v) {
  int i;
  
  if (v.row > 0 && v.col == 1) {
    row = v.row;
    col = v.col;
    allocateMatrix();
    for (i = 0; i < row; i++) {
      m[i][0] = v.m[i][0];
    }
  }
  else {
    row = 0;
    col = 0;
    m = nullptr;
  }
}

// Redefine vector size.
void Vector::setSize(int r) {
  if (r > 0) {
    if (m != nullptr) deallocateMatrix();
    row = r;
    col = 1;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = nullptr;
  }
}

// Replace a column of a matrix by the vector
Matrix Vector::vector_replace(int colIndex, const Matrix& mat) const {
    if (mat.getRow() != row) {
        std::cout << "Matrix row size do not match vector size." << std::endl;
        return mat; 
    }
    Matrix result(mat);
    for (int i = 0; i < row; ++i) {
        result.setElement(i, colIndex, m[i][0]);
    }
    return result;
}

