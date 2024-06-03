#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

// Vector subclass, representing a column vector.
class Vector : public Matrix {
public:
    Vector(int size = 0); // default vector constructor
    Vector(const Matrix& matrix, const int colIndex); // copy constructor from a matrix and a column index
    Vector(const Vector& other); // copy constructor from a vector
    void setSize(const int size); // set the size of a vector
    Matrix vector_replace(int colIndex, const Matrix& matrix) const; // Replace a column of a matrix by the vector
};

#endif

