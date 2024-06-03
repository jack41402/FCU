//
//  smatrix.h
//  Assignment6_D1265065
//
//  Created by Corrine  on 2024/5/20.
//

#ifndef smatrix
#define smatrix

#include "matrix.h"

// Square matrix subclass.
class SMatrix: public Matrix {
    
    public:
        SMatrix(int=0); // default square matrix constructor
        SMatrix(const Matrix&); // copy constructor from a matrix
        SMatrix(const SMatrix&); // copy constructor from a square matrix
        void setSize(const int); // set the size of a square matrix
        double determinant() const; // determinant function
};

#endif /* smatrix_h */
