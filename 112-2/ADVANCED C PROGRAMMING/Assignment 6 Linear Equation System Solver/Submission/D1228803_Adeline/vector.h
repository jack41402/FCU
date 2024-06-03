//vector.h

#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"
#include <stdexcept> // Include for invalid_argument

// Vector subclass, representing a column vector.
class Vector : public Matrix 
{
 	public:
     	Vector(int = 0); // default vector constructor
     	Vector(const Matrix &, int); // copy constructor from a matrix and a column index
     	Vector(const Vector &); // copy constructor from a vector
     	explicit Vector(const Matrix &); // constructor from a Matrix with one column
     	void setSize(int); // set the size of a vector
     	Matrix vector_replace(int, const Matrix &) const; // Replace a column of a matrix by the vector
 
     	Vector operator-(const Vector&) const; // Vector-Matrix operations
};

#endif // VECTOR_H
