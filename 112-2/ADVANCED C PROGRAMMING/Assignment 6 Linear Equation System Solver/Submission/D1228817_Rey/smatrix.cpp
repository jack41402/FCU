#include<iostream>
#include<cstdlib>
#include<cmath>
#include "smatrix.h"
using namespace std;

SMatrix::SMatrix(int n):Matrix(n, n){//Construct a SMatrix object using the Matrix default constructor
}

SMatrix::SMatrix(const Matrix& M){
	int i, j;

	if((M.getRow()==M.getCol())&&M.getRow()>0){//If the row and col of matrix is the same and >0
		row=col=M.getRow();
		allocateMatrix();
		
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				m[i][j]=M.getElement(i, j);
			}
		}
	}
	
	else{
		row=0;
		col=0;
		m=NULL;
	}
}
	
SMatrix::SMatrix(const SMatrix& S):Matrix(S){//Construct a SMatrix object using the Matrix copy constructor
}

void SMatrix::setSize(const int n){//Set the size of Smatrix using setSize of Matrix
	Matrix::setSize(n, n);
}

double SMatrix::determinant() const{
	int j, p, q;
	double det=0.0;
	
	if(row==1) det=m[0][0];
	
	else if(row>0){
		SMatrix cof(row-1);
		for(j=0; j<row; j++){
			for(p=0; p<row-1; p++){
				for(q=0; q<col-1; q++){
					if(q<j){
						cof.m[p][q]=m[p+1][q];
					}
					else{
						cof.m[p][q]=m[p+1][q+1];
					}
				}
			}
			det=det+pow(-1, j)*m[0][j]*cof.determinant();//Recursive function call
		}
	}
	
	return det;

}
