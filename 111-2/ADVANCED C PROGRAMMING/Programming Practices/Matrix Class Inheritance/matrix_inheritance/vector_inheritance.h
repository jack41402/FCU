#ifndef vector
#define vector

#include "matrix_inheritance.h"

// Vector subclass, representing a column vector.
class Vector: public Matrix { // inherit class Matrix

  public:
    Vector(int=0); // default vector constructor
    Vector(const Matrix&); // copy constructor from a column matrix
    Vector(const Vector&); // copy constructor from a vector
    void setSize(const int); // set the size of a vector
    double operator*(const Vector &) const; // use '*' for inner product operation
};

#endif
