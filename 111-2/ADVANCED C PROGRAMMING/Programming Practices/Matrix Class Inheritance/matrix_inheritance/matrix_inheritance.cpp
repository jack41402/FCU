#include <iostream>
#include <iomanip>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "matrix_inheritance.h"
#include "smatrix_inheritance.h"

// Friend output function.
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
}

// Friend input function.
istream &operator>>(istream& input, Matrix& M) {
	int i, j; // Loop vairables.
	
	cout << "Input Matrix: " << M.row << " X " << M.col << endl;
	for (i=0; i<M.row; i++)
	  for (j=0; j<M.col; j++)
	    input >> M.m[i][j];
	cout << endl;
	return input;
}

// Elementwise scalar-matrix addition.
Matrix operator+(const double &s, const Matrix &n) {
	Matrix sum;
	int i, j; // Loop variables.

  if (n.getRow()>0 && n.getCol()>0) {
    sum.setSize(n.getRow(), n.getCol());
    for (i=0; i<n.getRow(); i++)
      for (j=0; j<n.getCol(); j++)
        sum.m[i][j] = s + n.getElement(i,j);
  }
  else {
    std::cout << "Scalar-matrix addition: The matrix is empty." << endl;
    sum.row = 0;
    sum.col = 0;
    sum.m = NULL;
  }
	return sum;
}

// Elementwise scalar-matrix subtraction.
Matrix operator-(const double &s, const Matrix &n) {
	Matrix diff;
	int i, j; // Loop variables.

  if (n.getRow()>0 && n.getCol()>0) {
    diff.setSize(n.getRow(), n.getCol());
    for (i=0; i<n.getRow(); i++)
      for (j=0; j<n.getCol(); j++)
        diff.m[i][j] = s - n.getElement(i,j);
  }
  else {
    std::cout << "Scalar-matrix subtraction: The matrix is empty." << endl;
    diff.row = 0;
    diff.col = 0;
    diff.m = NULL;
  }
	return diff;
}

// Elementwise scalar-matrix multiplication.
Matrix operator*(const double &s, const Matrix &n) {
	Matrix prod;
	int i, j; // Loop variables.

  if (n.getRow()>0 && n.getCol()>0) {
    prod.setSize(n.getRow(), n.getCol());
    for (i=0; i<n.getRow(); i++)
      for (j=0; j<n.getCol(); j++)
        prod.m[i][j] = s * n.getElement(i,j);
  }
  else {
    std::cout << "Scalar-matrix multiplication: The matrix is empty." << endl;
    prod.row = 0;
    prod.col = 0;
    prod.m = NULL;
  }
	return prod;
}

// Request memory sotrage for matrix elements.
void Matrix::allocateMatrix() { 
  m = new double* [row];
  for (int i=0; i<row; i++) m[i] = new double [col];    
}

// Release memory sotrage for matrix elements.
void Matrix::deallocateMatrix() {
  for (int i=0; i<row; i++) delete [] m[i];
  delete [] m;
}

