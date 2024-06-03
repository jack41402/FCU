#ifndef SMATRIX_H
#define SMATRIX_H

#include "matrix.h"

// SMatrix class inheriting from Matrix
class SMatrix : public Matrix {
public:
    // Constructor for square matrix with optional size parameter
    SMatrix(int size = 0);

    // Constructor that takes a Matrix and ensures it is square
    SMatrix(const Matrix& matrix);

    // Copy constructor
    SMatrix(const SMatrix& other);

    // Set the size of the square matrix
    void setSize(const int size);

    // Calculate the determinant of the square matrix
    double determinant() const;
};

#endif

