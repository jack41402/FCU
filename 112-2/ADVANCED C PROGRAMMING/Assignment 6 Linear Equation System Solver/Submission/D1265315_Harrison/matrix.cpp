#include <iostream>
#include "matrix.h"
#include <iomanip>
using namespace std;

// Overloaded output operator for printing a matrix
ostream &operator<<(ostream &output, const Matrix &m2) {
    int i, j;
    for (i = 0; i < m2.row; i++) {
        output << "    ";
        for (j = 0; j < m2.col; j++) {
            output << fixed << setprecision(4) << m2.m[i][j];
            output << "   ";
        }
        output << '\n';
    }
    output << '\n';
    return output;
}

// Overloaded input operator for reading a matrix from standard input
istream &operator>>(istream &input, Matrix &m2) {
    int i, j;
    cout << "Input Matrix: " << m2.row << " X " << m2.col << endl;
    for (i = 0; i < m2.row; i++) {
        for (j = 0; j < m2.col; j++) {
            input >> m2.m[i][j];
        }
    }
    cout << '\n';
    return input;
}

// Overloaded addition operator for scalar and matrix addition
Matrix operator+(const double &d, const Matrix &m2) {
    Matrix sum;
    int i, j;
    if (m2.getCol() > 0 && m2.getRow() > 0) {
        sum.setSize(m2.getRow(), m2.getCol());
        for (i = 0; i < m2.getRow(); i++) {
            for (j = 0; j < m2.getCol(); j++) {
                sum.m[i][j] = m2.m[i][j] + d;
            }
        }
    } else {
        cout << "Scalar-matrix addition: The matrix is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Overloaded subtraction operator for scalar and matrix subtraction
Matrix operator-(const double &d, const Matrix &m2) {
    Matrix sum;
    int i, j;
    if (m2.getCol() > 0 && m2.getRow() > 0) {
        sum.setSize(m2.getRow(), m2.getCol());
        for (i = 0; i < m2.getRow(); i++) {
            for (j = 0; j < m2.getCol(); j++) {
                sum.m[i][j] = d - m2.m[i][j];
            }
        }
    } else {
        cout << "Scalar-matrix subtraction: The matrix is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Overloaded multiplication operator for scalar and matrix multiplication
Matrix operator*(const double &d, const Matrix &m2) {
    Matrix sum;
    int i, j;
    if (m2.getCol() > 0 && m2.getRow() > 0) {
        sum.setSize(m2.getRow(), m2.getCol());
        for (i = 0; i < m2.getRow(); i++) {
            for (j = 0; j < m2.getCol(); j++) {
                sum.m[i][j] = d * m2.m[i][j];
            }
        }
    } else {
        cout << "Scalar-matrix multiplication: The matrix is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Allocate memory for the matrix
void Matrix::allocateMatrix() {
    m = new double* [row];
    for (int i = 0; i < row; i++) m[i] = new double[col];
}

// Deallocate memory for the matrix
void Matrix::deallocateMatrix() {
    for (int i = 0; i < row; i++) delete[] m[i];
    delete[] m;
}

// Constructor with dimensions
Matrix::Matrix(int a, int b) {
    if (a > 0 && b > 0) {
        row = a;
        col = b;
        allocateMatrix();
    } else {
        row = 0;
        col = 0;
        m = NULL;
    }
}

// Copy constructor
Matrix::Matrix(const Matrix &n) {
    int i, j;
    if (n.row > 0 && n.col > 0) {
        row = n.row;
        col = n.col;
        allocateMatrix();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                m[i][j] = n.getElement(i, j);
            }
        }
    } else {
        row = 0;
        col = 0;
        m = NULL;
    }
}

// Destructor
Matrix::~Matrix() {
    if (row > 0 && col > 0) deallocateMatrix();
}

// Set the size of the matrix
void Matrix::setSize(int r, int c) {
    if (row > 0 && col > 0) deallocateMatrix();
    if (r > 0 && c > 0) {
        row = r;
        col = c;
        allocateMatrix();
    } else {
        row = 0;
        col = 0;
        m = NULL;
    }
}

// Set a specific element in the matrix
void Matrix::setElement(int r, int c, double e) {
    m[r][c] = e;
}

// Get a specific element from the matrix
double Matrix::getElement(int r, int c) const {
    return m[r][c];
}

// Get the number of columns
int Matrix::getCol() const {
    return col;
}

// Get the number of rows
int Matrix::getRow() const {
    return row;
}

// Overloaded addition operator for matrix addition
Matrix Matrix::operator+(const Matrix &m2) const {
    Matrix sum;
    int i, j;
    if (row > 0 && col > 0) {
        if (row == m2.row && col == m2.col) {
            sum.setSize(row, col);
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    sum.m[i][j] = m2.m[i][j] + m[i][j];
                }
            }
        } else {
            cout << "Matrix-matrix addition: The matrix operand sizes do not match." << endl;
            sum.row = 0;
            sum.col = 0;
            sum.m = NULL;
        }
    } else {
        cout << "Matrix-matrix addition: One of the matrices is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Overloaded subtraction operator for matrix subtraction
Matrix Matrix::operator-(const Matrix &m2) const {
    Matrix sum;
    int i, j;
    if (row > 0 && col > 0) {
        if (row == m2.row && col == m2.col) {
            sum.setSize(row, col);
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    sum.m[i][j] = m2.m[i][j] - m[i][j];
                }
            }
        } else {
            cout << "Matrix-matrix subtraction: The matrix operand sizes do not match." << endl;
            sum.row = 0;
            sum.col = 0;
            sum.m = NULL;
        }
    } else {
        cout << "Matrix-matrix subtraction: One of the matrices is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Overloaded multiplication operator for matrix multiplication
Matrix Matrix::operator*(const Matrix &m2) const {
    Matrix sum;
    int i, j, k;
    if (row > 0 && col > 0) {
        if (col == m2.row) {
            sum.setSize(row, m2.col);
            for (i = 0; i < row; i++) {
                for (j = 0; j < sum.col; j++) {
                    sum.m[i][j] = 0;
                    for (k = 0; k < col; k++) {
                        sum.m[i][j] += m[i][k] * m2.m[k][j];
                    }
                }
            }
        } else {
            cout << "Matrix-matrix multiplication: The matrix operand sizes do not match." << endl;
            sum.row = 0;
            sum.col = 0;
            sum.m = NULL;
        }
    } else {
        cout << "Matrix-matrix multiplication: One of the matrices is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Overloaded addition operator for matrix and scalar addition
Matrix Matrix::operator+(const double &d) const {
    Matrix sum;
    int i, j;
    if (row > 0 && col > 0) {
        sum.setSize(row, col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                sum.m[i][j] = m[i][j] + d;
            }
        }
    } else {
        cout << "Matrix-scalar addition: The matrix is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Overloaded subtraction operator for matrix and scalar subtraction
Matrix Matrix::operator-(const double &d) const {
    Matrix sum;
    int i, j;
    if (row > 0 && col > 0) {
        sum.setSize(row, col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                sum.m[i][j] = m[i][j] - d;
            }
        }
    } else {
        cout << "Matrix-scalar subtraction: The matrix is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Overloaded multiplication operator for matrix and scalar multiplication
Matrix Matrix::operator*(const double &d) const {
    Matrix sum;
    int i, j;
    if (row > 0 && col > 0) {
        sum.setSize(row, col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                sum.m[i][j] = m[i][j] * d;
            }
        }
    } else {
        cout << "Matrix-scalar multiplication: The matrix is empty." << endl;
        sum.row = 0;
        sum.col = 0;
        sum.m = NULL;
    }
    return sum;
}

// Overloaded equality operator for comparing matrices
bool Matrix::operator==(const Matrix &m2) const {
    int i, j;
    if (row > 0 && col > 0) {
        if (row == m2.row && col == m2.col) {
            for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                    if (m[i][j] != m2.m[i][j]) return false;
                }
            }
            return true;
        } else {
            cout << "Matrix relation: The operand matrix sizes do not match." << endl;
        }
    } else cout << "Matrix relation: One of the matrices is empty." << endl;
    return false;
}

// Overloaded inequality operator for comparing matrices
bool Matrix::operator!=(const Matrix &m2) const {
    return !(*this == m2);
}

// Overloaded assignment operator for matrix assignment
Matrix &Matrix::operator=(const Matrix &m2) {
    int i, j;
    if (row > 0 && col > 0) deallocateMatrix();
    row = m2.row;
    col = m2.col;
    if (row > 0 && col > 0) {
        allocateMatrix();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                m[i][j] = m2.m[i][j];
            }
        }
    } else m = NULL;
    return *this;
}

// Overloaded addition assignment operator for matrix addition
Matrix &Matrix::operator+=(const Matrix &m2) {
    *this = *this + m2;
    return *this;
}

// Overloaded subtraction assignment operator for matrix subtraction
Matrix &Matrix::operator-=(const Matrix &m2) {
    *this = *this - m2;
    return *this;
}

// Overloaded multiplication assignment operator for matrix multiplication
Matrix &Matrix::operator*=(const Matrix &m2) {
    *this = *this * m2;
    return *this;
}

// Overloaded negation operator for matrix transposition
Matrix Matrix::operator-() const {
    Matrix m2(col, row);
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            m2.m[j][i] = m[i][j];
        }
    }
    return m2;
}
