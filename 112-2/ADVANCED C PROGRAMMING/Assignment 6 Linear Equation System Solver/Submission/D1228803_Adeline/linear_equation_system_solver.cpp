// linear_equation_system_solver.cpp

#include <iostream> 
#include <cstdlib> 
#include <ctime>   
#include <iomanip>  
#include <cmath>    
#include "smatrix.h" 
#include "vector.h"

using namespace std; 

//Function to print the system of linear equations in matrix form
void printSystem(const SMatrix &A, const Vector &C) 
{
    int i, j; //Loop variable
    int n = A.getRow(); //Get the number of rows in matrix A
    cout << "System of linear equations:\n"; // Print header
    for(i = 0; i < n; i++) //Loop through each row
    {
        cout << "    "; //Print leading spaces for formatting
        for(j = 0; j < n; j++) //Loop through each column
        {
            cout << fixed << setprecision(4) << A.getElement(i, j) << "X_" << j; //Print matrix element with variable
            if(j < n - 1) cout << "+"; //Print plus sign if not the last element in the row
        }
        cout << "=" << fixed << setprecision(4) << C.getElement(i, 0) << "\n"; //Print constant
    }
}

//Function to verify the solution of the linear equation system
void verifySolution(const SMatrix &A, const Vector &X, const Vector &C) 
{
    int i; //Loop variable
    Vector AX = static_cast<Vector>(A * X); //Calculate A * X
    Vector AX_C = AX - C; //Calculate A * X - C
    int n = AX.getRow(); //Get the number of rows in AX
    cout << "Verify solution of the linear equation system:\n"; //Print header
    for(i = 0; i < n; i++) //Loop through each equation
    {
        if(std::fabs(AX_C.getElement(i, 0)) < 1e-6) 
        {
            cout << "    Equation " << i << " passes.\n"; //Verify succeed
        } 
        else 
        {
            cout << "    Equation " << i << " fails.\n"; //Verify failed
        }
    }
}

//Function to print the matrix with formatted output
void printMatrix(const Matrix &matrix) 
{
    int i, j; //Loop variable
    int rows = matrix.getRow(); //Get the number of rows in the matrix
    int cols = matrix.getCol(); //Get the number of columns in the matrix
    for(i = 0; i < rows; i++) //Loop through each row
    {
        for(j = 0; j < cols; j++) //Loop through each column
        {
            cout << fixed << setprecision(4) << setw(10) << matrix.getElement(i, j) << " "; //Matrix element with formatting
        }
        cout << endl; 
    }
}

//Function to print the vector with formatted output
void printVector(const Vector &vector) 
{
    int i; //Loop variable
    int rows = vector.getRow(); //Get the number of rows in the vector
    for(i = 0; i < rows; i++) //Loop through each row
    {
        cout << fixed << setprecision(4) << setw(10) << vector.getElement(i, 0) << " "; //Print vector element with formatting
    }
    cout << endl; //Print new line at the end
}

int main() 
{
    int i, j; //Loop variable
    srand(time(0)); //Seed the random number generator with the current time
    int n; //Variable to store the rank of the linear equation system
    cout << "Input n as the rank of the linear equation system (0 < n <= 10): "; //Prompt user for input
    cin >> n; //Read user input

    // Validate the rank input
    if(n <= 0 || n > 10) 
    {
        cout << "Invalid rank!" << endl; //Print error message
        return 1; //Exit the program
    }

    SMatrix A(n); //Declare matrix A with size n
    Vector C(n); //Declare vector C with size n

    //Randomly generate elements for A and C
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++) 
        {
            A.setElement(i, j, static_cast<double>(rand()) / RAND_MAX); //Set random elements in matrix A
        }
        C.setElement(i, 0, static_cast<double>(rand()) / RAND_MAX); //Set random elements in vector C
    }

    //Print coefficient matrix
    cout << "Coefficient matrix of the system of linear equations: \n"; 
    printMatrix(A); 

    //Print constant vector
    cout << "Constant vector of the system of linear equations: \n";
    printVector(C); 
    
    //Print the system of equations
    printSystem(A, C); 

    //Solve the linear system
    Vector X(n); //Declare vector X to store the solution
    double detA = A.determinant(); //Calculate the determinant of matrix A
    if(fabs(detA) < 1e-6) //Check if the determinant is too close to zero
    {
        cout << "The determinant of A is too close to zero, the system may be singular or ill-conditioned." << endl; //Print error message
        return 1; //Exit the program
    }
    for(i = 0; i < n; i++) 
    {
        SMatrix Ai = static_cast<SMatrix>(C.vector_replace(i, A)); //Replace column i of A with vector C
        X.setElement(i, 0, Ai.determinant() / detA); //Calculate solution for each variable
    }

    // Print the solution vector
    cout << "Solution of the linear equation system is: \n"; 
    printVector(X); 

    //Verify the solution
    verifySolution(A, X, C);

    return 0; 
}

