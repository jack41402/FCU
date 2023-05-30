#include <iostream>
#include <cstring>
#include "rhombus.h"

Rhombus::Rhombus (const int& value): side(value)
{
    name = new char[10]() ;
    strcpy(name , "Rhombus") ;
    width = 2 * side - 1 ;
    height = 2 * side - 1 ;
    board = new char*[height]() ;
    for (int i=0 ; i<height ; ++i) board[i] = new char[width+1]() ;

}

Rhombus::Rhombus (const Rhombus &square): side(square.side)
{
    name = new char[10]() ;
    strcpy(name , "Rhombus") ;
    width = side ;
    height = side ;
    board = new char*[height]() ;
    for (int i=0 ; i<height ; ++i) board[i] = new char[width+1]() ;
}

Rhombus::~Rhombus ()
{
    delete[] name ;
    for (int i=0 ; i<height ; ++i) delete[] board[i] ;
    delete[] board ;
}

void Rhombus::drawBoard ()
{
    for (int i=0 ; i<height/2+1 ; ++i)
    {
        for (int j=0 ; j<side-i ; ++j)
        {
            board[i][j] = ' ' ;
        }
        for (int j=0 ; j<2*i-1 ; ++j)
        {
            if (j==0 || j==2*i-2) board[i][side-i+j] = '*' ;
            else board[i][side-i+j] = '@' ;
        }
    }
    for (int i=0 ; i<height/2 ; ++i)
    {
        for (int j=0 ; j<=i+1 ; ++j)
        {
            board[height/2+i+1][j] = ' ' ;
        }
        for (int j=2*(side-i)-1 ; j>=0 ; --j)
        {
            if (j==0 || j==2*(side-i)-1) board[height/2+i+1][side-i+j] = '*' ;
            else board[height/2+i+1][side-i+j] = '@' ;
        }
    }
}

void Rhombus::printBoard () const
{
    for (int i=0 ; i<height ; ++i)
    {
        std::cout << "    " << board[i] << '\n' ;
    }
}
