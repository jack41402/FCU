#include <iostream>
#include <cstring>
#include "draw.h"

Draw::Draw ()
{
    name = NULL ;
    width = 0 ;
    height = 0 ;
    board = NULL ;
}

Draw::Draw (const Draw &draw)
{
    name = draw.name ;
    width = draw.width ;
    height = draw.height ;
    board = draw.board ;
}

Draw::Draw (const std::string &FigureName , const int &FigureWidth , const int &FigureHeight)
{
    name = new char[10]() ;
    strcpy(name , FigureName.c_str()) ;
    width = FigureWidth ;
    height = FigureHeight ;
    board = new char*[height]() ;
    for (int i=0 ; i<height ; ++i) board[i] = new char[width+1]() ;
}

Draw::~Draw ()
{
    delete[] name ;
    for (int i=0 ; i<height ; ++i) delete[] board[i] ;
    delete[] board ;
}
