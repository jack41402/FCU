#include <iostream>
#include <cstring>
#include "triangle.h"

Triangle::Triangle (const int& value): Draw("Triangle" , 2*value-1 , value) , side(value)
{

}

Triangle::Triangle (const Triangle &triangle): Draw(triangle.name , triangle.width , triangle.height) , side(triangle.side)
{

}

Triangle::~Triangle ()
{

}

void Triangle::drawBoard ()
{
    for (int i=0 ; i<height ; ++i)
    {
        for (int j=0 ; j<side-i-1 ; ++j)
        {
            board[i][j] = ' ' ;
        }
        for (int j=0 ; j<2*i+1 ; ++j)
        {
            if (i==height-1 || j==0 || j==2*i) board[i][side-i+j-1] = '*' ;
            else board[i][side-i+j-1] = '@' ;
        }
    }
}

void Triangle::info () const
{
    std::cout << "\n**** Figure: " << name
              << ", Side: " << side
              << ", Board: " << height << 'X' << width << "\n\n" ;
}

void Triangle::printBoard () const
{
    for (int i=0 ; i<height ; ++i)
    {
        std::cout << "    " << board[i] << '\n' ;
    }
    std::cout << '\n' ;
}
