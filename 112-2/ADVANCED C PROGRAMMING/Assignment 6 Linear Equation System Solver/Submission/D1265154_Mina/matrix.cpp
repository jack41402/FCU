#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

// Overload the output operator to print the contents of matrix M to the output stream
ostream &operator<<(ostream& output, const Matrix& M) {
    int i, j;
    for (i = 0; i < M.row; i++) {
        for (j = 0; j < M.col; j++) {
            output << setw(9) << M.m[i][j];
        }
        output << endl;
    }
    return output;
}

// Overload the input operator to read the contents of the matrix M from the input stream
istream &operator>>(istream& input, Matrix& M) {
    int i, j;
    for (i = 0; i < M.row; i++) {
        for (j = 0; j < M.col; j++) {
            input >> M.m[i][j];
        }
    }
    return input;
}

// Overload the addition operator to add a scalar value to a matrix
Matrix operator+(const double &d, const Matrix &M) {
    int i, j;
    Matrix sum(M.row, M.col);
    for (i = 0; i < M.row; i++) {
        for (j = 0; j < M.col; j++) {
            sum.m[i][j] = d + M.m[i][j];
        }
    }
    return sum;
}

// Overload the subtraction operator to subtract a scalar value from a matrix
Matrix operator-(const double &d, const Matrix &M) {
    int i, j;
    Matrix diff(M.row, M.col);
    for (i = 0; i < M.row; i++) {
        for (j = 0; j < M.col; j++) {
            diff.m[i][j] = d - M.m[i][j];
        }
    }
    return diff;
}

// Overload the multiplication operator to multiply a matrix by a scalar value
Matrix operator*(const double &d, const Matrix &M) {
    int i, j;
    Matrix prod(M.row, M.col);
    for (i = 0; i < M.row; i++) {
        for (j = 0; j < M.col; j++) {
            prod.m[i][j] = d * M.m[i][j];
        }
    }
    return prod;
}

// Allocate memory for the matrix elements
void Matrix::allocateMatrix() {
    int i;
    m = new double*[row]; // Create a double pointer (2D array)
    for (i = 0; i < row; i++) {
        m[i] = new double[col];
    }
}

// Deallocate memory for the matrix elements
void Matrix::deallocateMatrix() {
    int i;
    for (i = 0; i < row; ++i) {
        delete[] m[i]; // Delete each 1D array
    }
    delete[] m; // Delete the 2D array
    m = NULL;
}

// Constructor to initialize a matrix with given rows and columns
Matrix::Matrix(int r, int c) {
    row = r;
    col = c;
    m = NULL; // Double pointer pointing to 2D array
    if (row > 0 && col > 0) allocateMatrix(); // Allocate memory if rows and columns are greater than 0
}

// Copy constructor
Matrix::Matrix(const Matrix& M) {
    int i, j;
    row = M.row;
    col = M.col;
    allocateMatrix();
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            m[i][j] = M.m[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix() {
    deallocateMatrix();
}

// Set the size of the matrix and allocate memory
void Matrix::setSize(int r, int c) {
    row = r;
    col = c;
    if (row > 0 && col > 0) allocateMatrix();
}

// Set the element of the matrix at position (r, c)
void Matrix::setElement(int r, int c, double e) {
    if (m != NULL && r >= 0 && r < row && c >= 0 && c < col) {
        m[r][c] = e;
    }
}

// Get the element of the matrix at position (r, c)
double Matrix::getElement(int r, int c) const {
    if (m != NULL && (r >= 0 && r < row) && (c >= 0 && c < col)) {
        return m[r][c];
    }
    return 0; // Return 0 if indices are out of bounds
}

// Get the number of rows
int Matrix::getRow() const {
    return row;
}

// Get the number of columns
int Matrix::getCol() const {
    return col;
}

// Overload the addition operator for matrix addition
Matrix Matrix::operator+(const Matrix &M) const {
    int i, j;
    Matrix sum;
    if (row == M.row && col == M.col) {
        sum.setSize(row, col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                sum.m[i][j] = this->m[i][j] + M.m[i][j];
            }
        }
        return sum;
    }
    return Matrix(); // Return an empty matrix if dimensions do not match
}

// Overload the subtraction operator for matrix subtraction
Matrix Matrix::operator-(const Matrix &M) const {
    int i, j;
    Matrix diff;
    if (row == M.row && col == M.col) {
        diff.setSize(row, col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                diff.m[i][j] = m[i][j] - M.m[i][j];
            }
        }
        return diff;
    }
    return Matrix(); // Return an empty matrix if dimensions do not match
}

