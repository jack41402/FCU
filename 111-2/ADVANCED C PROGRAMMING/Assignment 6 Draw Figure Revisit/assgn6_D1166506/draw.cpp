#include <iostream>
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

void Draw::printBoard () const
{
    for (int i=0 ; i<width ; ++i)
    {
        for (int j=0 ; j<height ; ++j)
        {
            printf("%c" , board[i][j]) ;
        }
        printf("\n") ;
    }
    printf("\n") ;
}
