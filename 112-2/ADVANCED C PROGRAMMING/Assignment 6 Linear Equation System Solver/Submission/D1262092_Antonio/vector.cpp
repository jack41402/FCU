#include <iostream>

using std::cout; 
using std::endl; 
using std::cin; 
using std::ios;

#include "vector.h"

// Vector constructor with size definition.
Vector::Vector(int n) {
  if (n>0) {
    row = n;
    col = 1;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Copy constructor from a matrix and a column index
Vector::Vector(const Matrix &n, const int j) {
  int i;
  if (i<=0 && i<n.getCol()) {
    row = n.getRow();
    col = 1;
    allocateMatrix();
    for (i=0; i<row; i++) m[i][0] = n.getElement(i, j);
  }
  else {
    std::cout << "The column index is out of range." << endl << endl;
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Vector copy constructor
Vector::Vector(const Vector &v) {
  int i;
  
  if (v.row>0 && v.col==1) {
    row = v.row;
    col = v.col;
    allocateMatrix();
    for (i=0; i<row; i++) {
      m[i][0] = v.m[i][0];
    }
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// Redefine vector size.
void Vector::setSize(int r) {
  if (r>0) {
    if (m != NULL) deallocateMatrix();
    row = r;
    col = 1;
    allocateMatrix();
  }
  else {
    row = 0;
    col = 0;
    m = NULL;
  }
}

// vector replacement
Matrix Vector::vector_replace(int r, const Matrix &n){
	int i, j;
	int k = 0;
	Matrix a(n.getRow(), n.getCol());
	if(r<n.getCol() && r>=0){
		while(k!=r){
			k++;
		}
		for(i=0; i<n.getRow(); i++){
			for(j=0; j<n.getCol(); j++){
				a.setElement(i, j, n.getElement(i, j));
			}	
		}
		for(i=0; i<n.getRow(); i++){
			a.setElement(i, k, m[i][0]);
		}
	}
	else{
		cout << "Wrong matrix input";
	}
	return a;
}
