#include "matrix.h"
#include <stdexcept>

// Constructor, allocate memory and initialize matrix
Matrix::Matrix(int r, int c) : row(r), col(c) {
    allocateMatrix();
}

// Copy constructor, allocate memory and copy the contents of another matrix
Matrix::Matrix(const Matrix& other) : row(other.row), col(other.col) {
    allocateMatrix();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            m[i][j] = other.m[i][j];
        }
    }
}

// Destructor, release matrix memory
Matrix::~Matrix() {
    deallocateMatrix();
}

// Allocate memory for the matrix
void Matrix::allocateMatrix() {
    m = new double*[row];
    for (int i = 0; i < row; ++i) {
        m[i] = new double[col];
    }
}

// Release memory for the matrix
void Matrix::deallocateMatrix() {
    for (int i = 0; i < row; ++i) {
        delete[] m[i];
    }
    delete[] m;
}

// Set the size of the matrix and allocate memory
void Matrix::setSize(int r, int c) {
    deallocateMatrix();
    row = r;
    col = c;
    allocateMatrix();
}

// Set the value of a matrix element
void Matrix::setElement(int r, int c, double value) {
    if (r >= row || c >= col) {
        throw std::out_of_range("Index out of range");
    }
    m[r][c] = value;
}

// Get the value of a matrix element
double Matrix::getElement(int r, int c) const {
    if (r >= row || c >= col) {
        throw std::out_of_range("Index out of range");
    }
    return m[r][c];
}

// Get the number of rows in the matrix
int Matrix::getRow() const {
    return row;
}

// Get the number of columns in the matrix
int Matrix::getCol() const {
    return col;
}

// Matrix addition operator overloading
Matrix Matrix::operator+(const Matrix &other) const {
    if (row != other.row || col != other.col) {
        throw std::invalid_argument("Matrices must have the same dimensions to add");
    }
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] + other.m[i][j];
        }
    }
    return result;
}

// Matrix subtraction operator overloading
Matrix Matrix::operator-(const Matrix &other) const {
    if (row != other.row || col != other.col) {
        throw std::invalid_argument("Matrices must have the same dimensions to subtract");
    }
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] - other.m[i][j];
        }
    }
    return result;
}

// Matrix multiplication operator overloading
Matrix Matrix::operator*(const Matrix &other) const {
    if (col != other.row) {
        throw std::invalid_argument("Matrices must have compatible dimensions to multiply");
    }
    Matrix result(row, other.col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < other.col; ++j) {
            result.m[i][j] = 0.0;
            for (int k = 0; k < col; ++k) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}

// Matrix and scalar addition operator overloading
Matrix Matrix::operator+(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] + scalar;
        }
    }
    return result;
}

// Matrix and scalar subtraction operator overloading
Matrix Matrix::operator-(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] - scalar;
        }
    }
    return result;
}

// Matrix and scalar multiplication operator overloading
Matrix Matrix::operator*(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] * scalar;
        }
    }
    return result;
}

// Overloading equality comparison operator
bool Matrix::operator==(const Matrix &other) const {
    if (row != other.row || col != other.col) {
        return false;
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (m[i][j] != other.m[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Overloading inequality comparison operator
bool Matrix::operator!=(const Matrix &other) const {
    return !(*this == other);
}

// Overloading assignment operator
Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        deallocateMatrix();
        row = other.row;
        col = other.col;
        allocateMatrix();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                m[i][j] = other.m[i][j];
            }
        }
    }
    return *this;
}

// Overloading addition assignment operator
Matrix &Matrix::operator+=(const Matrix &other) {
    *this = *this + other;
    return *this;
}

// Overloading subtraction assignment operator
Matrix &Matrix::operator-=(const Matrix &other) {
    *this = *this - other;
    return *this;
}

// Overloading multiplication assignment operator
Matrix &Matrix::operator*=(const Matrix &other) {
    *this = *this * other;
    return *this;
}

// Overloading negation operator
Matrix Matrix::operator-() const {
    Matrix result(col, row);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[j][i] = m[i][j];
        }
    }
    return result;
}

// Overloading stream insertion operator
ostream &operator<<(ostream &out, const Matrix &mat) {
    for (int i = 0; i < mat.row; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            out << mat.m[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

// Overloading stream extraction operator
istream &operator>>(istream &in, Matrix &mat) {
    for (int i = 0; i < mat.row; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            in >> mat.m[i][j];
        }
    }
    return in;
}

// Scalar and matrix addition
Matrix operator+(const double &scalar, const Matrix &mat) {
    return mat + scalar;
}

// Scalar and matrix subtraction
Matrix operator-(const double &scalar, const Matrix &mat) {
    return mat - scalar;
}

// Scalar and matrix multiplication
Matrix operator*(const double &scalar, const Matrix &mat) {
    return mat * scalar;
}
