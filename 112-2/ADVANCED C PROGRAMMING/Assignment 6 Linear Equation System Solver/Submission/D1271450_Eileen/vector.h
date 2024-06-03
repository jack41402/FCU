#ifndef vector
#define vector

#include "matrix.h"
// Vector subclass, representing a column vector.
class Vector: public Matrix { // inherit class Matrix

	public:
		Vector(int=0); // default vector constructor
		Vector(const Matrix&, const int); // copy constructor from a matrix a column index
		Vector(const Vector&); // copy constructor from a vectori 
		void setSize(const int); // set the size of a vector
		Matrix vector_replace(int, const Matrix&); // Replace a column of a matrix by the vector
};

#endif
