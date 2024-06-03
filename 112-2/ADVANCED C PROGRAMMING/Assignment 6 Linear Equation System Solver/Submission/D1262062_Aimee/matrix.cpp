#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

ostream &operator<<(ostream &output, const Matrix &M) {
	for (int i=0; i<M.row; i++) {
		output << "  "; 
		for (int j=0; j<M.col; j++) {
		  output << setw(8) << setiosflags(ios::fixed | ios::showpoint);
		  output << setprecision(4) << M.m[i][j] << " ";
		}
		output << endl;
	}
	output << endl; 
	return output;
	
}
istream &operator>>(istream& input, Matrix& M) {
	cout << "Input Matrix: " << M.row << " X " << M.col << endl;
	for (int i=0; i<M.row; i++)
	  for (int j=0; j<M.col; j++)
	    input >> M.m[i][j];
	cout << endl;
	return input;
}

Matrix operator+(const double &n, const Matrix &M) {
	Matrix sum;
	if(M.getRow() > 0 && M.getCol() > 0){
		sum.setSize(M.getRow(), M.getCol());
		for(int i=0; i<M.getRow(); i++) {
			for(int j=0; j<M.getCol(); j++)
				 sum.m[i][j] = n + M.getElement(i,j);
		}
	}
	else {
    cout << "Scalar-matrix addition: The matrix is empty." << endl;
    sum.row = 0;
    sum.col = 0;
    sum.m = NULL;
  	}
	return sum;
}
Matrix operator-(const double &n, const Matrix &M) {
	Matrix diff;
	if(M.getRow() > 0 && M.getCol() > 0){
		diff.setSize(M.getRow(), M.getCol());
		for(int i=0; i<M.getRow(); i++) {
			for(int j=0; j<M.getCol(); j++)
				 diff.m[i][j] = n - M.getElement(i,j);
		}
	}
	else {
    cout << "Scalar-matrix subtraction: The matrix is empty." << endl;
    diff.row = 0;
    diff.col = 0;
    diff.m = NULL;
	}
	return diff;
}
Matrix operator*(const double &n, const Matrix &M) {
	Matrix prod;
	if(M.getRow() > 0 && M.getCol() > 0){
		prod.setSize(M.getRow(), M.getCol());
		for(int i=0; i<M.getRow(); i++) {
			for(int j=0; j<M.getCol(); j++)
				 prod.m[i][j] = n * M.getElement(i,j);
		}
	}
	else {
    cout << "Scalar-matrix multiplication: The matrix is empty." << endl;
    prod.row = 0;
    prod.col = 0;
    prod.m = NULL;
	}
	return prod;
}

void Matrix::allocateMatrix() {
	m = new double* [row];
	for(int i=0; i<row; i++) m[i] = new double [col];
}

void Matrix::deallocateMatrix() {
	if(row>0 && col>0){
	for(int i=0; i<row; i++) delete [] m[i];
  	delete [] m;
  	m=NULL;
	}
}

Matrix::Matrix(int r, int c) {
	if(r > 0 && c > 0){
		row = r;
		col = c;
		allocateMatrix();
	}
	else{
		row = 0;
		col = 0;
		m = NULL;
	}
}

Matrix::Matrix(const Matrix& M) {
	if(M.row > 0 && M.col > 0) {
		row = M.row;
		col = M.col;
		allocateMatrix();
		for(int r=0; r<row; r++) {
      		for(int c=0; c<col; c++)
        		m[r][c] = M.getElement(r, c);
    	}
	}
	else {
    	row = 0;
    	col = 0;
    	m = NULL;
	}	
}

Matrix::~Matrix() {
	if(row > 0 && col > 0) deallocateMatrix();
}

