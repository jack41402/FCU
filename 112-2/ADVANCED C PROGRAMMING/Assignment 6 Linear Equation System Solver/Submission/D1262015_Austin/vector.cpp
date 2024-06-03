#include "vector.h"
#include <stdexcept>

// Default constructor
Vector::Vector(int size) : Matrix(size,1) {}

// Constructor with a matrix and column index
Vector::Vector(const Matrix& matrix, const int colIndex) : Matrix(matrix.getRow(), 1) {
    if (colIndex >= matrix.getCol()) {
        throw std::out_of_range("Column index out of range");
    }
    for (int i = 0; i < matrix.getRow(); ++i) {
        m[i][0] = matrix.getElement(i, colIndex);
    }
}

// Copy constructor
Vector::Vector(const Vector& other) : Matrix(other) {}

// Set the size of the vector
void Vector::setSize(const int size) {
    Matrix::setSize(size, 1);
}

// Replace a column of the matrix with the vector
Matrix Vector::vector_replace(int colIndex, const Matrix& matrix) const {
    if (matrix.getRow() != this->row) {
        throw std::invalid_argument("Matrix row size must match vector size");
    }
    Matrix result(matrix);
    for (int i = 0; i < row; ++i) {
        result.setElement(i, colIndex, this->m[i][0]);
    }
    return result;
}
