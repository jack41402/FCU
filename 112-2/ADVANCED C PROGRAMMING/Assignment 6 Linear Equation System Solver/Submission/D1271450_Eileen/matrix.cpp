#include "matrix.h"
#include <iostream>
//allocates matrix elements's memory
void Matrix::allocateMatrix() {
    m = new double*[row];
    for (int i = 0; i < row; i++) {
        m[i] = new double[col];
    }
}
//deallocates matrix elements's memory 
void Matrix::deallocateMatrix() {
    for (int i = 0; i < row; i++) {
        delete[] m[i];
    }
    delete[] m;
}
//initialize matrix with given rows and columns
Matrix::Matrix(int r, int c) : row(r), col(c) {
    allocateMatrix();
}
//create a matrix from another matrix
Matrix::Matrix(const Matrix &other) : row(other.row), col(other.col) {
    allocateMatrix();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            m[i][j] = other.m[i][j];
        }
    }
}
//clean up allocated memory
Matrix::~Matrix() {
    deallocateMatrix();
}
//resizes the matrix to the new number of rows and columns
void Matrix::setSize(int r, int c) {
    deallocateMatrix();
    row = r;
    col = c;
    allocateMatrix();
}
//sets the element of i, j to the given value
void Matrix::setElement(int i, int j, double value) {
    m[i][j] = value;
}
//get the element at position i, j
double Matrix::getElement(int i, int j) const {
    return m[i][j];
}
//gets the number of rows in the matrix
int Matrix::getRow() const {
    return row;
}
//gets the number of columns in the matrix
int Matrix::getCol() const {
    return col;
}
//matrix addition
Matrix Matrix::operator+(const Matrix &other) const {
    Matrix result(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.m[i][j] = m[i][j] + other.m[i][j];
        }
    }
    return result;
}
//matrix subtraction
Matrix Matrix::operator-(const Matrix &other) const {
    Matrix result(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.m[i][j] = m[i][j] - other.m[i][j];
        }
    }
    return result;
}
//matrix multiplication
Matrix Matrix::operator*(const Matrix &other) const {
    Matrix result(row, other.col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < other.col; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < col; k++) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}
//scalar addition
Matrix Matrix::operator+(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.m[i][j] = m[i][j] + scalar;
        }
    }
    return result;
}
//scalar subtraction
Matrix Matrix::operator-(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.m[i][j] = m[i][j] - scalar;
        }
    }
    return result;
}
//scalar multiplication
Matrix Matrix::operator*(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.m[i][j] = m[i][j] * scalar;
        }
    }
    return result;
}
//equality comparison
bool Matrix::operator==(const Matrix &other) const {
    if (row != other.row || col != other.col) {
        return false;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] != other.m[i][j]) {
                return false;
            }
        }
    }
    return true;
}
//inequality comparison
bool Matrix::operator!=(const Matrix &other) const {
    return !(*this == other);
}
//assignment operator overload
Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        setSize(other.row, other.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                m[i][j] = other.m[i][j];
            }
        }
    }
    return *this;
}
//compound assignment for matrix addition
Matrix &Matrix::operator+=(const Matrix &other) {
    *this = *this + other;
    return *this;
}
// Compound assignment for matrix subtraction
Matrix &Matrix::operator-=(const Matrix &other) {
    *this = *this - other;
    return *this;
}
//compound assignment for matrix multiplication
Matrix &Matrix::operator*=(const Matrix &other) {
    *this = *this * other;
    return *this;
}
// unary minus
Matrix Matrix::operator-() const {
    Matrix result(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.m[i][j] = -m[i][j];
        }
    }
    return result;
}

