#include<iostream>
#include<cstdlib>
#include<iomanip>
#include "matrix.h"
using namespace std;

ostream &operator<<(ostream& os, const Matrix& M){
	int i, j;
	for(i=0; i<M.row; i++){
		os<<" ";
		for(j=0; j<M.col; j++){
			os<<fixed<<setw(9)<<setprecision(4)<<M.m[i][j];
		}
		os<<endl;
	}
	return os;
	
}

istream &operator>>(istream& is, Matrix& M){
	int i, j;
	cout << "Input Matrix: " << M.row << " X " << M.col << endl;
	
	for(i=0; i<M.row; i++){
		for(j=0; j<M.col; j++){
			is>>M.m[i][j];
		}
	}
	
	cout<<endl;
	return is;
}

Matrix operator+(const double& d, const Matrix& M){
	int i, j;
	Matrix sum(M.row, M.col);//Initialize Matrix sum
	
	if(M.row>0){
		
		for(i=0; i<M.row; i++){
			for(j=0; j<M.col; j++){
				sum.m[i][j]=d+M.m[i][j];//Set value for each element of sum
			}
		}
	}

	return sum;
}

Matrix operator-(const double& d, const Matrix& M){
	int i, j;
	Matrix diff(M.row, M.col);//Initialize Matrix diff
	
	if(M.row>0){
		
		for(i=0; i<M.row; i++){
			for(j=0; j<M.col; j++){
				diff.m[i][j]=d-M.m[i][j];//Set value for each element of diff
			}
		}
	}

	return diff;
}

Matrix operator*(const double& d, const Matrix& M){
	int i, j;
	Matrix pro(M.row, M.col);//Initialize Matrix pro
	
	if(M.row>0){
		
		for(i=0; i<M.row; i++){
			for(j=0; j<M.col; j++){
				pro.m[i][j]=d*M.m[i][j];//Set value for each element of pro
			}
		}
	}

	return pro;
}

void Matrix::allocateMatrix(){
	int i;
	m=new double*[row];
	for(i=0; i<row; i++){
		m[i]=new double[col];
	}
}

void Matrix::deallocateMatrix(){
	int i;
	for(i=0; i<row; i++){
		delete[] m[i];
	}
	delete[] m;
}

Matrix::Matrix(int r, int c){
	row=r;
	col=c;
	if(row>0&&col>0) allocateMatrix();
	else{
		row=col=0;
		m=NULL;
	} 
}

Matrix::Matrix(const Matrix& M){
	int i, j;
	row=M.row;
	col=M.col;
	
	if(row>0){
		
		allocateMatrix();
	
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				m[i][j]=M.m[i][j];
			}
		}
	}
	else m=NULL; 
	
}

Matrix::~Matrix(){
	if(row>0) deallocateMatrix();
}

void Matrix::setSize(int r, int c){//***
	//Deallocate memory for matrix if it is not the intended size or if Matrix is empty
	if((row!=r||col!=c)&&row!=0) deallocateMatrix();
	row=r;
	col=c;
	if(row>0&&col>0) allocateMatrix();//Alocate memory for matrix if it is not empty
	else{//Set the matrix to its default state if row<=0 or col<=0 
		row=col=0;
		m=NULL;
	} 
}

void Matrix::setElement(int i, int j, double e){
	m[i][j]=e;
}

double Matrix::getElement(int i, int j) const{
	return m[i][j];
}

int Matrix::getRow() const{
	return row;
}

int Matrix::getCol() const{
	return col;
}

Matrix Matrix::operator+(const Matrix& M) const{
	int i, j;
	Matrix sum;
	
	if(row==M.row&&col==M.col&&row>0){//If the two matrix size matches and neither one of them is empty
		sum.setSize(row, col);
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				sum.m[i][j]=m[i][j]+M.m[i][j];
			}
		}
	}
	return sum;
}

Matrix Matrix::operator-(const Matrix& M) const{
	int i, j;
	Matrix diff;
	
	if(row==M.row&&col==M.col&&row>0){//If the two matrix size matches and neither one of them is empty
		diff.setSize(row, col);
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				diff.m[i][j]=m[i][j]-M.m[i][j];
			}
		}
	}
	return diff;
}

Matrix Matrix::operator*(const Matrix& M) const{
	int i, j, k;
	Matrix pro;
	
	//If col of the current matrix is the same as the row of the matrix put within the parameter 
	//and neither one of them is empty
	if(col==M.row&&row>0){
		pro.setSize(row, M.col);
		
		for(i=0; i<row; i++){
			for(j=0; j<M.col; j++){
				pro.m[i][j]=0;
				for(k=0; k<col; k++){
					pro.m[i][j]+=m[i][k]*M.m[k][j];
				}
			}
		}
	}
	
	return pro;
}

Matrix Matrix::operator+(const double& d) const{
	int i, j;
	
	Matrix sum(row, col);//Initialize Matrix sum
	
	if(row>0){
		
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				sum.m[i][j]=m[i][j]+d;//Set value for each element of sum
			}
		}
	}

	return sum;
}

Matrix Matrix::operator-(const double& d) const{
	int i, j;
	
	Matrix diff(row, col);//Initialize Matrix diff
	
	if(row>0){
		
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				diff.m[i][j]=m[i][j]-d;//Set value for each element of diff
			}
		}
	}

	return diff;
}

Matrix Matrix::operator*(const double& d) const{
	int i, j;
	
	Matrix pro(row, col);//Initialize Matrix pro
	
	if(row>0){
		
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				pro.m[i][j]=m[i][j]*d;//Set value for each element of pro
			}
		}
	}

	return pro;
}

bool Matrix::operator==(const Matrix& M) const{
	int i, j;
	
	if(row!=M.row||col!=M.col) return false;//Check if size matches
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			if(m[i][j]!=M.m[i][j]) return false;//Check if element matches
		}
	}
	
	return true;
}

bool Matrix::operator!=(const Matrix& M) const{
	int i, j;
	
	if(row!=M.row||col!=M.col) return true;//Check if size matches
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			if(m[i][j]!=M.m[i][j]) return true;//Check if element matches
		}
	}
	
	return false;
	
}

Matrix& Matrix::operator=(const Matrix& M){
	int i, j;
	
	setSize(M.row, M.col);//Set the size of the matrix
	
	if(row>0){
		for(i=0; i<row; i++){
			for(j=0; j<col; j++){
				m[i][j]=M.m[i][j];//Set elements for the matrix
			}
		}
	}
	
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& M){
	*this=*this+M;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& M){
	*this=*this-M;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& M){
	*this=*this*M;
	return *this;
}

Matrix Matrix::operator-() const{
	int i, j;
	Matrix transp(col, row);
	
	for(i=0; i<col; i++){
		for(j=0; j<row; j++){
			transp.m[i][j]=m[j][i];
		}
	}
	
	return transp;
}
