#include <iostream>
#include <iomanip>
#include "matrix.h"
using namespace std;

ostream &operator<<(ostream &output, const Matrix &m){
    int i, j;
    for(i=0;i<m.row;i++){
        output<<"  ";
        for(j=0;j<m.col;j++){
            output<<setw(8)<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(4)<<m.m[i][j]<<" ";
        }
        output<<endl;
    }
    output<<endl;
    return output;
}

istream &operator>>(istream &input, Matrix &m){
    int i, j;
    cout<<"Input Matrix: "<<m.row<<"X"<<m.col<<endl;
    for(i=0;i<m.row;i++)
        for(j=0;j<m.col;j++)
            input>>m.m[i][j];
    cout<<endl;
    return input;
}

Matrix operator+(const double &s, const Matrix &M){
    Matrix sum;
    int i, j;
    if(M.row>0 && M.col>0){
        sum.setSize(M.row, M.col);
        for(i=0;i<M.row;i++)
            for(j=0;j<M.col;j++)
                sum.m[i][j]=s+M.m[i][j];
    }
    else{
        cout<<"Scalar-matrix addition: The matrix is empty."<<endl;
        sum.row=0;
        sum.col=0;
        sum.m=NULL;
    }
    return sum;
}

Matrix operator-(const double &s, const Matrix &M){
    Matrix diff;
    int i, j;
    if(M.row>0 && M.col>0){
        diff.setSize(M.row, M.col);
        for(i=0;i<M.row;i++)
            for(j=0;j<M.col;j++)
                diff.m[i][j]=s-M.m[i][j];
    }
    else{
        cout<<"Scalar-matrix subtraction: The matrix is empty."<<endl;
        diff.row=0;
        diff.col=0;
        diff.m=NULL;
    }
    return diff;
}

Matrix operator*(const double &s, const Matrix &M){
    Matrix prou;
    int i, j;
    if(M.row>0 && M.col>0){
        prou.setSize(M.row, M.col);
        for(i=0;i<M.row;i++)
            for(j=0;j<M.col;j++)
                prou.m[i][j]=s*M.m[i][j];
    }
    else{
        cout<<"Scalar-matrix subtraction: The matrix is empty."<<endl;
        prou.row=0;
        prou.col=0;
        prou.m=NULL;
    }
    return prou;
}

void Matrix::allocateMatrix(){
    if(row>0 && col>0){
        m=new double* [row];
        for(int i=0;i<row;i++) m[i]=new double [col];
    }
    else m=NULL;
}

void Matrix::deallocateMatrix(){
    if(m!=NULL){
        for(int i=0;i<row;i++) delete [] m[i];
        delete [] m;
        m=NULL;
    }
}

Matrix::Matrix(int r, int c){
    if(r>0 && c>0) { row=r; col=c; allocateMatrix(); }
    else { row=0; col=0; m=NULL; }
}

Matrix::Matrix(const Matrix &M){
    int i, j;
    if(M.row>0 && M.col>0) {
        row=M.row;
        col=M.col;
        allocateMatrix();
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                m[i][j]=M.m[i][j];
    }
    else{ row=0; col=0; m=NULL; }
}

Matrix::~Matrix(){ if(row>0 && col>0) deallocateMatrix(); }

void Matrix::setSize(int r, int c){
    if(row>0 && col>0) deallocateMatrix();
    if(r>0 && c>0){
        row=r;
        col=c;
        allocateMatrix();
    }
    else{
        row=0;
        col=0;
        m=NULL;
    }
}

void Matrix::setElement(int r, int c, double e){
    if(row>0 && col>0){
        if(r>=0 && r<row && c>=0 && c<col) m[r][c]=e;
        else cout<<"Illegal matrix index ["<<r<<","<<c<<"]."<<endl;
    }
    else cout<<"The matrix is empty."<<endl<<endl;
}

double Matrix::getElement(int r, int c) const{
    if(row>0 && col>0){
        if(r>=0 && r<row && c>=0 && c<col) return m[r][c];
        else { cout<<"Illegal matrix index ["<<r<<","<<c<<"]."<<endl; return 0.0; }
    }
    else { cout<<"The matrix is empty."<<endl<<endl; return 0.0; }
}

int Matrix::getRow() const{ return row; }

int Matrix::getCol() const{ return col; }

