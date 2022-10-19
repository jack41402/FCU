#include <stdio.h>

//Remember to use flag V to prevent from overflow

int adder (int a , int b , int carry)
{
    int ans=0 ;
    for (int i=0 ; i<=32 ; ++i)
    {
        //Get the bit of integer variables a and b ;
        ans |= ((((a>>i) & 1 ^ (b>>i) & 1) ^ carry)<<i) ;
        carry = ((((a>>i)&1) & ((b>>i)&1)) | (((a>>i) & 1 ^ (b>>i) & 1) & carry)) ;
    }
    return ans ;
}

int main()
{
    int a , b , m=0 ;
    char sign ;
    scanf ("%d%c%d" , &a , &sign , &b) ;
    if (sign=='-') m = 1 , b = ~b ;
    printf ("%d\n" , adder (a , b , m)) ;
    return 0;
}
