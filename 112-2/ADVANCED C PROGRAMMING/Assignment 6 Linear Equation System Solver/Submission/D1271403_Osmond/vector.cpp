#include <iostream>
#include "vector.h"

Vector::Vector(int n){
    if(n>0){ row=n; col=1; allocateMatrix(); }
    else{ row=0; col=0; m=NULL;}
}

Vector::Vector(const Matrix &M, const int j){ // copy constructor from a matrix a column index
    if(j>=0 && j<M.getCol()){
        row=M.getRow();
        col=1;
        allocateMatrix();
        for(int i=0;i<row;i++) m[i][0]=M.getElement(i, j);
    }
    else{
        cout<<"The column index is out of range."<<endl<<endl;
        row=0; col=0; m=NULL;
    }
}

Vector::Vector(const Vector &v){
    if(v.row>0 && v.col==1){
        row=v.row;
        col=1;
        allocateMatrix();
        for(int i=0;i<row;i++) { m[i][0]=v.m[i][0]; }
    }
    else{ row=0; col=0; m=NULL; }
}

void Vector::setSize(const int n){
    if(m!=NULL) deallocateMatrix();
    if(n>0){ row=n; col=1; allocateMatrix(); }
    else{ row=0; col=0; m=NULL; }
}

Matrix Vector::vector_replace(int n, const Matrix &M){
    Matrix R;
    if(M.getCol()>0 && M.getRow()>0 && n>=0 && n<M.getCol() && col==1 && row==M.getRow()){
        R.setSize(M.getRow(), M.getCol());
        int i, j;
        for(i=0;i<M.getRow();i++)
            for(j=0;j<M.getCol();j++){ R.setElement(i, j, M.getElement(i, j)); }
        for(i=0;i<M.getRow();i++) { R.setElement(i, n, m[i][0]); }
    }
    else{ row=0; col=0; m=NULL; }
    return R;
}
