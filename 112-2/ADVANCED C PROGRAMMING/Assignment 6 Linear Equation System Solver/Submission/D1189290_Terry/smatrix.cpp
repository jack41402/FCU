#include "smatrix.h"
#include <cmath> // Include cmath for fabs function
#include <stdexcept> // for exception handling

using namespace std;

// Default constructor
SMatrix::SMatrix(int size) : Matrix(size, size) {}

// Copy constructor from a matrix
SMatrix::SMatrix(const Matrix& other) : Matrix(other) {
    if (other.getRow() != other.getCol()) {
        throw invalid_argument("Matrix is not square.");
    }
}

// Copy constructor from a square matrix
SMatrix::SMatrix(const SMatrix& other) : Matrix(other) {}

// Set the size of the square matrix
void SMatrix::setSize(const int size) {
    Matrix::setSize(size, size);
}

// Function to compute the determinant of the square matrix
double SMatrix::determinant() const {
    if (row != col) {
        throw invalid_argument("Matrix is not square.");
    }

    // Create a copy of the matrix elements for manipulation
    double** temp = new double*[row];
    for (int i = 0; i < row; ++i) {
        temp[i] = new double[col];
        for (int j = 0; j < col; ++j) {
            temp[i][j] = m[i][j];
        }
    }

    // Apply Gaussian elimination to find the determinant
    double det = 1;
    for (int i = 0; i < row; ++i) {
        // Find the pivot
        int pivot = i;
        for (int j = i + 1; j < row; ++j) {
            if (fabs(temp[j][i]) > fabs(temp[pivot][i])) { // Use fabs for floating point numbers
                pivot = j;
            }
        }

        // Swap rows if necessary
        if (i != pivot) {
            swap(temp[i], temp[pivot]);
            det *= -1;
        }

        // Multiply determinant by pivot element
        det *= temp[i][i];
        if (temp[i][i] == 0) {
            det = 0;
            break;
        }

        // Eliminate column below pivot
        for (int j = i + 1; j < row; ++j) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i; k < col; ++k) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    // Clean up the temporary matrix
    for (int i = 0; i < row; ++i) {
        delete[] temp[i];
    }
    delete[] temp;

    return det;
}

