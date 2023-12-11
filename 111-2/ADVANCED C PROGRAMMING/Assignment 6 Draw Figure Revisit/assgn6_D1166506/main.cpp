#include <iostream>
#include "square.h"
#include "triangle.h"
#include "rhombus.h"

int main ()
{
    int figure , side ;
    while (true)
    {
        do
        {
            std::cout<<"Enter figure code, 1: Square, 2: Triangle, 3: Rhombus: " ;
            std::cin>>figure ;

        } while (figure<0 || 3<figure) ;
        if (figure==0) return 0 ;
        do
        {
            std::cout<<"Enter side if figure (between 3 and 20): " ;
            std::cin>>side ;
        } while (side<3 || side>20) ;

        switch (figure)
        {
            case 1:
            {
                Square square(side) ;
                square.drawBoard() ;
                square.info() ;
                square.printBoard() ;
                break ;
            }
            case 2:
            {
                Triangle triangle(side) ;
                triangle.drawBoard() ;
                triangle.info() ;
                triangle.printBoard() ;
                break ;
            }
            case 3:
            {
                Rhombus rhombus(side) ;
                rhombus.drawBoard() ;
                rhombus.info() ;
                rhombus.printBoard() ;
                break ;
            }
            default:
            {
                break ;
            }
        }
    }
    return 0;
}
