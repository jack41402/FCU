#include <iostream>
#include <cmath>
#include "smatrix.h"

SMatrix::SMatrix(int n){
    if(n>0){
        row=n;
        col=n;
        allocateMatrix();
    }
    else{
        row=0;
        col=0;
        m=NULL;
    }
}

SMatrix::SMatrix(const Matrix &M){
    if(M.getRow()==M.getCol()){
        if(M.getRow()>0 && M.getCol()>0){
            row=M.getRow();
            col=M.getCol();
            allocateMatrix();
            int i, j;
            for(i=0;i<M.getRow();i++)
                for(j=0;j<M.getCol();j++)
                    m[i][j]=M.getElement(i, j);
        }
        else { row=0; col=0; m=NULL; }
    }
    else{
        cout<<"The matrix is not a square matrix."<<endl<<endl;
        row=0; col=0; m=NULL;
    }
}

SMatrix::SMatrix(const SMatrix &S){
    if(S.row>0 && S.col>0){
        row=S.row;
        col=S.col;
        allocateMatrix();
        int i, j;
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                m[i][j]=S.getElement(i, j);
    }
    else{ row=0; col=0; m=NULL; }
}

void SMatrix::setSize(const int n){
    if(m!=NULL) deallocateMatrix();
    if(n>0){ row=n; col=n; allocateMatrix(); }
    else{ row=0; col=0; m=NULL; }
}

double SMatrix::determinant() const{
    double d=0.0;
    int j, p, q;
    if(row==1){ d=m[0][0]; }
    else if(row>1){
        SMatrix cofactor(row-1);
        for(j=0;j<row;j++){
            for(p=0;p<row-1;p++){
                for(q=0;q<row-1;q++){
                    if(q<j) cofactor.setElement(p, q, m[p+1][q]);
                    if(q>=j) cofactor.setElement(p, q, m[p+1][q+1]);
                }
            }
            d+=pow(-1, j%2)*m[0][j]*cofactor.determinant();
        }
    }
    else cout<<"The matrix is empty."<<endl<<endl;
    return d;
}