// Overload the multiplication operator for matrix multiplication
Matrix Matrix::operator*(const Matrix &M) const {
    int i, j, k;
    double sum;
    Matrix prod;
    if (col == M.row) {
        prod.setSize(row, M.col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < M.col; j++) {
                sum = 0.0;
                for (k = 0; k < col; k++) {
                    sum += m[i][k] * M.m[k][j];
                }
                prod.m[i][j] = sum;
            }
        }
        return prod;
    }
    return Matrix(); // Return an empty matrix if dimensions do not match
}

// Overload the addition operator to add a scalar value to the matrix
Matrix Matrix::operator+(const double &d) const {
    int i, j;
    Matrix sum(row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            sum.m[i][j] = m[i][j] + d;
        }
    }
    return sum;
}

// Overload the subtraction operator to subtract a scalar value from the matrix
Matrix Matrix::operator-(const double &d) const {
    int i, j;
    Matrix diff(row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            diff.m[i][j] = m[i][j] - d;
        }
    }
    return diff;
}

// Overload the multiplication operator to multiply the matrix by a scalar value
Matrix Matrix::operator*(const double &d) const {
    int i, j;
    Matrix prod(row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            prod.m[i][j] = m[i][j] * d;
        }
    }
    return prod;
}

// Overload the equality operator to check if two matrices are equal
bool Matrix::operator==(const Matrix &M) const {
    int i, j;
    if (row != M.row || col != M.col) return false;
    else {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (m[i][j] != M.m[i][j]) return false;
            }
        }
        return true;
    }
}

// Overload the inequality operator to check if two matrices are not equal
bool Matrix::operator!=(const Matrix &M) const {
    int i, j;
    if (row != M.row || col != M.col) return true;
    else {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (m[i][j] != M.m[i][j]) return true;
            }
        }
        return false;
    }
}

// Overload the assignment operator to assign one matrix to another
Matrix& Matrix::operator=(const Matrix &M) {
    int i, j;
    if (this != &M) { // Check for self-assignment
        deallocateMatrix();
        row = M.row;
        col = M.col;
        allocateMatrix();
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                m[i][j] = M.m[i][j];
            }
        }
    }
    return *this;
}

// Overload the addition assignment operator to add and assign a matrix
Matrix& Matrix::operator+=(const Matrix &M) {
    int i, j;
    if (row == M.row && col == M.col) {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                m[i][j] += M.m[i][j];
            }
        }
    }
    return *this;
}

// Overload the subtraction assignment operator to subtract and assign a matrix
Matrix& Matrix::operator-=(const Matrix &M) {
    int i, j;
    if (row == M.row && col == M.col) {
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                m[i][j] -= M.m[i][j];
            }
        }
    }
    return *this;
}

// Overload the multiplication assignment operator to multiply and assign a matrix
Matrix& Matrix::operator*=(const Matrix &M) {
    int i, j, k;
    double sum;
    Matrix prod;
    if (col == M.row) {
        prod.setSize(row, M.col);
        for (i = 0; i < row; i++) {
            for (j = 0; j < M.col; j++) {
                sum = 0.0;
                for (k = 0; k < col; k++) {
                    sum += m[i][k] * M.m[k][j];
                }
                prod.m[i][j] = sum;
            }
        }
        deallocateMatrix();
        setSize(row, M.col);
        *this = prod;
    }
    return *this;
}

// Overload the unary negation operator to negate a matrix
Matrix Matrix::operator-() const {
    int i, j;
    Matrix nega(row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            nega.m[i][j] = -m[i][j];
        }
    }
    return nega;
}

