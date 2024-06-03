#include "matrix.h"
#include <iomanip> 

// allocate matrix elements
void Matrix::allocateMatrix() {
    m = new double* [row];
    for (int i = 0; i < row; ++i) {
        m[i] = new double[col]();
    }
}

// deallocate matrix elements
void Matrix::deallocateMatrix() {
    for (int i = 0; i < row; ++i) {
        delete[] m[i];
    }
    delete[] m;
}

// default matrix constructor
Matrix::Matrix(int r, int c) : row(r), col(c) {
    if (row > 0 && col > 0) {
        allocateMatrix();
    }
    else {
        m = nullptr;
    }
}

// matrix copy constructor
Matrix::Matrix(const Matrix& other) : row(other.row), col(other.col) {
    if (row > 0 && col > 0) {
        allocateMatrix();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                m[i][j] = other.m[i][j];
            }
        }
    }
    else {
        m = nullptr;
    }
}

// matrix destructor
Matrix::~Matrix() {
    if (m != nullptr) {
        deallocateMatrix();
    }
}

// set row size and column size
void Matrix::setSize(int r, int c) {
    if (m != nullptr) {
        deallocateMatrix();
    }
    row = r;
    col = c;
    if (row > 0 && col > 0) {
        allocateMatrix();
    }
    else {
        m = nullptr;
    }
}

// set a matrix element
void Matrix::setElement(int r, int c, double value) {
    if (m!=nullptr&&r >= 0 && r < row && c >= 0 && c < col) {
        m[r][c] = value;
    }
}

// get a matrix element
double Matrix::getElement(int r, int c) const {
    if (m != nullptr&&r >= 0 && r < row && c >= 0 && c < col) {
        return m[r][c];
    }
    return 0;
}

// get row size
int Matrix::getRow() const {
    return row;
}

// get column size
int Matrix::getCol() const {
    return col;
}

// matrix-matrix addition
Matrix Matrix::operator+(const Matrix& other) const {
    if (row == other.row && col == other.col) {
        Matrix result(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result.m[i][j] = m[i][j] + other.m[i][j];
            }
        }
        return result;
    }
}

// matrix-matrix subtraction
Matrix Matrix::operator-(const Matrix& other) const {
    if (row == other.row && col == other.col) {
        Matrix result(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result.m[i][j] = m[i][j] - other.m[i][j];
            }
        }
        return result;
    }
}

// matrix-matrix multiplication
Matrix Matrix::operator*(const Matrix& other) const {
    if (col == other.row) {
        Matrix result(row, other.col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < other.col; ++j) {
                result.m[i][j] = 0;
                for (int k = 0; k < col; ++k) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }
        return result;
    }
}

// matrix-scalar addition
Matrix Matrix::operator+(const double& scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] + scalar;
        }
    }
    return result;
}

// matrix-scalar subtraction
Matrix Matrix::operator-(const double& scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] - scalar;
        }
    }
    return result;
}

// matrix-scalar multiplication
Matrix Matrix::operator*(const double& scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] * scalar;
        }
    }
    return result;
}

// equal to relation for matrices
bool Matrix::operator==(const Matrix& other) const {
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

// not equal to relation for matrices
bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

// matrix assignment
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        if (m != nullptr) {
            deallocateMatrix();
        }
        row = other.row;
        col = other.col;
        if (row > 0 && col > 0) {
            allocateMatrix();
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    m[i][j] = other.m[i][j];
                }
            }
        }
        else {
            m = nullptr;
        }
    }
    return *this;
}

// matrix assignment with addition
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

// matrix assignment with subtraction
Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

// matrix assignment with multiplication
Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
}

// interpret uniary operation as matrix transposition
Matrix Matrix::operator-() const {
    Matrix result(col, row);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[j][i] = m[i][j];
        }
    }
    return result;
}

// friend output function
ostream& operator<<(ostream& os, const Matrix& t) {
    os << fixed << setprecision(4);
    if (t.col != 1) {
        for (int i = 0; i < t.row; ++i) {
            for (int j = 0; j < t.col; ++j) {
                os << "   " << t.m[i][j];
            }
            os << endl;
        }
    }
    else {
        for (int i = 0; i < t.row; ++i) {
            os << "   " << t.m[i][0];
        }
        os << endl;
    }
    return os;
}

// friend input function
istream& operator>>(istream& is, Matrix& t) {
    for (int i = 0; i < t.row; ++i) {
        for (int j = 0; j < t.col; ++j) {
            is >> t.m[i][j];
        }
    }
    return is;
}

// scalar-matrix addition
Matrix operator+(const double& scalar, const Matrix& t) {
    return t + scalar;
}

// scalar-matrix subtraction
Matrix operator-(const double& scalar, const Matrix& t) {
    Matrix result(t.row, t.col);
    for (int i = 0; i < t.row; ++i) {
        for (int j = 0; j < t.col; ++j) {
            result.m[i][j] = scalar - t.m[i][j];
        }
    }
    return result;
}

// scalar-matrix multiplication
Matrix operator*(const double& scalar, const Matrix& t) {
    return t * scalar;
}