// Matrix constructor with size definition.
Matrix::Matrix(int r, int c) {
  if (r>0 && c>0) {
    row = r;
    col = c;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}
// Matrix copy constructor.
Matrix::Matrix(const Matrix& n) {
  int i, j;
  
  if (n.row>0 && n.col>0) {
    row = n.row;
    col = n.col;
    allocateMatrix();
    for (i=0; i<row; i++) {
      for (j=0; j<col; j++) {
        m[i][j] = n.getElement(i, j);
      }
    }
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Matrix destructor.
Matrix::~Matrix() {
  if (row>0 && col>0) deallocateMatrix();
}

// Redefine matrix size.
void Matrix::setSize(int r, int c) {
     
  if (row>0 && col>0) deallocateMatrix();
  if (r>0 && c>0) {
    row = r;
    col = c;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Set value of a matrix element via parameter.
void Matrix::setElement(int i, int j, double elem) {
  
  if (row>0 && col>0) {
    if (i>=0 && i<row && j>=0 && j<col) {
      m[i][j] = elem;
    }
    else cout << "Illegal matrix index [" << i << "," << j << "]." << endl;
  }
  else cout << "The matrix is empty." << endl << endl;
}

// Get a matrix element.
double Matrix::getElement(int i, int j) const{
  double elem = 0;

  if (row>0 && col>0) {
    if (i>=0 && i<row && j>=0 && j<col) {
      elem = m[i][j];
    }
    else std::cout << "Illegal matrix index [" << i << "," << j << "]." << endl;
  }
  else std::cout << "The matrix is empty." << endl << endl;
  return elem;
}

// Get the number of rows in a matrix
int Matrix::getRow() const {
  return row;
}

// Get the number of columns in a matrix
int Matrix::getCol() const {
  return col;
}

// Matrix-matrix addition.
Matrix Matrix::operator+(const Matrix &n) const {
  Matrix sum;
  int i, j;

  if (row==n.row && col==n.col) {
    if (row>0 && col>0) {
      sum.setSize(row, col);
      for (i=0; i<row; i++)
	      for (j=0; j<col; j++)
	        sum.m[i][j] = m[i][j] + n.m[i][j];
    }
    else {
      std::cout << "Matrix-matrix addition: One of the matrices is empty." << endl;
      sum.row = 0;
      sum.col = 0;
      sum.m = NULL;
    }
  }
  else {
    std::cout << "Matrix-matrix addition: The matrix operand sizes do not match." << endl;
    sum.row = 0;
    sum.col = 0;
    sum.m = NULL;
  }
  return sum;
}

// Matrix-matrix substraction.
Matrix Matrix::operator-(const Matrix &n) const {
  Matrix diff;
  int i, j;

  if (row==n.row && col==n.col) {
    if (row>0 && col>0) {
      diff.setSize(row, col);
      for (i=0; i<row; i++)
      	for (j=0; j<col; j++)
	        diff.m[i][j] = m[i][j] - n.m[i][j];
    }
    else {
      std::cout << "Matrix-matrix substraction: One of the matrices is empty." << endl;
      diff.row = 0;
      diff.col = 0;
      diff.m = NULL;
    }
  }
  else {
    std::cout << "Matrix-matrix substraction: The matrix operand sizes do not match." << endl;
    diff.row = 0;
    diff.col = 0;
    diff.m = NULL;
  }
  return diff;
}

// Matrix-matrix multiplication
Matrix Matrix::operator*(const Matrix &n) const {
  Matrix prod;
  int i, j, k;

  if (col==n.row) {
    if (row>0 && col>0 && n.col>0) {
      prod.setSize(row, n.col);
      for (i=0; i<row; i++) {
      	for (j=0; j<n.col; j++) {
	        prod.m[i][j] = 0;
	        for (k=0; k<col; k++)
	          prod.m[i][j] += m[i][k] * n.m[k][j];
       	}
      }
    }
    else {
      std::cout << "Matrix-matrix multiplication: One of the matrices is empty." << endl;      
      prod.row = 0;
      prod.col = 0;
      prod.m = NULL;
    }
  }
  else {
    std::cout << "Matrix-matrix multiplication: The matrix operand sizes do not match." << endl;    
    prod.row = 0;
    prod.col = 0;
    prod.m = NULL;
  }
  return prod;
}

// Matrix-scalar addition.
Matrix Matrix::operator+(const double &s) const {
  Matrix sum;
  int i, j;

  if (row>0 && col>0) {
    sum.setSize(row, col);
    for (i=0; i<row; i++)
      for (j=0; j<col; j++)
        sum.m[i][j] = m[i][j] + s;
  }
  else {
    std::cout << "Matrix-scalar addition: The matrix is empty." << endl;
    sum.row = 0;
    sum.col = 0;
    sum.m = NULL;
  }
  return sum;
}

// Matrix-scalar subtraction.
Matrix Matrix::operator-(const double &s) const {
  Matrix diff;
  int i, j;
  
  if (row>0 && col>0) {
    diff.setSize(row, col);
    for (i=0; i<row; i++)
      for (j=0; j<col; j++)
        diff.m[i][j] = m[i][j] - s;
  }
  else {
    std::cout << "Matrix-scalar subtraction: The matrix is empty." << endl;
    diff.row = 0;
    diff.col = 0;
    diff.m = NULL;
  }
  return diff;
}

// Matrix-scalar multiplication
Matrix Matrix::operator*(const double &s) const {
  Matrix prod;
  int i, j;
  
  if (row>0 && col>0) {
	  prod.setSize(row, col);
	  for (i=0; i<row; i++)
      for (j=0; j<col; j++)
        prod.m[i][j] = m[i][j] * s;
  }
  else {
    std::cout << "Matrix-scalar multiplication: The matrix is empty." << endl;    
    prod.row = 0;
    prod.col = 0;
    prod.m = NULL;
  }
  return prod;
}

// Equal to relation for matrices.
bool Matrix::operator==(const Matrix &n) const {
  int i, j; // Loop variables. 
	
  if (row==n.row && col==n.col) {
    if (row>0 && col>0) {
      for (i=0; i<row; i++) 
      	for (j=0; j<col; j++) 
	        if (m[i][j]!=n.m[i][j]) return false;      	
      return true;
    }
    else cout << "Matrix relation: One of the matrices is empty." << endl;
  }
  else cout << "Matrix relation: The operand matrix sizes do not match." << endl;
  return false;
} 

// Not equal to relation for matrices.
bool Matrix::operator!=(const Matrix &n) const {
  return !(*this==n);
}

// Matrix assignment.
Matrix & Matrix::operator=(const Matrix &n) {
  int i,j;

  if (row>0 && col>0) deallocateMatrix();
  row = n.row;
  col = n.col;
  if (row>0 && col>0 ) {
    allocateMatrix();
    for (i=0; i<row; i++)
      for (j=0; j<col; j++) 
        m[i][j] = n.getElement(i, j);
  }
  else m = NULL; 
  return *this;
}

// Matrix assignment with addition.
Matrix & Matrix::operator+=(const Matrix &n) {
	*this = *this + n; 
  return *this;
}

// Matrix assignment with subtraction.
Matrix & Matrix::operator-=(const Matrix &n) {
	*this = *this - n; 
  return *this;
}

// Matrix assignment with multiplication.
Matrix & Matrix::operator*=(const Matrix &n) {
	*this = *this * n; 
  return *this;
}

// Interpret uniary operation as matrix transposition.
Matrix Matrix::operator-() const {
	Matrix T(col, row); // Create the transposed matrix.
	int i, j; // Loop variables.
	
	for (i=0; i<row; i++)
	  for (j=0; j<col; j++)
		  T.m[j][i] = m[i][j];
			
  return T; 
}

// Overloaded determinant function when row==col
double Matrix::determinant() const {
  if (row==col) {
  	SMatrix S(*this);
  	return S.determinant();
	}
	else {
		cout << "The matrix is not a square matrix." << endl; 
		return -999;
	}
}
