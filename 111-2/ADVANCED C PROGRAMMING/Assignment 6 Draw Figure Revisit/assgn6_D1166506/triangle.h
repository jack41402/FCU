#ifndef ASSGN6_D1166506_TRIANGLE_H
#define ASSGN6_D1166506_TRIANGLE_H

#include "draw.h"

class Triangle: public Draw
{
    private:
        int side ; // Side of figure.

    public:
        Triangle (const int& =0) ; // Default constructor.
        Triangle (const Triangle &) ;
        ~Triangle() ;
        void drawBoard () ; // Filling the drawing board. Concrete method.
        void printBoard () const ; // Print drawing board. Override printBoard in Draw.
};

#endif //ASSGN6_D1166506_TRIANGLE_H
