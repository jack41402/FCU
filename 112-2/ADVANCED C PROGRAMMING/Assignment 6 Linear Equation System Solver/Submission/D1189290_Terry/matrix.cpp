#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Allocate matrix elements
void Matrix::allocateMatrix() {
    if(row > 0 && col > 0) {
        m = new double*[row];
        for(int i = 0; i < row; ++i) {
            m[i] = new double[col];
        }
    } else {
        m = NULL;
    }
}

// Deallocate matrix elements
void Matrix::deallocateMatrix() {
    if(m) {
        for(int i = 0; i < row; ++i) {
            delete[] m[i];
        }
        delete[] m;
        m = NULL;
    }
}

// Default constructor
Matrix::Matrix(int r, int c) : row(r), col(c) {
    allocateMatrix();
}

// Copy constructor
Matrix::Matrix(const Matrix& other) : row(other.row), col(other.col) {
    allocateMatrix();
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            m[i][j] = other.m[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix() {
    deallocateMatrix();
}

// Set matrix size
void Matrix::setSize(int r, int c) {
    deallocateMatrix();
    row = r;
    col = c;
    allocateMatrix();
}

// Set matrix element
void Matrix::setElement(int r, int c, double value) {
    if(r >= 0 && r < row && c >= 0 && c < col) {
        m[r][c] = value;
    }
}

// Get matrix element
double Matrix::getElement(int r, int c) const {
    if(r >= 0 && r < row && c >= 0 && c < col) {
        return m[r][c];
    }
    return 0.0; // Or throw an exception
}

// Get row size
int Matrix::getRow() const {
    return row;
}

// Get column size
int Matrix::getCol() const {
    return col;
}

// Overload operators for matrix operations

// Scalar-matrix addition
Matrix operator+(const double &scalar, const Matrix &mat) {
    Matrix result(mat.row, mat.col);
    for(int i = 0; i < mat.row; ++i) {
        for(int j = 0; j < mat.col; ++j) {
            result.m[i][j] = scalar + mat.m[i][j];
        }
    }
    return result;
}

// Scalar-matrix subtraction
Matrix operator-(const double &scalar, const Matrix &mat) {
    Matrix result(mat.row, mat.col);
    for(int i = 0; i < mat.row; ++i) {
        for(int j = 0; j < mat.col; ++j) {
            result.m[i][j] = scalar - mat.m[i][j];
        }
    }
    return result;
}

// Scalar-matrix multiplication
Matrix operator*(const double &scalar, const Matrix &mat) {
    Matrix result(mat.row, mat.col);
    for(int i = 0; i < mat.row; ++i) {
        for(int j = 0; j < mat.col; ++j) {
            result.m[i][j] = scalar * mat.m[i][j];
        }
    }
    return result;
}

// Output operator
ostream &operator<<(ostream &out, const Matrix &mat) {
    for(int i = 0; i < mat.row; ++i) {
        for(int j = 0; j < mat.col; ++j) {
            out << setw(10) << mat.m[i][j];
        }
        out << endl;
    }
    return out;
}

// Input operator
istream &operator>>(istream &in, Matrix &mat) {
    for(int i = 0; i < mat.row; ++i) {
        for(int j = 0; j < mat.col; ++j) {
            in >> mat.m[i][j];
        }
    }
    return in;
}

// Matrix-matrix addition
Matrix Matrix::operator+(const Matrix &other) const {
    if(row != other.row || col != other.col) {
        throw invalid_argument("Matrix dimensions must agree.");
    }
    Matrix result(row, col);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] + other.m[i][j];
        }
    }
    return result;
}

// Matrix-matrix subtraction
Matrix Matrix::operator-(const Matrix &other) const {
    if(row != other.row || col != other.col) {
        throw invalid_argument("Matrix dimensions must agree.");
    }
    Matrix result(row, col);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] - other.m[i][j];
        }
    }
    return result;
}

// Matrix-matrix multiplication
Matrix Matrix::operator*(const Matrix &other) const {
    if(col != other.row) {
        throw invalid_argument("Matrix dimensions must agree.");
    }
    Matrix result(row, other.col);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < other.col; ++j) {
            result.m[i][j] = 0;
            for(int k = 0; k < col; ++k) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}

// Matrix-scalar addition
Matrix Matrix::operator+(const double &scalar) const {
    Matrix result(row, col);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] + scalar;
        }
    }
    return result;
}

// Matrix-scalar subtraction
Matrix Matrix::operator-(const double &scalar) const {
    Matrix result(row, col);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] - scalar;
        }
    }
    return result;
}

// Matrix-scalar multiplication
Matrix Matrix::operator*(const double &scalar) const {
    Matrix result(row, col);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] * scalar;
        }
    }
    return result;
}

// Equal to relation
bool Matrix::operator==(const Matrix &other) const {
    if(row != other.row || col != other.col) {
        return false;
    }
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            if(m[i][j] != other.m[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Not equal to relation
bool Matrix::operator!=(const Matrix &other) const {
    return !(*this == other);
}

// Matrix assignment
Matrix &Matrix::operator=(const Matrix &other) {
    if(this != &other) {
        setSize(other.row, other.col);
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                m[i][j] = other.m[i][j];
            }
        }
    }
    return *this;
}

// Matrix assignment with addition
Matrix &Matrix::operator+=(const Matrix &other) {
    *this = *this + other;
    return *this;
}

// Matrix assignment with subtraction
Matrix &Matrix::operator-=(const Matrix &other) {
    *this = *this - other;
    return *this;
}

// Matrix assignment with multiplication
Matrix &Matrix::operator*=(const Matrix &other) {
    *this = *this * other;
    return *this;
}

// Interpret unary operation as matrix transposition
Matrix Matrix::operator-() const {
    Matrix result(col, row);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            result.m[j][i] = m[i][j];
        }
    }
    return result;
}

