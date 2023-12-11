#include <stdio.h>

int main()
{
    //declare the variable of layer, side, growth, width, height
    int layer , side , growth , width , height ;
    //input the number of layers
    do
    {
        printf ("Enter the number of layers (2 to 5): ") , fflush (stdout) ;
        scanf ("%d" , &layer) ;
    }
    while (!(2<=layer && layer<=5)) ;
    //input the side of top layer
    do
    {
        printf ("Enter the side of top layer (3 to 6): ") , fflush (stdout) ;
        scanf ("%d" , &side) ;
    }
    while (!(3<=side && side<=6)) ;
    //input the growth of each layer
    do
    {
        printf ("Enter the growth of each layer (1 to 5): ") , fflush (stdout) ;
        scanf ("%d" , &growth) ;
    }
    while (!(1<=growth && growth<=5)) ;
    //input the trunk width
    do
    {
        printf ("Enter the trunk width (odd number, 3 to 9): ") , fflush (stdout) ;
        scanf ("%d" , &width) ;
    }
    while (!((3<=width && width<=9) && width&1)) ;
    //input the trunk height
    do
    {
        printf ("Enter the trunk height (4 to 10): ") , fflush (stdout) ;
        scanf ("%d" , &height) ;
    }
    while (!(4<=height && height<=10)) ;
    //declare and initialize the variable of space and layer_count in order to control the output
    int space , layer_count ;
    space = side + (layer-1) * growth - 1 + 10 , layer_count = side ;
    //print the Christmas tree
    for (int i=1 ; i<=layer ; ++i)
    {
        //print each layer
        for (int j=1 ; j<=layer_count ; ++j)
        {
            //print the space and sharp.
            //If encounter the top of the first layer, print a sharp sign.
            // If encounter the top of other layer, continue the loop.
            if (i!=1 && j==1) continue ;
            for (int k=j ; k<=space ; ++k) printf (" ") ;
            if (i==1 && j==1)
            {
                printf ("#\n") ;
                continue ;
            }
            //If encounter the bottom of the layer, print a row of sharp sign.
            if (j==layer_count)
            {
                for (int k=1 ; k<=2*j-1 ; ++k) printf ("#") ;
                printf ("\n") ;
                continue ;
            }
            //If it doesn't encounter the bottom layer, print as normal.
            printf ("#") ;
            for (int k=1 ; k<=2*(j-1)-1 ; ++k) printf ("@") ;
            printf ("#\n") ;
        }
        layer_count += growth ;
    }
    for (int i=1 ; i<=height ; ++i)
    {
        //print the space and trunk
        for (int j=1 ; j<=space-width/2 ; ++j) printf (" ") ;
        for (int j=1 ; j<=width ; ++j) printf ("|") ;
        printf ("\n") ;
    }
    return 0;
}