void Matrix::setSize(int r, int c) {
	if(m != NULL) deallocateMatrix();
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

void Matrix::setElement(int r, int c, double elem) {
	if(row > 0 && col > 0) {
		if(r >= 0 && r < row && c >= 0 && c < col) m[r][c] = elem;
		else cout << "Illegal matrix index [" << r << "," << c << "]." << endl; 
	}
	else cout << "The matrix is empty." << endl << endl;
}

double Matrix::getElement(int r, int c) const {
	double elem = 0.0;
	if(row > 0 && col > 0) {
		if(r >= 0 && r < row && c >= 0 && c < col) elem = m[r][c];
		else cout << "Illegal matrix index [" << r << "," << c << "]." << endl; 
	}
	else cout << "The matrix is empty." << endl << endl;
	return elem;
}

int Matrix::getRow() const {
	return row;
}

int Matrix::getCol() const {
	return col;
}

Matrix Matrix::operator+(const Matrix &M) const {
	Matrix sum;
	if(row == M.row && col == M.col){
		if(row > 0 && col > 0){
			sum.setSize(row, col);
			for(int r=0; r<row; r++)
				for(int c=0; c<col; c++)
					sum.m[r][c] = m[r][c] + M.m[r][c];
		}
		else{
			cout << "Matrix-matrix addition: One of the matrices is empty." << endl;
			sum.row = 0;
			sum.col = 0;
			sum.m = NULL;
		}
	}
	else{
		cout << "Matrix-matrix addition: The matrix operand sizes do not match." << endl;
	    sum.row = 0;
	    sum.col = 0;
	    sum.m = NULL;
	}
	return sum;
} 

Matrix Matrix::operator-(const Matrix &M) const {
	Matrix diff;
	if(row == M.row && col == M.col){
		if(row > 0 && col > 0){
			diff.setSize(row, col);
			for(int r=0; r<row; r++)
				for(int c=0; c<col; c++)
					diff.m[r][c] = m[r][c] - M.m[r][c];
		}
		else{
			cout << "Matrix-matrix substraction: One of the matrices is empty." << endl;
			diff.row = 0;
			diff.col = 0;
			diff.m = NULL;
		}
	}
	else{
		cout << "Matrix-matrix substraction: The matrix operand sizes do not match." << endl;
	    diff.row = 0;
	    diff.col = 0;
	    diff.m = NULL;
	}
	return diff;
}

Matrix Matrix::operator*(const Matrix &M) const {
	Matrix prod;
	if(col == M.row){
		if(row > 0 && col > 0 && M.col > 0){
			prod.setSize(row, M.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<M.col; j++){
					prod.m[i][j] = 0;
					for(int k=0; k<col; k++) 
						prod.m[i][j] += m[i][k] * M.m[k][j];
				}
			}	
		}
		else {
			cout << "Matrix-matrix multiplication: One of the matrices is empty." << endl;      
		    prod.row = 0;
		    prod.col = 0;
		    prod.m = NULL;
	    }
	}
	else {
	    cout << "Matrix-matrix multiplication: The matrix operand sizes do not match." << endl;    
	    prod.row = 0;
	    prod.col = 0;
	    prod.m = NULL;
	}
	return prod;
}

Matrix Matrix::operator+(const double &n) const {
	Matrix sum;
	if(row > 0 && col > 0){
		sum.setSize(row, col);
		for(int r=0; r<row; r++)
			for(int c=0; c<col; c++)
				sum.m[r][c] = m[r][c] + n;
	}
	else{
		cout << "Matrix-scalar addition: The matrix is empty." << endl;
	    sum.row = 0;
	    sum.col = 0;
	    sum.m = NULL;
	}
	return sum;
}

Matrix Matrix::operator-(const double &n) const {
	Matrix diff;
	if(row > 0 && col > 0){
		diff.setSize(row, col);
		for(int r=0; r<row; r++)
			for(int c=0; c<col; c++)
				diff.m[r][c] = m[r][c] - n;
	}
	else{
		cout << "Matrix-scalar substraction: The matrix is empty." << endl;
	    diff.row = 0;
	    diff.col = 0;
	    diff.m = NULL;
	}
	return diff;
}

Matrix Matrix::operator*(const double &n) const {
	Matrix prod;
	if(row > 0 && col > 0){
		prod.setSize(row, col);
		for(int r=0; r<row; r++)
			for(int c=0; c<col; c++)
				prod.m[r][c] = m[r][c] * n;
	}
	else{
		cout << "Matrix-scalar multiplication: The matrix is empty." << endl;
	    prod.row = 0;
	    prod.col = 0;
	    prod.m = NULL;
	}
	return prod;
}

bool Matrix::operator==(const Matrix &M) const {
	if(row == M.row && col == M.col){
		if(row > 0 && col > 0){
			for(int r=0; r<row; r++)
				for(int c=0; c<col; c++)
					if (m[r][c] != M.m[r][c]) return false;
			return true;
		}
		else cout << "Matrix relation: One of the matrices is empty." << endl;
	}
	else cout << "Matrix relation: The operand matrix sizes do not match." << endl;
  	return false;
}

bool Matrix::operator!=(const Matrix &M) const {
	return !(*this == M);
}

Matrix & Matrix::operator=(const Matrix &M) {
	if(row > 0 && col > 0) deallocateMatrix();
	row = M.row;
	col = M.col;
	if (row>0 && col>0 ) {
    allocateMatrix();
    for (int r=0; r<row; r++)
      for (int c=0; c<col; c++) 
        m[r][c] = M.getElement(r, c);
	}
	else m = NULL; 
	return *this;
}

Matrix & Matrix::operator+=(const Matrix &M) {
	*this = *this + M;
	return *this;
} 

Matrix & Matrix::operator-=(const Matrix &M) {
	*this = *this - M;
	return *this;
}

Matrix & Matrix::operator*=(const Matrix &M) {
	*this = *this * M;
	return *this;
}

Matrix Matrix::operator-() const {
	Matrix M(row, col);
	for(int r=0; r<row; r++)
		for(int c=0; c<col; c++)
			M.m[r][c] = m[r][c];	
	return M;
}
