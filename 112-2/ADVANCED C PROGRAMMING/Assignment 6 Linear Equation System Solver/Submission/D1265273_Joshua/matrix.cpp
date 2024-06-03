#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl; 
using std::cin; 
using std::ios;

#include "matrix.h"
#include "smatrix.h"
#include "vector.h"
//output function
ostream &operator<<(ostream& output, const Matrix& M){
	int i, j;
	for (i = 0; i<M.row; i++){
            output<<"  ";
		for (j = 0;j<M.col; j++){
			output << setw(8) << setiosflags(ios::fixed | ios::showpoint);
			output<<setprecision(4)<<M.m[i][j]<<" ";
		}
		output<<"\n";
	}
	return output;
} 
//input funnction
istream &operator>>(istream& input, Matrix& M){
	int i, j;
	for (i = 0; i<M.row; i++){
		for (j = 0; j<M.col; j++){
			input>>M.m[i][j];
		}
	}
	return input;
}
//request memory space
void Matrix::allocateMatrix(){
	m = new double* [row];
	for (int i = 0; i<row; i++) m[i] = new double [col];
}
//release memory space
void Matrix::deallocateMatrix(){
	for (int i = 0; i<row; i++) delete [] m[i];
	delete [] m;
}
//define matrix
Matrix::Matrix(int a, int b) {
	if (a>0 && b>0){
		row = a;
		col = b;
		allocateMatrix();
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//matrix copy constructor
Matrix::Matrix(const Matrix& n){
	int i, j;
	if (n.row>0 && n.col>0){
		row = n.row;
		col = n.col;
		for (i = 0; i<row; i++){
			for (j = 0; j<col; j++){
				m[i][j] = n.getElement(i, j);
			}
		}
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//matrix destructor
Matrix::~Matrix(){
	if (row>0 && col>0){
		deallocateMatrix();
	}
}
//define matrix size
void Matrix::setSize(int a, int b){
	if (row>0 && col>0){
		deallocateMatrix();
	}
	if (a>0 && b>0){
		row = a;
		col = b;
		allocateMatrix();
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}
//define matrix element
void Matrix::setElement(int a, int b, double elem){
	if (row>0 && col>0){
		if (a>=0 && a<row && b>=0 && b<col){
			m[a][b] = elem;
		}
	}
}
//get a matrix element
double Matrix::getElement(int a, int b)const{
	double elem = 0;
	if (row>0 && col>0){
		if (a>=0 && a<row && b>=0 && b<col){
			elem = m[a][b];
		}
	}
	return elem;
}
//get the row value
int Matrix::getRow()const{
	return row;
}
//get the colume value
int Matrix::getCol()const{
	return col;
}
//scalar-matrix addition
Matrix operator+(const double& s, const Matrix& n){
	Matrix sum;
	int i, j;
	if (n.getRow()>0 && n.getCol()>0){
		sum.setSize(n.getRow(), n.getCol());
		for (i = 0; i<n.getRow(); i++){
			for (j = 0; j<n.getCol(); j++){
				sum.m[i][j] = s + n.getElement(i, j);
			}
		}
	}
	else{
		sum.row = 0;
		sum.col = 0;
		sum.m = NULL;
	}
	return sum;
}
//scalar-matrix subtraction
Matrix operator-(const double& s, const Matrix& n){
	Matrix diff;
	int i, j;
	if (n.getRow()>0 && n.getCol()>0){
		diff.setSize(n.getRow(), n.getCol());
		for (i = 0; i<n.getRow(); i++){
			for (j = 0; j<n.getCol(); j++){
				diff.m[i][j] = s-n.getElement(i, j);
			}
		}
	}
	else{
		diff.row = 0;
		diff.col = 0;
		diff.m = NULL;
	}
	return diff;
}
//scalar-matrix multiplication
Matrix operator*(const double& s, const Matrix& n){
	Matrix product;
	int i, j;
	if (n.getRow()>0 && n.getCol()>0){
		product.setSize(n.getRow(), n.getCol());
		for (i = 0; i<n.getRow(); i++){
			for (j = 0; j<n.getCol(); j++){
				product.m[i][j] = s*n.getElement(i, j);
			}
		}
	}
	else{
		product.row = 0;
		product.col = 0;
		product.m = NULL;
	}
	return product;
}
//Matrix-matrix addition
Matrix Matrix::operator+(const Matrix& n)const{
	Matrix sum;
	int i, j;
	if (row==n.row && col==n.col){
		if (row>0 && col>0){
			sum.setSize(n.row, n.col);
			for (i = 0; i<n.row; i++){
				for (j = 0; j<n.col; j++){
					sum.m[i][j] = m[i][j] + n.m[i][j];
				}
			}
		}
		else{
			sum.row = 0;
			sum.col = 0;
			sum.m = NULL;
		}
	}
	else{
		sum.row = 0;
		sum.col = 0;
		sum.m = NULL;
	}
	return sum;
}
//Matrix-matrix substraction
Matrix Matrix::operator-(const Matrix& n)const{
	Matrix diff;
	int i, j;
	if (row==n.row && col==n.col){
		if (row>0 && col>0){
			diff.setSize(n.row, n.col);
			for (i = 0; i<n.row; i++){
				for (j = 0; j<n.col; j++){
					diff.m[i][j] = m[i][j] - n.m[i][j];
				}
			}
		}
		else{
			diff.row = 0;
			diff.col = 0;
			diff.m = NULL;
		}
	}
	else{
		diff.row = 0;
		diff.col = 0;
		diff.m = NULL;
	}
	return diff;
}
//Matrix-matrix multiplication
Matrix Matrix::operator*(const Matrix& n)const{
	Matrix product;
	int i, j, k;
	if (col==n.row){
		if (row>0 && col>0 && n.col>0){
			product.setSize(row, n.col);
			for (i = 0; i<row; i++){
				for (j = 0; j<n.col; j++){
					product.m[i][j] = 0;
					for (k = 0; k<col; k++){
						product.m[i][j] += m[i][k]*n.m[k][j];
					}
				}
			}
		}
		else{
			product.row = 0;
			product.col = 0;
			product.m = NULL;
		}
	}
	else{
		product.row = 0;
		product.col = 0;
		product.m = NULL;
	}
	return product;
}
//Matrix-scalar addition
Matrix Matrix::operator+(const double& s)const{
	Matrix sum;
	int i, j;
	if(row>0 && col>0){
		sum.setSize(row, col);
		for (i = 0; i<row; i++){
			for (j = 0; j<col; j++){
				sum.m[i][j] = m[i][j] + s;
			}
		}
	}
	else{
		sum.row = 0;
		sum.col = 0;
		sum.m = NULL;
	}
	return sum;
}
//Matrix-scalar substraction
Matrix Matrix::operator-(const double& s)const{
	Matrix diff;
	int i, j;
	if (row>0 && col>0){
		diff.setSize(row, col);
		for (i = 0; i<row; i++){
			for (j = 0; j<col; j++){
				diff.m[i][j] = m[i][j] - s;
			}
		}
	}
	else{
		diff.row = 0;
		diff.col = 0;
		diff.m = NULL;
	}
	return diff;
}
//Matrix-scalar multiplication
Matrix Matrix::operator*(const double& s)const{
	Matrix product;
	int i, j;
	if (row>0 && col>0){
		for (i = 0; i<row; i++){
			for (j = 0; j<col; j++){
				product.m[i][j] = m[i][j] * s;
			}
		}
	}
	else{
		product.row = 0;
		product.col = 0;
		product.m = NULL;
	}
	return product;
}
//Equal to relation for matrices
bool Matrix::operator==(const Matrix& n)const{
	if (row==n.row && col==n.col){
		if (row>0 && col>0){
            int i, j;
			for (i = 0; i<n.row; i++){
				for (j = 0; j<n.col; j++){
					if (m[i][j]!= n.m[i][j]){
						return false;
					}
				}
			}
			return true;
		}
	}
	return false;
}
//Not equal to relation for matrices
bool Matrix::operator!=(const Matrix& n)const{
	return !(*this==n);
}
//Matrix assignment
Matrix & Matrix::operator=(const Matrix& n){
	int i, j;
	if (row>0 && col>0){
		deallocateMatrix();
	}
	row = n.row;
	col = n.col;
	if (row>0 && col>0 ){
		allocateMatrix();
		for (i = 0; i<n.row; i++){
			for (j = 0; j<n.col; j++){
				m[i][j] = n.getElement(i, j);
			}
		}
	}
	else{
		m = NULL;
	}
	return *this;
}
//Matrix assignment with addition
Matrix & Matrix::operator+=(const Matrix& n){
	*this = *this + n;
	return *this;
}
//Matrix assignment with substraction
Matrix & Matrix::operator-=(const Matrix& n){
	*this = *this - n;
	return *this;
}
//Matrix assignment with multiplication
Matrix & Matrix::operator*=(const Matrix& n){
	*this = *this * n;
	return *this;
}
//Interpret unary operation as matrix transposition
Matrix Matrix::operator-()const{
	Matrix T(col, row);
	int i, j;
	for (i = 0; i<row; i++){
		for (j = 0; j<col; j++){
			T.m[j][i] = m[i][j];
		}
	} 
	return T;
}
