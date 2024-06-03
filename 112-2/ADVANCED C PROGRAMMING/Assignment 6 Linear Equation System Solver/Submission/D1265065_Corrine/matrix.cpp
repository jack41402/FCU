//
//  matrix.cpp
//  Assignment6_D1265065
//
//  Created by Corrine  on 2024/5/20.
//
#include "smatrix.h"
#include "matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;
void Matrix::allocateMatrix() {
    m = new double*[row];
    for (int i = 0; i < row; ++i) {
        m[i] = new double[col];
    }
} // allocate matrix elements

void Matrix::deallocateMatrix() {
    for (int i = 0; i < row; ++i) {
        delete[] m[i];
    }
    delete[] m;
} // deallocate matrix elements

Matrix::Matrix(int r, int c){
    if(r > 0 && c > 0){
        row = r;
        col = c;
        allocateMatrix();
    }else{
        row = 0;
        col = 0;
        m = NULL;
    }
} // default matrix constructor

Matrix::Matrix(const Matrix &other) : row(other.row), col(other.col) {
    if (other.row > 0 && other.col > 0) {
        allocateMatrix();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                m[i][j] = other.getElement(i, j);
            }
        }
    }
    else {
        row = 0;
        col = 0;
        m = NULL;
    }
} // matrix copy constructor

Matrix::~Matrix() {
    if (row > 0 && col > 0) deallocateMatrix();
} // matrix destructor
    
void Matrix::setSize(int r, int c){
    if (row > 0 && col > 0) deallocateMatrix();
    row = r;
    col = c;
    allocateMatrix();
} // set row size and column size

void Matrix::setElement(int i, int j, double elem) {
  
  if (row>0 && col>0) {
    if (i>=0 && i<row && j>=0 && j<col) {
      m[i][j] = elem;
    }
    else cout << "Illegal matrix index [" << i << "," << j << "]." << endl;
  }
  else cout << "The matrix is empty." << endl << endl;
} // set a matrix element

double Matrix::getElement(int i, int j) const{
  double elem = 0;

  if (row>0 && col>0) {
    if (i>=0 && i<row && j>=0 && j<col) {
      elem = m[i][j];
    }
    else cout << "Illegal matrix index [" << i << "," << j << "]." << endl;
  }
  else cout << "The matrix is empty." << endl << endl;
  return elem;
}// get a matrix element

int Matrix::getRow() const{
    return row;
} // get row size

int Matrix::getCol() const{
    return col;
} // get column size

Matrix Matrix::operator+(const Matrix &other) const {
    if (row != other.row || col != other.col) {
        cout << "Matrix dimensions must match for addition";
    }
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] + other.m[i][j];
        }
    }
    return result;
} // matrix-matrix addition

Matrix Matrix::operator-(const Matrix &other) const {
    if (row != other.row || col != other.col) {
        cout << "Matrix dimensions must match for subtraction";
    }
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] - other.m[i][j];
        }
    }
    return result;
} // matrix-matrix subtraction

Matrix Matrix::operator*(const Matrix &other) const {
    if (col != other.row) {
        cout << "Matrix dimensions must match for multiplication";
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
} // matrix-matrix multiplication

Matrix Matrix::operator+(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] + scalar;
        }
    }
    return result;
} // matrix-scalar addition

Matrix Matrix::operator-(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] - scalar;
        }
    }
    return result;
} // matrix-scalar subtraction

Matrix Matrix::operator*(const double &scalar) const {
    Matrix result(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[i][j] = m[i][j] * scalar;
        }
    }
    return result;
} // matrix-scalar multiplication

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
} // equal to relation for matrices

bool Matrix::operator!=(const Matrix &other) const {
    return !(*this == other);
} // not equal to relation for matrices

Matrix& Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        setSize(other.row, other.col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                m[i][j] = other.m[i][j];
            }
        }
    }
    return *this;
} // matrix assignment

Matrix& Matrix::operator+=(const Matrix &other) {
    *this = *this + other;
    return *this;
} // matrix assignment with addition

Matrix& Matrix::operator-=(const Matrix &other) {
    *this = *this - other;
    return *this;
} // matrix assignment with subtraction

Matrix& Matrix::operator*=(const Matrix &other) {
    *this = *this * other;
    return *this;
} // matrix assignment with multiplication

Matrix Matrix::operator-() const {
    Matrix result(col, row);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.m[j][i] = m[i][j];
        }
    }
    return result;
} // interpret uniary operation as matrix transposition

Matrix operator+(const double &scalar, const Matrix &m) {
    Matrix result(m.row, m.col);
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++){
            result = m.getElement(i, j) + scalar;
        }
    }
    return result;
}// scalar-matrix addition

Matrix operator-(const double &scalar, const Matrix &m) {
    Matrix result(m.row, m.col);
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.col; ++j) {
            result.m[i][j] = scalar - m.m[i][j];
        }
    }
    return result;
}// scalar-matrix subtraction

Matrix operator*(const double &scalar, const Matrix &m) {
    Matrix result(m.row, m.col);
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++){
            result = m.m[i][j] * scalar;
        }
    }
    return result;
}// scalar-matrix multiplication

ostream &operator<<(ostream &output, const Matrix &M) {
    int i, j; // Loop variables.
    
    for (i=0; i<M.row; i++) {
        output << "  ";
        for (j=0; j<M.col; j++) {
          output << setw(8) << setiosflags(ios::fixed | ios::showpoint);
          output << setprecision(4) << M.m[i][j] << " ";
        }
        output << endl;
    }
    output << endl;
    return output;
}// friend output function

istream& operator>>(istream &in, Matrix &m) {
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.col; ++j) {
            in >> m.m[i][j];
        }
    }
    return in;
} // friend input function
