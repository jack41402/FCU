#ifndef vector
#define vector

#include "matrix.h"
#include "smatrix.h"

// Vector subclass, representing a column vector.
class Vector: public Matrix { // inherit class Matrix

	public:
		Vector(int=0); // default vector constructor
		Vector(const Matrix&, const int); // copy constructor from a matrix a column index
		Vector(const Vector&); // copy constructor from a vectori 
		void setSize(const int); // set the size of a vector
		SMatrix vector_replace(int, const SMatrix&) const; // Replace a column of a matrix by the vector
};

#endif
