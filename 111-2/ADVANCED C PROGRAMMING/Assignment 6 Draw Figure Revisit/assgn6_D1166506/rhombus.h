#ifndef ASSGN6_D1166506_RHOMBUS_H
#define ASSGN6_D1166506_RHOMBUS_H

#include "draw.h"

class Rhombus: public Draw
{
    private:
        int side ; // Side of figure.

    public:
        Rhombus (const int& =0) ; // Default constructor.
        Rhombus (const Rhombus &) ;
        ~Rhombus() ;
        void drawBoard () ; // Filling the drawing board. Concrete method.
        void printBoard () const ; // Print drawing board. Override printBoard in Draw.
};

#endif //ASSGN6_D1166506_RHOMBUS_H