Matrix Matrix::operator+(const Matrix &M) const{
    Matrix sum;
    int i, j;
    if(row==M.row && col==M.col){
        if(M.row>0 && M.col>0){
            sum.setSize(row, col);
            for(i=0;i<row;i++)
                for(j=0;j<col;j++)
                    sum.setElement(i, j, m[i][j]+M.m[i][j]);
        }
        else{
            cout<<"Matrix-matrix addition: One of the matrices is empty." <<endl;
            sum.row=0; sum.col=0; sum.m=NULL;
        }
    }
    else{
        cout<<"Matrix-matrix addition: The matrix operand sizes do not match."<<endl;
        sum.row=0; sum.col=0; sum.m=NULL;
    }
    return sum;
}

Matrix Matrix::operator-(const Matrix &M) const{
    Matrix diff;
    int i, j;
    if(row==M.row && col==M.col){
        if(M.row>0 && M.col>0){
            diff.setSize(row, col);
            for(i=0;i<row;i++)
                for(j=0;j<col;j++)
                    diff.setElement(i, j, m[i][j]-M.m[i][j]);
        }
        else{
            cout<<"Matrix-matrix substraction: One of the matrices is empty." <<endl;
            diff.row=0; diff.col=0; diff.m=NULL;
        }
    }
    else{
        cout<<"Matrix-matrix substraction: The matrix operand sizes do not match."<<endl;
        diff.row=0; diff.col=0; diff.m=NULL;
    }
    return diff;
}

Matrix Matrix::operator*(const Matrix &M) const{
    Matrix prou;
    if(col==M.row){
        if(row>0 && col>0 && M.col>0){
            prou.setSize(row, M.col);
            int i, j, k;
            for(i=0;i<row;i++){
                for(j=0;j<M.col;j++){
                    prou.m[i][j]=0;
                    for(k=0;k<col;k++) prou.m[i][j]+=m[i][k]*M.m[k][j];
                }
            }
        }
        else{
            cout<<"Matrix-matrix multiplication: One of the matrices is empty."<<endl;
            prou.row=0; prou.col=0; prou.m=NULL;
        }
    }
    else{
        cout<<"Matrix-matrix multiplication: The matrix operand sizes do not match."<<endl;
        prou.row=0; prou.col=0; prou.m=NULL;
    }
    return prou;
}

Matrix Matrix::operator+(const double &s) const{
    Matrix sum;
    if(row>0 && col>0){
        sum.setSize(row, col);
        int i, j;
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                sum.m[i][j]=m[i][j]+s;
    }
    else{
        cout<<"Matrix-scalar addition: The matrix is empty."<<endl;
        sum.row=0; sum.col=0; sum.m=NULL;
    }
    return sum;
}

Matrix Matrix::operator-(const double &s) const{
    Matrix diff;
    if(row>0 && col>0){
        diff.setSize(row, col);
        int i, j;
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                diff.m[i][j]=m[i][j]-s;
    }
    else{
        cout<<"Matrix-scalar subtraction: The matrix is empty."<<endl;
        diff.row=0; diff.col=0; diff.m=NULL;
    }
    return diff;
}

Matrix Matrix::operator*(const double &s) const{
    Matrix prou;
    if(row>0 && col>0){
        prou.setSize(row, col);
        int i, j;
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                prou.m[i][j]=m[i][j]*s;
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
            for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                    if(m[i][j]!=M.m[i][j]) return false;
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

bool Matrix::operator!=(const Matrix &M) const{
    return !(*this==M);
}

Matrix &Matrix::operator=(const Matrix &M){
    if(row>0 && col>0) deallocateMatrix();
    if(M.row>0 && M.col>0){
        setSize(M.row, M.col);
        int i, j;
        for(i=0;i<M.row;i++){
            for(j=0;j<M.col;j++){
                m[i][j]=M.m[i][j];
            }
        }
    }
    else{ row=0; col=0; m=NULL; }
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &M){
    *this=*this+M;
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &M){
    *this=*this-M;
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &M){
    *this=*this*M;
    return *this;
}

Matrix Matrix::operator-() const{
    Matrix T(col, row);
    int i, j;
    for(i=0;i<col;i++)
        for(j=0;j<row;j++)
            T.m[i][j]=m[j][i];
    return T;
}
