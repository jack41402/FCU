#include <iostream>
#include <cstring>
#include "square.h"

Square::Square (const int& value): side(value)
{
    name = new char[10]() ;
    strcpy(name , "Square") ;
    width = side ;
    height = side ;
    board = new char*[height]() ;
    for (int i=0 ; i<height ; ++i) board[i] = new char[width+1]() ;

}

Square::Square (const Square &square): side(square.side)
{
    name = new char[10]() ;
    strcpy(name , "Square") ;
    width = side ;
    height = side ;
    board = new char*[height]() ;
    for (int i=0 ; i<height ; ++i) board[i] = new char[width+1]() ;
}

Square::~Square ()
{
    delete[] name ;
    for (int i=0 ; i<height ; ++i) delete[] board[i] ;
    delete[] board ;
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
        board[i][width] = '\0' ;
    }
}

void Square::printBoard () const
{
    for (int i=0 ; i<height ; ++i)
    {
        std::cout << "    " << board[i] << '\n' ;
    }
}
