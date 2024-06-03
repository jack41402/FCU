#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

// Overloaded >> operator to input a matrix
istream &operator>>(istream &input, Matrix &m){
    
    
    cout<<"Input Matrix: "<<m.row<<"X"<<m.col<<endl;
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            input>>m.m[i][j]; // Read each element of the matrix
        }
    }
    cout<<endl;
    return input;
}

// Overloaded + operator to add a scalar to a matrix
Matrix operator+(const double &s, const Matrix &M){
    
    Matrix sum;
    
    if(M.row>0 && M.col>0){
        
        sum.setSize(M.row, M.col); // Set size of the result matrix
        for(int i=0;i<M.row;i++)
        {
            for(int j=0;j<M.col;j++)
            {
                sum.m[i][j]=s+M.m[i][j]; // Add scalar to each element
            }
        }
    }
    else{
        cout<<"Scalar-matrix addition: The matrix is empty."<<endl;
        sum.row=0;
        sum.col=0;
        sum.m = NULL;
    }
    return sum;
}

// Deallocate memory for the matrix
void Matrix::deallocateMatrix(){
    if(m!=NULL){
        for(int i=0 ; i<row ; i++) delete [] m[i];
        delete [] m;
        m=NULL;
    }
}

// Overloaded * operator to multiply a scalar with a matrix
Matrix operator*(const double &s, const Matrix &M){
    Matrix w;
    
    if(M.row>0 && M.col>0){
        w.setSize(M.row, M.col);
        for(int i=0;i<M.row;i++)
        {
            for(int j=0;j<M.col;j++)
            {
                w.m[i][j] = s*M.m[i][j];
            }
                            
        }
            
    }
    else
    {
        cout<<"Scalar-matrix subtraction: The matrix is empty."<<endl;
        w.row=0;
        w.col=0;
        w.m=NULL;
    }
    return w;
}

// Allocate memory for the matrix
void Matrix::allocateMatrix()
{
    if(row>0 && col>0)
    {
        m=new double* [row];
        for(int i=0;i<row;i++) 
        {
            m[i] = new double [col];
        }
    }
    else 
    {
        m=NULL;
    }
}

// Overloaded - operator to subtract a matrix from a scalar
Matrix operator-(const double &s, const Matrix &M)
{
    Matrix diff;
    
    if(M.row>0 && M.col>0){
        diff.setSize(M.row, M.col);
        for(int i=0;i<M.row;i++)
        {
            for(int j=0;j<M.col;j++)
            {
                diff.m[i][j]=s-M.m[i][j];
            }
        }
    }
    else{
        cout<<"Scalar-matrix subtraction: The matrix is empty."<<endl;
        diff.row=0;
        diff.col=0;
        diff.m=NULL;
    }
    return diff;
}

// Constructor to initialize a matrix with given dimensions
Matrix::Matrix(int r, int a){
    if(r>0 && a>0) 
    {
        row=r;
        col=a;
        allocateMatrix();
    }
    else 
    {
        row=0; 
        col=0;
        m=NULL;
    }
}

// Destructor to deallocate memory
Matrix::~Matrix()
{
    if(row>0 && col>0)
    {
        deallocateMatrix();
    }
}

// Set an element in the matrix
void Matrix::setElement(int y, int q, double e){
    if(row>0 && col>0){
        
        if(y>=0 && y<row && q>=0 && q<col) 
        {
            m[y][q]=e;
        }
        
        else 
        {
            cout<<"Illegal matrix index ["<<y<<","<<q<<"]."<<endl;
        }
    }
    else 
    {
        cout<<"The matrix is empty."<<endl<<endl;
    }
}

// Get an element from the matrix
double Matrix::getElement(int r, int c) const
{
    if(row>0 && col>0)
    {
        if(r>=0 && r<row && c>=0 && c<col)
        {
            return m[r][c];
        }
        else
        {
            cout<<"Illegal matrix index ["<<r<<","<<c<<"]."<<endl; return 0.0;
        }
    }
    else 
    {
        cout<<"The matrix is empty."<<endl<<endl; return 0.0;
    }
}

// Set the size of the matrix and allocate memory
void Matrix::setSize(int t, int w){
    
    if(row>0 && col>0) 
    {
        deallocateMatrix();
    }
    if(t>0 && w>0)
    {
        row=t;
        col=w;
        allocateMatrix();
    }
    else{
        row=0;
        col=0;
        m=NULL;
    }
}

// Get the number of rows in the matrix
int Matrix::getRow() const{ return row; }
// Get the number of columns in the matrix
int Matrix::getCol() const{ return col; }

