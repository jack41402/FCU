#include <iostream>
#include <cstring>
#include "triangle.h"

Triangle::Triangle (const int& value): side(value)
{
    name = new char[10]() ;
    strcpy(name , "Triangle") ;
    width = 2 * side ;
    height = side ;
    board = new char*[height]() ;
    for (int i=0 ; i<height ; ++i) board[i] = new char[width+1]() ;

}

Triangle::Triangle (const Triangle &square): side(square.side)
{
    name = new char[10]() ;
    strcpy(name , "Triangle") ;
    width = side ;
    height = side ;
    board = new char*[height]() ;
    for (int i=0 ; i<height ; ++i) board[i] = new char[width+1]() ;
}

Triangle::~Triangle ()
{
    delete[] name ;
    for (int i=0 ; i<height ; ++i) delete[] board[i] ;
    delete[] board ;
}

void Triangle::drawBoard ()
{
    for (int i=0 ; i<height ; ++i)
    {
        for (int j=0 ; j<side-i ; ++j)
        {
            board[i][j] = ' ' ;
        }
        for (int j=0 ; j<2*i-1 ; ++j)
        {
            if (j==0 || j==2*i-2) board[i][side+i+j] = '*' ;
            else board[i][side+i+j] = '@' ;
        }
        board[i][width] = '\0' ;
    }
}

void Triangle::printBoard () const
{
    for (int i=0 ; i<height ; ++i)
    {
        std::cout << "    " << board[i] << '\n' ;
    }
}
