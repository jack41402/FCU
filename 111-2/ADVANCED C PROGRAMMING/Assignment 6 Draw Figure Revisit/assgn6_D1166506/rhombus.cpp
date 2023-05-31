#include <iostream>
#include <cstring>
#include "rhombus.h"

Rhombus::Rhombus (const int& value): Draw("Rhombus" , 2*value-1 , 2*value-1) , side(value)
{

}

Rhombus::Rhombus (const Rhombus &rhombus): Draw(rhombus.name , rhombus.width , rhombus.height) , side(rhombus.side)
{

}

Rhombus::~Rhombus ()
{

}

void Rhombus::drawBoard ()
{
    for (int i=0 ; i<height/2+1 ; ++i)
    {
        for (int j=0 ; j<side-i-1 ; ++j)
        {
            board[i][j] = ' ' ;
        }
        for (int j=0 ; j<2*i+1 ; ++j)
        {
            if (j==0 || j==2*i) board[i][side-i+j-1] = '*' ;
            else board[i][side-i+j-1] = '@' ;
        }
    }
    for (int i=0 ; i<height/2 ; ++i)
    {
        for (int j=0 ; j<i+1 ; ++j)
        {
            board[height/2+i+1][j] = ' ' ;
        }
        for (int j=0 ; j<2*(height/2-i)-1 ; ++j)
        {
            if (j==0 || j==2*(height/2-i)-2) board[height/2+i+1][i+j+1] = '*' ;
            else board[height/2+i+1][i+j+1] = '@' ;
        }
    }
}

void Rhombus::info () const
{
    std::cout << "\n**** Figure: " << name
              << ", Side: " << side
              << ", Board: " << height << 'X' << width << "\n\n" ;
}

void Rhombus::printBoard () const
{

    for (int i=0 ; i<height ; ++i)
    {
        std::cout << "    " << board[i] << '\n' ;
    }
    std::cout << '\n' ;
}
