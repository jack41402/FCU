#include "vector.h"
#include <stdexcept> // for exception handling

using namespace std;

// Default constructor
Vector::Vector(int size) : Matrix(size, 1) {}

// Copy constructor from a matrix and a column index
Vector::Vector(const Matrix& mat, const int colIndex) : Matrix(mat.getRow(), 1) {
    if (colIndex < 0 || colIndex >= mat.getCol()) {
        throw invalid_argument("Column index out of bounds.");
    }
    for (int i = 0; i < mat.getRow(); ++i) {
        m[i][0] = mat.getElement(i, colIndex);
    }
}

// Copy constructor from a vector
Vector::Vector(const Vector& vec) : Matrix(vec) {}

// Set the size of the vector
void Vector::setSize(const int size) {
    Matrix::setSize(size, 1);
}

// Replace a column of a matrix with the vector
Matrix Vector::vector_replace(int colIndex, const Matrix& mat) {
    if (colIndex < 0 || colIndex >= mat.getCol()) {
        throw invalid_argument("Column index out of bounds.");
    }
    if (getRow() != mat.getRow()) {
        throw invalid_argument("Vector and matrix row sizes do not match.");
    }

    Matrix result(mat);
    for (int i = 0; i < getRow(); ++i) {
        result.setElement(i, colIndex, m[i][0]);
    }
    return result;
}

