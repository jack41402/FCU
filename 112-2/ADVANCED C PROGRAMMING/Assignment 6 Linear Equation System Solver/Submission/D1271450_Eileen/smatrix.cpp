#include "smatrix.h"

//construct square matrix of given size
SMatrix::SMatrix(int size) : Matrix(size, size) {
}

//copy constructor from Matrix
SMatrix::SMatrix(const Matrix &other) : Matrix(other) {
}

//copy constructor from SMatrix
SMatrix::SMatrix(const SMatrix &other) : Matrix(other) {
}

//set the size of the square matrix
void SMatrix::setSize(const int size) {
    Matrix::setSize(size, size); //set both dimensions to the same value
}

//calculate the determinant of the square matrix
double SMatrix::determinant() const {
    int n = this->getRow(); //assuming square matrix, get number of rows or columns

    //base case for 1x1 matrix
    if (n == 1) {
        return this->getElement(0, 0);
    }

    //base case for 2x2 matrix
    if (n == 2) {
        return this->getElement(0, 0) * this->getElement(1, 1) - this->getElement(0, 1) * this->getElement(1, 0);
    }

    //recursive expansion by minors for larger matrices
    double det = 0.0;
    for (int p = 0; p < n; p++) {
        //minor's create submatrix
        SMatrix subMatrix(n - 1);
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                subMatrix.setElement(i - 1, sub_j, this->getElement(i, j));
                sub_j++;
            }
        }
        double subDet = subMatrix.determinant();
        //expansion's alternate signs
        det += (p % 2 == 0 ? 1 : -1) * this->getElement(0, p) * subDet;
    }
    return det;
}

