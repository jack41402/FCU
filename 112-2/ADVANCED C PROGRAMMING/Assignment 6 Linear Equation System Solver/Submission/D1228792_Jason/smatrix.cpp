#include <iostream>
#include <math.h>
#include "smatrix.h"
using namespace std;

// Constructor for SMatrix class with size n
SMatrix::SMatrix(int n) {
    if (n > 0) {
        row = n;
        col = n;
        allocateMatrix();
    } 
	else {
        row = 0;
        col = 0;
        m = NULL;
    }
}

// Constructor for SMatrix class from a general Matrix object
SMatrix::SMatrix(const Matrix &m2) {
    int i, j;
    if (m2.getCol() == m2.getRow()) { // Ensure the matrix is square
        row = m2.getRow();
        col = row;
        allocateMatrix();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                m[i][j] = m2.getElement(i, j);
            }
        }
    } 
	else {
        cout << "The matrix is not a square matrix." << endl << endl;
        row = 0;
        col = 0;
        m = NULL;
    }
}

// Copy constructor for SMatrix class
SMatrix::SMatrix(const SMatrix &s) {
    int i, j;
    if (s.getCol() > 0 && s.getRow() > 0) {
        row = s.getRow();
        col = s.getCol();
        allocateMatrix();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                m[i][j] = s.getElement(i, j);
            }
        }
    } 
	else {
        row = 0;
        col = 0;
        m = NULL;
    }
}

// Set size for SMatrix, ensuring it is square
void SMatrix::setSize(const int n) {
    if (n > 0) {
        if (m != NULL) {
            deallocateMatrix();
        }
        row = n;
        col = n;
        allocateMatrix();
    } 
	else {
        row = 0;
        col = 0;
        m = NULL;
    }
}

// Calculate the determinant of the square matrix
double SMatrix::determinant() const {
    double d = 0.0;
    int i, j, k;
    if (row == 1) {
        d = m[0][0];
    } else if (row > 1) {
        SMatrix co; // Create cofactor matrix
        co.setSize(row - 1);
        for (i = 0; i < row; i++) {
            for (j = 0; j < row - 1; j++) {
                for (k = 0; k < row - 1; k++) {
                    if (i > k) {
                        co.setElement(j, k, m[j + 1][k]);
                    } 
					else {
                        co.setElement(j, k, m[j + 1][k + 1]);
                    }
                }
            }
            d = d + pow(-1, i % 2) * m[0][i] * co.determinant(); // Recursive calculation
        }
    }
    return d;
}




