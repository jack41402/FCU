#include<iostream>
#include"vector.h"

using std::cout;
using std::cin;
using std::ios;
//Vector constructor with size definition
Vector::Vector(int a){
	if (a>0){
		row = a;
		col = 1;
		allocateMatrix();
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//Copy constructor from a matrix and a column index
Vector::Vector(const Matrix& n, const int a){
	int i;
	if (i<=0 && i<n.getCol()){
		row = n.getRow();
		col = 1;
		allocateMatrix();
		for (i = 0; i<row; i++){
			m[i][0] = n.getElement(i, a);
		}
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//Vector copy constructor
Vector::Vector(const Vector& c){
	int i;
	if (c.row>0 && c.col>0){
		row = c.row;
		col = c.col;
		allocateMatrix();
		for (i = 0; i<row; i++){
			m[i][0] = c.m[i][0];
		} 
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//Redefine vector size
void Vector::setSize(const int a){
	if (a>0){
		if (m!=NULL){
			deallocateMatrix();
		}
		row = a;
		col = 1;
		allocateMatrix();
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//vector replacement function
Matrix Vector::vector_replace(int a,const Matrix& n){
	int i, j, k = 0;
	Matrix b(n.getRow(), n.getCol());
	if (a>=0 && a<n.getCol()){
		while (a!=k){
			k++;
		}
		for (i = 0; i<n.getRow(); i++){
			for (j = 0; j<n.getCol(); j++){
				b.setElement(i, j, n.getElement(i, j));
			}
		}
		for (i = 0; i<n.getRow(); i++){
			b.setElement(i, k, m[i][0]);
		}
	}
	return b;
}

