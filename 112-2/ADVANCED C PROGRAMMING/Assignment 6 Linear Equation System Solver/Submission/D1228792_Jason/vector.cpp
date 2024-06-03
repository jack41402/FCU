#include <iostream>
#include "vector.h"

// Constructor for Vector class with size n
Vector::Vector(int n) {
    if (n > 0) {
        col = 1;
        row = n;
        allocateMatrix();
    } 
	else {
        col = 0;
        row = 0;
        m = NULL;
    }
}

// Constructor for Vector class from a column of a Matrix
Vector::Vector(const Matrix &m2, const int n) {
    int i;
    if (m2.getCol() > 0 && m2.getRow() > 0) { // Check if Matrix is non-empty
        if (n >= 0 && n < m2.getCol()) { // Check if column index n is valid
            col = 1;
            row = m2.getRow();
            allocateMatrix();
            for (i = 0; i < m2.getRow(); i++) {
                m[i][0] = m2.getElement(i, n);
            }
        } 
		else {
            col = 0;
            row = 0;
            m = NULL;
            cout << "Wrong index of n.\n";
        }
    } 
	else {
        col = 0;
        row = 0;
        m = NULL;
        cout << "The index Matrix is NULL.\n";
    }
}

// Copy constructor for Vector class
Vector::Vector(const Vector &v) {
    if (v.getCol() == 1 && v.getRow() > 0) { // Check if v is a valid vector
        int i;
        col = 1;
        row = v.row;
        allocateMatrix();
        for (i = 0; i < row; i++) {
            m[i][0] = v.m[i][0];
        }
    } 
	else {
        col = 0;
        row = 0;
        m = NULL;
        cout << "The index Vector is NULL or not a Vector.\n";
    }
}

// Set size for Vector, ensuring it is a column vector
void Vector::setSize(const int n) {
    if (n > 0) {
        if (m != NULL) deallocateMatrix();
        col = 1;
        row = n;
        allocateMatrix();
    } 
	else {
        col = 0;
        row = 0;
        m = NULL;
    }
}

// Replace a column in Matrix with this Vector and return the new Matrix
Matrix Vector::vector_replace(int c, const Matrix &m2) {
    Matrix m3;
    if (m2.getCol() > 0 && m2.getRow() > 0) { // Check if m2 is non-empty
        if (c >= 0 && c < m2.getCol() && row == m2.getRow()) { // Check if column index c is valid and dimensions match
            m3.setSize(m2.getRow(), m2.getCol());
            int i, j;
            for (i = 0; i < m2.getRow(); i++) {
                for (j = 0; j < m2.getCol(); j++) {
                    m3.setElement(i, j, m2.getElement(i, j)); // Copy elements from m2 to m3
                }
            }
            for (i = 0; i < m2.getRow(); i++) {
                m3.setElement(i, c, m[i][0]); // Replace column c with the vector
            }
        } 
		else {
            cout << "The index c and Matrix are not suitable.\n";
        }
    } 
	else {
        cout << "The index Matrix is NULL\n";
    }
    return m3;
}

