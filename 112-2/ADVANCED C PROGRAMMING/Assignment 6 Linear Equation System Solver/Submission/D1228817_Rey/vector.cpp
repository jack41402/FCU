#include<iostream>
#include<cstdlib>
#include"vector.h"//***
using namespace std;

Vector::Vector(int n):Matrix(n, 1){//Construct a Vector object using the Matrix default constructor
}

Vector::Vector(const Matrix& M, const int j){
	int i;
	if(M.getRow()>0&&j>=0&&j<M.getCol()){//Checks if matrix is empty or if index is out of bound
		row=M.getRow();
		col=1;
		allocateMatrix();
		
		for(i=0; i<row; i++){
			m[i][0]=M.getElement(i, j);//Set element for vectro
		}
	}
	
	else{
		row=0;
		col=0;
		m=NULL;
	}
}

Vector::Vector(const Vector& V):Matrix(V){//Construct a vector object using the Matrix copy constructor
}

void Vector::setSize(const int n){//Set the size of Vector using setSize of Matrix
	Matrix::setSize(n, 1);
}

Matrix Vector::vector_replace(int j, const Matrix& M)const{
	int i;
	Matrix cpyM(M);//A copy of Matrix M
	
	//Checks if index is out of bound and if the row of vector matches that of M
	if(j>=0&&j<M.getCol()&&row==M.getRow()){
		for(i=0; i<row; i++){
			cpyM.setElement(i, j, m[i][0]);
		}
	}
	
	else{
		cpyM.setSize(0, 0);
	}
	
	return cpyM;
}
