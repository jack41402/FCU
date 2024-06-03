#include "smatrix.h"

// Constructor that initializes an SMatrix with the same number of rows and columns (square matrix)
SMatrix::SMatrix(int r) : Matrix(r, r) {}

// Constructor that initializes an SMatrix from a given Matrix if it is square
SMatrix::SMatrix(const Matrix &M) {
    int i, j;
    if (M.getRow() == M.getCol()) {
        row = col = M.getRow();
        allocateMatrix();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                m[i][j] = M.getElement(i, j);
            }
        }
    }
}

// Copy constructor for SMatrix
SMatrix::SMatrix(const SMatrix &S) {
    int i, j;
    row = col = S.row;
    allocateMatrix();
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            m[i][j] = S.m[i][j];
        }
    }
}

// Set the size of the SMatrix (square matrix)
void SMatrix::setSize(const int r) {
    Matrix::setSize(r, r);
}

// Calculate the determinant of the SMatrix
double SMatrix::determinant() const {
    if (row != col) {
        return 0; // Determinant is not defined for non-square matrices
    }
    if (row == 1) {
        return m[0][0]; // Determinant of a 1x1 matrix is the element itself
    } else if (row == 2) {
        // Determinant of a 2x2 matrix is ad - bc
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    } else {
        double det = 0;
        for (int i = 0; i < row; ++i) {
            SMatrix subMatrix(row - 1); // Create a submatrix
            for (int j = 1; j < row; ++j) {
                for (int k = 0, l = 0; k < row; ++k) {
                    if (k == i) continue; // Skip the current column
                    subMatrix.m[j - 1][l++] = m[j][k];
                }
            }
            double cofactor = subMatrix.determinant();
            if (i % 2 == 1) {
                cofactor = -cofactor; // Apply the sign based on column index
            }
            det += m[0][i] * cofactor; // Sum up the cofactors
        }
        return det;
    }
}

