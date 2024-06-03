#include "vector.h"
#include <iostream>

//default vector constructor
Vector::Vector(int size) : Matrix(size, 1) {
    //initialize the vector as a column vector of given size
}

//copy constructor from a matrix and a column index
Vector::Vector(const Matrix& mat, const int colIndex) : Matrix(mat.getRow(), 1) {
    //copy the specified column from the matrix to the vector
    if (colIndex < 0 || colIndex >= mat.getCol()) {
        std::cerr << "Column index out of bounds" << std::endl;
        exit(1);
    }
    for (int i = 0; i < mat.getRow(); ++i) {
        this->setElement(i, 0, mat.getElement(i, colIndex));
    }
}

//copy constructor from a vector
Vector::Vector(const Vector& vec) : Matrix(vec) {
    //copy the vector
}

//set the size of the vector
void Vector::setSize(const int size) {
    Matrix::setSize(size, 1);
}

//replace a column of a matrix by the vector
Matrix Vector::vector_replace(int colIndex, const Matrix& mat) {
    if (this->getRow() != mat.getRow()) {
        std::cout << "Vector and matrix row size mismatch" << std::endl;
        exit(1);
    }
    if (colIndex < 0 || colIndex >= mat.getCol()) {
        std::cout << "Column index out of bounds" << std::endl;
        exit(1);
    }
    Matrix result(mat); //create a copy of the matrix
    for (int i = 0; i < this->getRow(); ++i) {
        result.setElement(i, colIndex, this->getElement(i, 0));
    }
    return result;
}

