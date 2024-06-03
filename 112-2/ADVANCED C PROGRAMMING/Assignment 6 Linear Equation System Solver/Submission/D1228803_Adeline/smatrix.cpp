// smatrix.cpp

#include "smatrix.h" 
#include <stdexcept> 

//Constructor to initialize a square matrix with given size
SMatrix::SMatrix(int size) : Matrix(size, size) 
{
    
}

//Constructor to initialize a square matrix from a Matrix object
SMatrix::SMatrix(const Matrix &other) : Matrix(other) 
{
    if(other.getRow() != other.getCol()) //Check if the matrix is not square
    {
        throw std::invalid_argument("Matrix is not square"); //Throw an exception if not square
    }
}

//Copy constructor to initialize a square matrix from another SMatrix object
SMatrix::SMatrix(const SMatrix &other) : Matrix(other) 
{
    
}

//Function to set the size of the square matrix
void SMatrix::setSize(int size) 
{
    Matrix::setSize(size, size); //Call the base class function to set the size
}

//Function to calculate the determinant of the square matrix
double SMatrix::determinant() const 
{
    int i, j, k; //Loop variable

    if(row != col) //Check if the matrix is not square
    {
        throw std::logic_error("Matrix is not square"); //Throw an exception if not square
    }

    //Base case for 1x1 matrix
    if(row == 1) 
    {
        return m[0][0]; //Return the single element
    }

    // Base case for 2x2 matrix
    if(row == 2) 
    {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0]; //Return the determinant of 2x2 matrix
    }

    //Recursive case for larger matrices
    double det = 0.0; //Initialize determinant to 0
    for(k = 0; k < col; k++) //Loop through each column of the first row
    {
        SMatrix subMatrix(row - 1); //Create a submatrix of size (row-1)x(row-1)
        for(i = 1; i < row; i++) //Loop through each row starting from the second row
        {
            int colIndex = 0; //Initialize column index for submatrix
            for(j = 0; j < col; j++) //Loop through each column
            {
                if (j == k) continue; //Skip the current column of the first row
                subMatrix.setElement(i - 1, colIndex, m[i][j]); //Set elements in the submatrix
                colIndex++; //Increment column index for submatrix
            }
        }

        //Add or subtract the cofactor multiplied by the determinant of the submatrix
        if(k % 2 == 0) 
        {
            det += m[0][k] * subMatrix.determinant(); //Add if column index is even
        } 
        else 
        {
            det -= m[0][k] * subMatrix.determinant(); //Subtract if column index is odd
        }
    }

    return det; //Return the determinant of the matrix
}

