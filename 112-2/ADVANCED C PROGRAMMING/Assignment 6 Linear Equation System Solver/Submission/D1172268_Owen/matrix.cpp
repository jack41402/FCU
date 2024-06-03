#include "matrix.h"
#include <iomanip>

ostream &operator<<(ostream& os, const Matrix& M){
	for(int i = 0; i < M.row; i++){
		cout << "    ";
		for(int j = 0; j < M.col; j++){
			os << fixed <<setprecision(4) << M.m[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
    return os;
}

istream &operator>>(istream& is, Matrix& M) {
	cout << "Input Matrix: " << M.row << " x " << M.col << endl;
    for(int i = 0; i < M.row; i++){
        for(int j = 0; j < M.col; j++){
            is >> M.m[i][j];
        }
    }
	cout << endl;
	return is;
}

Matrix operator+(const double& d, const Matrix& M){
    Matrix mat(M.row, M.col);
	for(int i = 0; i < M.row; i++){
		for(int j = 0; j < M.col; j++){
			mat.m[i][j] = M.m[i][j] + d ;
		}
	}
	return mat;
}

Matrix operator-(const double& d, const Matrix& M){
    Matrix mat(M.row, M.col);
	for(int i = 0; i < M.row; i++){
		for(int j = 0; j < M.col; j++){
			mat.m[i][j] = d - M.m[i][j];
		}
	}
	return mat;
}

Matrix operator*(const double& d, const Matrix& M){
    Matrix mat(M.row, M.col);
	for(int i = 0; i < M.row; i++){
		for(int j = 0; j < M.col; j++){
			mat.m[i][j] = d * M.m[i][j];
		}
	}
	return mat;
}

void Matrix::allocateMatrix(){
	this->m = new double*[this->row];
	for(int i = 0; i < this->row; i++){
		this->m[i] = new double[this->col];
	}
}

void Matrix::deallocateMatrix(){
	for(int i = 0; i < this->row; i++){
		delete[] this->m[i];
	}
	delete[] this->m;
}

Matrix::Matrix(int r, int l){
	this->row = r;
	this->col = l;
	this->allocateMatrix();
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			this->m[i][j] = 0;	
		}
	}
}

Matrix::Matrix(const Matrix& M){
	this->row = M.row;
	this->col = M.col;
	this->allocateMatrix();
	for(int i = 0; i < M.row; i++){
		for(int j = 0; j < M.col; j++){
			this->m[i][j] = M.m[i][j];	
		}
	}
}

Matrix::~Matrix(){
	this->deallocateMatrix();
}

void Matrix::setSize(int r, int c){
	this->deallocateMatrix();
	this->row = r;
	this->col = c;
	this->allocateMatrix();
}
		
void Matrix::setElement(int r, int c, double elem){
	this->m[r][c] = elem;
}

double Matrix::getElement(int r, int c) const{
	return this->m[r][c];
}

int Matrix::getRow() const{
	return this->row;
}

int Matrix::getCol() const{
	return this->col;
}

Matrix Matrix::operator+(const Matrix& M) const{
	Matrix mat(this->row, this->col);
	for(int i = 0; i < M.row; i++){
		for(int j = 0; j < M.col; j++){
			mat.m[i][j] = this->m[i][j] + M.m[i][j];
		}
	}
	return mat;
}

Matrix Matrix::operator-(const Matrix& M) const{
	Matrix mat(this->row, this->col);
	for(int i = 0; i < M.row; i++){
		for(int j = 0; j < M.col; j++){
			mat = m[i][j] = this->m[i][j] - M.m[i][j];
		}
	}
	return mat;
}

Matrix Matrix::operator*(const Matrix& M) const{
	Matrix mat(this->row, M.col);
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < M.col; j++){
			for(int k = 0; k < this->col; k++){
				mat.m[i][j] += this->m[i][k] * M.m[k][j];
			} 
		}
	}
	return mat;
}

Matrix Matrix::operator+(const double& d) const{
	Matrix mat(this->row, this->col);
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			mat.m[i][j] = this->m[i][j] + d;
		}
	}
	return mat;
}

Matrix Matrix::operator-(const double& d) const{
	Matrix mat(this->row, this->col);
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			mat = m[i][j] = this->m[i][j] - d;
		}
	}
	return mat;
}

Matrix Matrix::operator*(const double& d) const{
	Matrix mat(this->row, this->col);
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){
			mat = m[i][j] = this->m[i][j] * d;
		}
	}
	return mat;
}

bool Matrix::operator==(const Matrix& M) const{
	if(this->row != M.row || this->col != M.col) return false;
	else for(int i = 0; i < M.row; i++){
			for(int j = 0; j < M.col; j++){
				if(this->m[i][j] != M.m[i][j]) return false;
		}
	}
	return true;
} 

bool Matrix::operator!=(const Matrix& M) const{
	if(this->row != M.row || this->col != M.col) return true;
	else for(int i = 0; i < M.row; i++){
			for(int j = 0; j < M.col; j++){
				if(this->m[i][j] != M.m[i][j]) return true;
		}
	}
	return false;
}

Matrix& Matrix::operator=(const Matrix& M){
	this->row = M.row;
	this->col = M.col;
	for(int i = 0; i < M.row; i++){
		for(int j = 0; j < M.col; j++){
			this->m[i][j] = M.m[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& M){
	if(this->row == M.row && this->col == M.col){
		for(int i = 0; i < M.row; i++){
			for(int j = 0; j < M.col; j++){
				this->m[i][j] += M.m[i][j];
			}
		}
	} 
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& M){
	if(this->row == M.row && this->col == M.col){
		for(int i = 0; i < M.row; i++){
			for(int j = 0; j < M.col; j++){
				this->m[i][j] -= M.m[i][j];
			}
		}
	} 
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& M){
	Matrix n(this->row, M.col);
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < M.col; j++){
			for(int k = 0; k < this->col; k++){
				n.m[i][j] += this->m[i][k] * M.m[k][j];
			} 
		}
	}
	*this = n;
	return *this;	
}

Matrix Matrix::operator-() const{
	Matrix mat(this->row, this->col);
	for(int i = 0; i < this->row; i++){
		for(int j = 0; j < this->col; j++){ 
			mat.m[i][j] = -this->m[i][j];
		}
	}
	return mat; 
}
