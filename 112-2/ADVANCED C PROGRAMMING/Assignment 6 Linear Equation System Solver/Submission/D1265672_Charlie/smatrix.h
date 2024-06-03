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

#endif

