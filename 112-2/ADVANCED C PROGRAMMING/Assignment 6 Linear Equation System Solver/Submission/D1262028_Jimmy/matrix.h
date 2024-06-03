#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept> // Add this line to ensure std::out_of_range is included

using namespace std;

class Matrix {
    // Friends for input/output stream operations and scalar operations
    friend ostream &operator<<(ostream&, const Matrix&);
    friend istream &operator>>(istream&, Matrix&);
    friend Matrix operator+(const double &, const Matrix &);
    friend Matrix operator-(const double &, const Matrix &);
    friend Matrix operator*(const double &, const Matrix &);

protected:
    int row, col; // Number of rows and columns
    double** m; // Pointer to matrix data
    void allocateMatrix(); // Allocate memory for the matrix
    void deallocateMatrix(); // Deallocate memory for the matrix

public:
    // Constructors and destructor
    Matrix(int = 0, int = 0); // Constructor with default size 0x0
    Matrix(const Matrix&); // Copy constructor
    ~Matrix(); // Destructor
    
    // Methods to manipulate matrix size and elements
    void setSize(int, int); // Set matrix size and allocate memory
    void setElement(int, int, double); // Set the value of a matrix element
    double getElement(int, int) const; // Get the value of a matrix element
    int getRow() const; // Get the number of rows
    int getCol() const; // Get the number of columns
    
    // Overloaded operators for matrix operations
    Matrix operator+(const Matrix &) const; // Matrix addition
    Matrix operator-(const Matrix &) const; // Matrix subtraction
    Matrix operator*(const Matrix &) const; // Matrix multiplication
    Matrix operator+(const double &) const; // Matrix and scalar addition
    Matrix operator-(const double &) const; // Matrix and scalar subtraction
    Matrix operator*(const double &) const; // Matrix and scalar multiplication
    bool operator==(const Matrix &) const; // Equality comparison
    bool operator!=(const Matrix &) const; // Inequality comparison
    Matrix &operator=(const Matrix &); // Assignment operator
    Matrix &operator+=(const Matrix &); // Addition assignment operator
    Matrix &operator-=(const Matrix &); // Subtraction assignment operator
    Matrix &operator*=(const Matrix &); // Multiplication assignment operator
    Matrix operator-() const; // Negation operator (transpose)
};

#endif
