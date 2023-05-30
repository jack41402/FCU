#ifndef ASSGN6_D1166506_SQUARE_H
#define ASSGN6_D1166506_SQUARE_H

#include "draw.h"

class Square: public Draw
{
    private:
        int side ; // Side of figure.

    public:
        Square (const int& =0) ; // Default constructor.
        Square (const Square &) ;
        ~Square() ;
        void drawBoard () ; // Filling the drawing board. Concrete method.
        void printBoard () const ; // Print drawing board. Override printBoard in Draw.
};

#endif //ASSGN6_D1166506_SQUARE_H
