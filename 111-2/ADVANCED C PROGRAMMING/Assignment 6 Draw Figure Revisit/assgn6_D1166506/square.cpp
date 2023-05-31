#include <iostream>
#include <cstring>
#include "square.h"

Square::Square (const int& value): Draw("Square" , value , value) , side(value)
{

}

Square::Square (const Square &square): Draw(square.name , square.width , square.height) , side(square.side)
{

}

Square::~Square ()
{

}

void Square::drawBoard ()
{
    for (int i=0 ; i<height ; ++i)
    {
        for (int j=0 ; j<width ; ++j)
        {
            if (i==0 || j==0 || i==height-1 || j==width-1) board[i][j] = '*' ;
            else board[i][j] = '@' ;
        }
    }
}

void Square::info () const
{
    std::cout << "\n**** Figure: " << name
              << ", Side: " << side
              << ", Board: " << height << 'X' << width << "\n\n" ;
}

void Square::printBoard () const
{
    for (int i=0 ; i<height ; ++i)
    {
        std::cout << "    " << board[i] << '\n' ;
    }
    std::cout << '\n' ;
}
