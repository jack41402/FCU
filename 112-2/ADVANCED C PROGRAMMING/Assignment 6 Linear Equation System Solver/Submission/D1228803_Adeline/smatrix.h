//smatrix.h

#ifndef SMATRIX_H
#define SMATRIX_H

#include "matrix.h"
#include <stdexcept> // Include for std::invalid_argument

// Square matrix subclass.
class SMatrix: public Matrix 
{
 	public:
      	SMatrix(int = 0); // default square matrix constructor
      	SMatrix(const Matrix &); // copy constructor from a matrix
      	SMatrix(const SMatrix &); // copy constructor from a square matrix
      	void setSize(int); // set the size of a square matrix
      	double determinant() const; // determinant function
};

#endif // SMATRIX_H
