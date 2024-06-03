#include "smatrix.h"

// default square matrix constructor
SMatrix::SMatrix(int size) : Matrix(size, size) {}

// copy constructor from a matrix
SMatrix::SMatrix(const Matrix& other) : Matrix(other) {
    if (row != col) {
        cout << "Matrix must be square\n";
    }
}

// copy constructor from a square matrix
SMatrix::SMatrix(const SMatrix& other) : Matrix(other) {}

// set the size of a square matrix
void SMatrix::setSize(const int size) {
    Matrix::setSize(size, size);
}

// helper function to compute the determinant recursively
double determinantRecursive(double** mat, int n) {
    if (n == 1) {
        return mat[0][0];
    }
    if (n == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    double det = 0;
    for (int p = 0; p < n; ++p) {
        int subi = 0;
        double** subMat = new double* [n - 1];
        for (int i = 1; i < n; ++i) {
            subMat[subi] = new double[n - 1];
            int subj = 0;
            for (int j = 0; j < n; ++j) {
                if (j == p) continue;
                subMat[subi][subj++] = mat[i][j];
            }
            subi++;
        }
        det += (p % 2 == 0 ? 1 : -1) * mat[0][p] * determinantRecursive(subMat, n - 1);
        for (int i = 0; i < n - 1; ++i) {
            delete[] subMat[i];
        }
        delete[] subMat;
    }
    return det;
}

// determinant function
double SMatrix::determinant() const {
    if (row != col) {
       cout<<"Matrix must be square\n";
    }

    double** matCopy = new double* [row];
    for (int i = 0; i < row; ++i) {
        matCopy[i] = new double[col];
        for (int j = 0; j < col; ++j) {
            matCopy[i][j] = m[i][j];
        }
    }

    double det = determinantRecursive((double**)matCopy, row);

    for (int i = 0; i < row; ++i) {
        delete[] matCopy[i];
    }
    delete[] matCopy;

    return det;
}
