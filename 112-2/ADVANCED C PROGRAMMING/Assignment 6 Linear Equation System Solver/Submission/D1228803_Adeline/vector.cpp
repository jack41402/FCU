// vector.cpp

#include "vector.h"    
#include <stdexcept>

//Constructor to initialize a vector with a given size
Vector::Vector(int size) : Matrix(size, 1) 
{
  
}

//Constructor to initialize a vector from a specific column of a matrix
Vector::Vector(const Matrix &matrix, int colIndex) : Matrix(matrix.getRow(), 1) 
{
    int i; // Loop variable
    for(i = 0; i < matrix.getRow(); i++) //Loop through each row
    {
        setElement(i, 0, matrix.getElement(i, colIndex)); //Set vector element from matrix column
    }
}

//Copy constructor to initialize a vector from another vector
Vector::Vector(const Vector &other) : Matrix(other) 
{
    
}

//Constructor to initialize a vector from a matrix with one column
Vector::Vector(const Matrix &matrix) : Matrix(matrix.getRow(), 1) 
{
    int i; //Loop variable

    if(matrix.getCol() != 1) //Check if the matrix has more than one column
    {
        throw std::invalid_argument("Matrix must have exactly one column to convert to Vector."); //Throw an exception if not
    }
    for(i = 0; i < matrix.getRow(); i++) //Loop through each row
    {
        setElement(i, 0, matrix.getElement(i, 0)); //Set vector element from matrix column
    }
}

//Function to set the size of the vector
void Vector::setSize(int size) 
{
    Matrix::setSize(size, 1); //Call the base class function to set the size with one column
}

//Function to replace a column in a matrix with the vector
Matrix Vector::vector_replace(int colIndex, const Matrix &matrix) const 
{
    int i; //Loop variable

    if(matrix.getRow() != getRow()) //Check if the number of rows in matrix and vector match
    {
        throw std::invalid_argument("Matrix and vector size mismatch"); //Throw an exception if sizes do not match
    }
    Matrix result(matrix); //Create a copy of the matrix
    for(i = 0; i < getRow(); i++) //Loop through each row
    {
        result.setElement(i, colIndex, getElement(i, 0)); //Replace matrix column with vector elements
    }

    return result; //Return the modified matrix
}

//Subtraction operator to subtract one vector from another
Vector Vector::operator-(const Vector &other) const 
{
    int i; //Loop variable

    if(getRow() != other.getRow()) //Check if the vectors have the same length
    {
        throw std::invalid_argument("Vectors must be of the same length for subtraction."); //Throw an exception if lengths do not match
    }

    Vector result(getRow()); //Create a result vector with the same length

    for(i = 0; i < getRow(); i++) //Loop through each element
    {
        result.setElement(i, 0, getElement(i, 0) - other.getElement(i, 0)); //Subtract corresponding elements
    }

    return result; //Return the result vector
}

