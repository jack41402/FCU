// matrix.cpp

#include "matrix.h" 
#include <iostream> 
#include <iomanip>  
#include <stdexcept> 

using namespace std; 

//Constructor to initialize matrix with given rows and columns
Matrix::Matrix(int rows, int cols) : row(rows), col(cols) 
{
    allocateMatrix(); //Allocate memory for the matrix
}

//Copy constructor to initialize matrix from another matrix
Matrix::Matrix(const Matrix &other) : row(other.row), col(other.col) 
{
    int i, j; //Loop variable
    allocateMatrix(); //Allocate memory for the matrix
    for(i = 0; i < row; i++) //Loop through each row
    {
        for(j = 0; j < col; j++) //Loop through each column
        {
            m[i][j] = other.m[i][j]; // Copy elements from the other matrix
        }
    }
}

//Destructor to deallocate memory of the matrix
Matrix::~Matrix() 
{
    deallocateMatrix(); //Deallocate memory
}

//Function to allocate memory for the matrix
void Matrix::allocateMatrix() 
{
    int i; //Loop variable
    m = new double*[row]; //Allocate memory for row pointers
    for(i = 0; i < row; i++) //Loop through each row
    {
        m[i] = new double[col]; //Allocate memory for each column
    }
}

//Function to deallocate memory of the matrix
void Matrix::deallocateMatrix() 
{
    int i; //Loop variable
    for(i = 0; i < row; i++) //Loop through each row
    {
        delete[] m[i]; //Delete each column array
    }
    delete[] m; //Delete row pointers array
}

//Function to set the size of the matrix and reallocate memory
void Matrix::setSize(int rows, int cols) 
{
    deallocateMatrix(); //Deallocate existing memory
    row = rows; //Set new row size
    col = cols; //Set new column size
    allocateMatrix(); //Allocate memory for the new size
}

//Function to set the value of a specific element in the matrix
void Matrix::setElement(int r, int c, double value) 
{
    if(r >= row || c >= col) //Check if indices are out of range
    {
        throw out_of_range("Index out of range"); //Throw an exception if out of range
    }
    m[r][c] = value; //Set the value at the specified position
}

//Function to get the value of a specific element in the matrix
double Matrix::getElement(int r, int c) const 
{
    if(r >= row || c >= col) //Check if indices are out of range
    {
        throw out_of_range("Index out of range"); //Throw an exception if out of range
    }
    return m[r][c]; //Return the value at the specified position
}

//Function to get the number of rows in the matrix
int Matrix::getRow() const 
{
    return row; //Return the number of rows
}

//Function to get the number of columns in the matrix
int Matrix::getCol() const 
{
    return col; //Return the number of columns
}

//Assignment operator to assign one matrix to another
Matrix& Matrix::operator=(const Matrix &other) 
{
    int i, j; //Loop variable
    if(this != &other) //Check for self-assignment
    {
        setSize(other.row, other.col); //Set the size to match the other matrix
        for(i = 0; i < row; i++) //Loop through each row
        {
            for(j = 0; j < col; j++) //Loop through each column
            {
                m[i][j] = other.m[i][j]; //Copy elements from the other matrix
            }
        }
    }
    return *this; //Return the current matrix
}

//Addition operator to add two matrices
Matrix Matrix::operator+(const Matrix &other) const 
{
    int i, j; //Loop variable
    if(row != other.row || col != other.col) // Check if dimensions match
    {
        throw invalid_argument("Matrix dimensions must match for addition."); //Throw an exception if dimensions do not match
    }
    Matrix result(row, col); //Create a result matrix
    for(i = 0; i < row; i++) //Loop through each row
    {
        for(j = 0; j < col; j++) //Loop through each column
        {
            result.m[i][j] = m[i][j] + other.m[i][j]; //Add corresponding elements
        }
    }
    return result; //Return the result matrix
}

//Subtraction operator to subtract one matrix from another
Matrix Matrix::operator-(const Matrix &other) const 
{
    int i, j; //Loop variable
    if(row != other.row || col != other.col) //Check if dimensions match
    {
        throw invalid_argument("Matrix dimensions must match for subtraction."); //Throw an exception if dimensions do not match
    }
    Matrix result(row, col); //Create a result matrix
    for(i = 0; i < row; i++) //Loop through each row
    {
        for(j = 0; j < col; j++) //Loop through each column
        {
            result.m[i][j] = m[i][j] - other.m[i][j]; //Subtract corresponding elements
        }
    }
    return result; //Return the result matrix
}

//Multiplication operator to multiply two matrices
Matrix Matrix::operator*(const Matrix &other) const 
{
    int i, j, k; //Loop variable
    if(col != other.row) //Check if dimensions match for multiplication
    {
        throw invalid_argument("Matrix dimensions must match for multiplication."); //Throw an exception if dimensions do not match
    }
    Matrix result(row, other.col); //Create a result matrix
    for(i = 0; i < row; i++) //Loop through each row of the first matrix
    {
        for(j = 0; j < other.col; j++) //Loop through each column of the second matrix
        {
            result.m[i][j] = 0; //Initialize the result element to zero
            for(k = 0; k < col; k++) //Loop through each element in the row and column
            {
                result.m[i][j] += m[i][k] * other.m[k][j]; //Multiply and accumulate the result
            }
        }
    }
    return result; //Return the result matrix
}

//Overloaded output stream operator to print the matrix
ostream &operator<<(ostream &out, const Matrix &matrix) 
{
    int i, j; //Loop variable
    for(i = 0; i < matrix.row; i++) //Loop through each row
    {
        for(j = 0; j < matrix.col; j++) //Loop through each column
        {
            out << fixed << setprecision(4) << setw(10) << matrix.m[i][j] << " "; //Print the matrix element with formatting
        }
        out << endl; //Print a new line at the end of each row
    }
    return out; //Return the output stream
}

//Overloaded input stream operator to read the matrix
istream &operator>>(istream &in, Matrix &matrix) 
{
    int i, j; //Loop variable
    for(i = 0; i < matrix.row; i++) //Loop through each row
    {
        for(j = 0; j < matrix.col; j++) //Loop through each column
        {
            in >> matrix.m[i][j]; //Read the matrix element
        }
    }
    return in; //Return the input stream
}