// Copy constructor to initialize a matrix with another matrix
Matrix::Matrix(const Matrix &M){

    if(M.row>0 && M.col>0) {
        
        row=M.row;
        
        col=M.col;
        
        allocateMatrix();
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                m[i][j]=M.m[i][j];
            }
        }
    }
    else
    {
        row=0; 
        col=0;
        m=NULL;
    }
}
// Overloaded + operator to add two matrices
Matrix Matrix::operator+(const Matrix &M) const{
    Matrix r;
    
    if(row==M.row && col==M.col){
        if(M.row>0 && M.col>0){
            r.setSize(row, col);
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    r.setElement(i, j, m[i][j]+M.m[i][j]);
                }
            }
                
        }
        
        else{
            cout<<"Matrix-matrix addition: One of the matrices is empty." <<endl;
            r.row=0; 
            r.col=0;
            r.m=NULL;
        }
    }
    else{
        cout<<"Matrix-matrix addition: The matrix operand sizes do not match."<<endl;
        r.row=0; 
        r.col=0;
        r.m=NULL;
    }
    return r;
}
// Overloaded << operator to output a matrix
ostream &operator<<(ostream &output, const Matrix &m){
    
    for(int i=0;i<m.row;i++){
        
        output<<"  ";
        
        for(int j=0;j<m.col;j++)
        {
            output<<setw(8)<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(4)<<m.m[i][j]<<" ";
        }
        output<<endl;
    }
    
    output<<endl;
    return output;
}
// Overloaded - operator to subtract two matrices
Matrix Matrix::operator-(const Matrix &M) const{
    
    Matrix d;
    
    int a, b;
    if(row==M.row && col==M.col){
        
        if(M.row>0 && M.col>0){
            d.setSize(row, col);
            for(a=0;a<row;a++)
                for(b=0;b<col;b++)
                    d.setElement(a, b, m[a][b]-M.m[a][b]);
        }
        else{
            cout<<"Matrix-matrix substraction: One of the matrices is empty." <<endl;
            d.row=0; d.col=0; d.m=NULL;
        }
    }
    else{
        cout<<"Matrix-matrix substraction: The matrix operand sizes do not match."<<endl;
        d.row=0; d.col=0; d.m=NULL;
    }
    return d;
}

// Overloaded * operator to multiply two matrices
Matrix Matrix::operator*(const Matrix &M) const{
    Matrix p;
    
    if(col==M.row)
    {
        if(row>0 && col>0 && M.col>0){
            p.setSize(row, M.col);
            
            int i, j, k;
            for(i=0;i<row;i++){
                for(j=0;j<M.col;j++){
                    p.m[i][j]=0;
                    for(k=0;k<col;k++) p.m[i][j]+=m[i][k]*M.m[k][j];
                }
            }
        }
        else{
            cout<<"Matrix-matrix multiplication: One of the matrices is empty."<<endl;
            p.row=0; p.col=0; p.m=NULL;
        }
    }
    else{
        cout<<"Matrix-matrix multiplication: The matrix operand sizes do not match."<<endl;
        p.row=0; p.col=0; p.m=NULL;
    }
    return p;
}

Matrix Matrix::operator+(const double &s) const{
    Matrix r;
    if(row>0 && col>0)
    {
        r.setSize(row, col);
        
        int i, j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                r.m[i][j]=m[i][j]+s;
            }
        }
    }
    else
    {
        cout<<"Matrix-scalar addition: The matrix is empty."<<endl;
        r.row=0; r.col=0; r.m=NULL;
    }
    return r;
}


Matrix Matrix::operator-(const double &s) const{
    Matrix r;
    if(row>0 && col>0){
        r.setSize(row, col);
        
        int i, j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                r.m[i][j]=m[i][j]-s;
            }
        }
    }
    else
    {
        cout<<"Matrix-scalar subtraction: The matrix is empty."<<endl;
        r.row=0; r.col=0; r.m=NULL;
    }
    return r;
}

// Overloaded * operator to multiply a matrix by a scalar
Matrix Matrix::operator*(const double &s) const{
    Matrix prou;
    if(row>0 && col>0){
        prou.setSize(row, col);
        int i, j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                prou.m[i][j]=m[i][j]*s;// Multiply each element by scalar
            }
        }
    }
    
    else{
        cout<<"Matrix-scalar multiplication: The matrix is empty."<<endl;
        prou.row=0; prou.col=0; prou.m=NULL;
    }
    return prou;
}


bool Matrix::operator==(const Matrix &M) const{
    if(row==M.row && col==M.col){
        if(row>0 && col>0){
            
            int i, j;
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    if(m[i][j]!=M.m[i][j]) 
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else{
            cout<<"Matrix relation: One of the matrices is empty."<<endl;
            return false;
        }
    }
    else{
        cout<<"Matrix relation: The operand matrix sizes do not match."<< endl;
        return false;
    }
}
// Overloaded != operator to compare two matrices for inequality
bool Matrix::operator!=(const Matrix &M) const{
    return !(*this==M);
}

Matrix &Matrix::operator-=(const Matrix &M)
{
    *this=*this-M;
    return *this;
}


Matrix &Matrix::operator=(const Matrix &M){
    if(row>0 && col>0) 
    {
        deallocateMatrix();
    }
    
    if(M.row>0 && M.col>0)
    {
        setSize(M.row, M.col);
        int i, j;
        for(i=0;i<M.row;i++)
        {
            for(j=0;j<M.col;j++)
            {
                m[i][j]=M.m[i][j];
            }
        }
    }
    
    else
    {
        row=0; col=0; m=NULL;
    }
    return *this;
}



Matrix &Matrix::operator+=(const Matrix &M)
{
    *this=*this+M;
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &M)
{
    *this=*this*M;
    return *this;
}



Matrix Matrix::operator-() const
{
    Matrix T(col, row);
    int i, j;
    
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            T.m[i][j]=m[j][i];
        }
    }
        
    return T;
}
