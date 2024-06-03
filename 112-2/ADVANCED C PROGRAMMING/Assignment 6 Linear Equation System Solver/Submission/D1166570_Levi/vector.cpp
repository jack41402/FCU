#include "vector.h"

// default vector constructor
Vector::Vector(int size) : Matrix(size, 1) {}

// copy constructor from a matrix a column index
Vector::Vector(const Matrix& other, const int colIndex) : Matrix(other.getRow(), 1) {
    if (colIndex < 0 || colIndex >= other.getCol()) {
        cout<<"Column index out of range\n";
    }
    for (int i = 0; i < row; ++i) {
        m[i][0] = other.getElement(i, colIndex);
    }
}

// copy constructor from a vectori 
Vector::Vector(const Vector& other) : Matrix(other) {}

// set the size of a vector
void Vector::setSize(const int size) {
    Matrix::setSize(size, 1);
}

// Replace a column of a matrix by the vector
Matrix Vector::vector_replace(int colIndex, const Matrix& t) {
    if (colIndex < 0 || colIndex >= t.getCol()) {
        cout<<"Column index out of range\n";
    }
    if (t.getRow() != row) {
        cout<<"Matrix row size must match vector size\n";
    }

    Matrix result(t);
    for (int i = 0; i < row; ++i) {
        result.setElement(i, colIndex, m[i][0]);
    }
    return result;
}
