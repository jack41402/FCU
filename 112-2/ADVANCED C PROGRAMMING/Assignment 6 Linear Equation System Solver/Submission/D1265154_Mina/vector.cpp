#include <iomanip>
#include "vector.h"

using namespace std;

// Overloaded output stream operator to print the vector
ostream &operator<<(ostream& output, const Vector &V) {
    int i;
    for (i = 0; i < V.row; i++) {
        output << setw(9) << V.m[i][0];
    }
    output << endl;
    return output;
}

// Constructor that initializes a Vector by calling the Matrix constructor with rows and 1 column
Vector::Vector(int r) : Matrix(r, 1) {}

// Constructor that initializes a Vector from a specified column of a given Matrix
Vector::Vector(const Matrix &M, const int c) {
    int i;
    row = M.getRow();
    col = 1;
    allocateMatrix();
    for (i = 0; i < row; i++) {
        m[i][0] = M.getElement(i, c);
    }
}

// Copy constructor for Vector
Vector::Vector(const Vector &V) {
    int i;
    row = V.row;
    col = 1;
    allocateMatrix();
    for (i = 0; i < row; i++) {
        m[i][0] = V.m[i][0];
    }
}

// Set the size of the Vector (with a single column)
void Vector::setSize(const int r) {
    Matrix::setSize(r, 1);
}

// Function to replace a specified column in a given Matrix with the current Vector
Matrix Vector::vector_replace(int c, const Matrix &M) const {
    int i;
    Matrix result(M);
    for (i = 0; i < row; i++) {
        result.setElement(i, c, m[i][0]);
    }
    return result;
}

