#include <iostream>
#include "vector.h"

// Constructor to create a Vector from a specified column of a Matrix
Vector::Vector(const Matrix &M, const int j){ // copy constructor from a matrix a column index
    // Check if the column index is within the valid range
    if (j>=0 && j<M.getCol())
        
    {
        row=M.getRow();
        col=1;
        allocateMatrix();
        for(int i=0 ; i<row ; i++ )
        {
            m[i][0]=M.getElement(i, j);
        }
    }
    
    else
    {
        cout<<"The column index is out of range."<<endl<<endl;
        row=0; 
        col=0;
        m=NULL;
    }
}
// Copy constructor to create a Vector from another Vector
Vector::Vector(const Vector &v)

{
    if(v.row>0 && v.col==1)
    {
        row=v.row;
        col=1;
        allocateMatrix();
        for(int i=0;i<row;i++) { m[i][0]=v.m[i][0]; }
    }
    else
    {
        row=0; col=0; m=NULL;
    }
}

Vector::Vector(int u)
{
    if(u>0)
    {
        row=u; 
        col=1;
        allocateMatrix();
    }
    else
    {
        row=0; 
        col=0;
        m=NULL;
    }
}
// Method to set the size of the Vector
void Vector::setSize(const int n)
{
    if(m!=NULL) 
    {
        deallocateMatrix();
    }
    
    if(n>0)
    {
        row=n; 
        col=1;
        allocateMatrix();
    }
    else
    {
        row=0; 
        col=0;
        m=NULL;
    }
}
// Method to replace a column in a Matrix with the Vector
Matrix Vector::vector_replace(int e, const Matrix &M)
{
    Matrix t;
    
    if (M.getCol() > 0 && M.getRow()>0 && e>=0 && e<M.getCol() && col==1 && row==M.getRow())
    {
        t.setSize(M.getRow(), M.getCol());
        
        for(int i=0;i<M.getRow();i++)
        {
            for(int j=0;j<M.getCol();j++)
            {
                t.setElement(i, j, M.getElement(i, j));
            }
        }
            
        for(int i=0 ; i<M.getRow() ; i++)
        {
            t.setElement(i, e, m[i][0]);
        }
    }
    else
    {
        row=0;
        col=0;
        m=NULL;
    }
    return t;
}

