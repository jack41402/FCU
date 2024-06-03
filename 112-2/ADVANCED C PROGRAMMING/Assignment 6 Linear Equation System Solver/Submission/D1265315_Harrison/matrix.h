#ifndef matrix
#define matrix

#include <iostream>

using namespace std;

// Matrix operations
class Matrix {

friend ostream &operator<<(ostream&, const Matrix&); // friend output function
friend istream &operator>>(istream&, Matrix&); // friend input function
friend Matrix operator+(const double &, const Matrix &); // scalar-matrix addition
friend Matrix operator-(const double &, const Matrix &); // scalar-matrix subtraction
friend Matrix operator*(const double &, const Matrix &); // scalar-matrix multiplication

protected:
	int row, col; // row size and column size of a matrix
	double** m; // a pointer to matrix elements
	void allocateMatrix(); // allocate matrix elements
	void deallocateMatrix(); // deallocate matrix elements
  
	public:
		Matrix(int=0, int=0); // default matrix constructor
		Matrix(const Matrix&); // matrix copy constructor
		~Matrix(); // matrix destructor
    
		void setSize(int, int); // set row size and column size
		void setElement(int, int, double); // set a matrix element
		double getElement(int, int) const; // get a matrix element
		int getRow() const; // get row size
		int getCol() const; // get column size
    
		Matrix operator+(const Matrix &) const; // matrix-matrix addition
		Matrix operator-(const Matrix &) const; // matrix-matrix subtraction
		Matrix operator*(const Matrix &) const; // matrix-matrix multiplication
		Matrix operator+(const double &) const; // matrix-scalar addition
		Matrix operator-(const double &) const; // matrix-scalar subtraction
		Matrix operator*(const double &) const; // matrix-scalar multiplication
		bool operator==(const Matrix &) const; // equal to relation for matrices
		bool operator!=(const Matrix &) const; // not equal to relation for matrices
		Matrix &operator=(const Matrix &); // matrix assignment
		Matrix &operator+=(const Matrix &); // matrix assignment with addition
		Matrix &operator-=(const Matrix &); // matrix assignment with subtraction
		Matrix &operator*=(const Matrix &); // matrix assignment with multiplication
		Matrix operator-() const; // interpret uniary operation as matrix transposition
};

#endif

