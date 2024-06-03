#include "vector.h"

Vector::Vector(int n){
    this->row = n;
    this->col = 1;
    allocateMatrix();
}

Vector::Vector(const Matrix& M, const int j){
    this->row = M.getRow();
    this->col = 1;
    allocateMatrix();
    for(int i = 0; i < row; i++){
        this->m[i][0] = M.getElement(i, j);
    }
}

Vector::Vector(const Vector& v){
    this->row = v.row;
    this->col = v.col;
    allocateMatrix();
    for(int i = 0; i < row; i++){
      this->m[i][0] = v.m[i][0];
    }
}

void Vector::setSize(const int r){
    deallocateMatrix();
    this->row = r;
    this->col = 1;
    allocateMatrix();
}

Matrix Vector::vector_replace(int j, const Matrix& M){
    Matrix mat(M);
    for(int i = 0; i < M.getRow(); i++){
        mat.setElement(i, j, this->m[i][0]);
    }
    return mat;
}
