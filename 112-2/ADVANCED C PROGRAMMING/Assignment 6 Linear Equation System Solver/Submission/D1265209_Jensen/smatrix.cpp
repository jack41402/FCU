#include "smatrix.h"
#include <stdexcept>

// Constructor for square matrix of given size
SMatrix::SMatrix(int size) : Matrix(size, size) {}

// Constructor that takes a Matrix and ensures it is square
SMatrix::SMatrix(const Matrix& mat) : Matrix(mat) {
    if (mat.getRow() != mat.getCol()) {
        throw invalid_argument("Matrix must be square");
    }
}

// Copy constructor
SMatrix::SMatrix(const SMatrix& other) : Matrix(other) {}

// Set the size of the square matrix
void SMatrix::setSize(const int size) {
    Matrix::setSize(size, size);
}

// Calculate the determinant of the square matrix
double SMatrix::determinant() const {
    if (row != col) {
        throw invalid_argument("Matrix must be square");
    }
    if (row == 1) { // Base case for 1x1 matrix
        return m[0][0];
    }
    if (row == 2) { // Base case for 2x2 matrix
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }
    double det = 0;
    for (int p = 0; p < col; p++) { // Expansion by first row
        SMatrix subMatrix(row - 1); // Submatrix for minor
        for (int i = 1; i < row; i++) {
            int subi = 0;
            for (int j = 0; j < col; j++) {
                if (j == p) continue; // Skip column p
                subMatrix.m[i-1][subi] = m[i][j];
                subi++;
            }
        }
        // Recursive call and alternating sign
        det += (p % 2 == 0 ? 1 : -1) * m[0][p] * subMatrix.determinant();
    }
    return det;
}
