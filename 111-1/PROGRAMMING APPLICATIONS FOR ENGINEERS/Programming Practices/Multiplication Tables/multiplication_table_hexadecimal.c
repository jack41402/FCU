/*
  This program prints the multiplication table of hexadecimal digits (1 to F) in the following
  two formats:

Multiplication Table Format 1:

      | 1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
    --+------------------------------------------------------------
    1 | 1   2   3   4   5   6   7   8   9   A   B   C   D   E   F
    2 | 2   4   6   8   A   C   E  10  12  14  16  18  1A  1C  1E
    3 | 3   6   9   C   F  12  15  18  1B  1E  21  24  27  2A  2D
    4 | 4   8   C  10  14  18  1C  20  24  28  2C  30  34  38  3C
    5 | 5   A   F  14  19  1E  23  28  2D  32  37  3C  41  46  4B
    6 | 6   C  12  18  1E  24  2A  30  36  3C  42  48  4E  54  5A
    7 | 7   E  15  1C  23  2A  31  38  3F  46  4D  54  5B  62  69
    8 | 8  10  18  20  28  30  38  40  48  50  58  60  68  70  78
    9 | 9  12  1B  24  2D  36  3F  48  51  5A  63  6C  75  7E  87
    A | A  14  1E  28  32  3C  46  50  5A  64  6E  78  82  8C  96
    B | B  16  21  2C  37  42  4D  58  63  6E  79  84  8F  9A  A5
    C | C  18  24  30  3C  48  54  60  6C  78  84  90  9C  A8  B4
    D | D  1A  27  34  41  4E  5B  68  75  82  8F  9C  A9  B6  C3
    E | E  1C  2A  38  46  54  62  70  7E  8C  9A  A8  B6  C4  D2
    F | F  1E  2D  3C  4B  5A  69  78  87  96  A5  B4  C3  D2  E1

************************************************************************

Multiplication Table Format 2:

  1*1= 1  1*2= 2  1*3= 3  1*4= 4  1*5= 5  1*6= 6  1*7= 7  1*8= 8
  1*9= 9  1*A= A  1*B= B  1*C= C  1*D= D  1*E= E  1*F= F

  2*1= 2  2*2= 4  2*3= 6  2*4= 8  2*5= A  2*6= C  2*7= E  2*8=10
  2*9=12  2*A=14  2*B=16  2*C=18  2*D=1A  2*E=1C  2*F=1E

  3*1= 3  3*2= 6  3*3= 9  3*4= C  3*5= F  3*6=12  3*7=15  3*8=18
  3*9=1B  3*A=1E  3*B=21  3*C=24  3*D=27  3*E=2A  3*F=2D

  4*1= 4  4*2= 8  4*3= C  4*4=10  4*5=14  4*6=18  4*7=1C  4*8=20
  4*9=24  4*A=28  4*B=2C  4*C=30  4*D=34  4*E=38  4*F=3C

  5*1= 5  5*2= A  5*3= F  5*4=14  5*5=19  5*6=1E  5*7=23  5*8=28
  5*9=2D  5*A=32  5*B=37  5*C=3C  5*D=41  5*E=46  5*F=4B

  6*1= 6  6*2= C  6*3=12  6*4=18  6*5=1E  6*6=24  6*7=2A  6*8=30
  6*9=36  6*A=3C  6*B=42  6*C=48  6*D=4E  6*E=54  6*F=5A

  7*1= 7  7*2= E  7*3=15  7*4=1C  7*5=23  7*6=2A  7*7=31  7*8=38
  7*9=3F  7*A=46  7*B=4D  7*C=54  7*D=5B  7*E=62  7*F=69

  8*1= 8  8*2=10  8*3=18  8*4=20  8*5=28  8*6=30  8*7=38  8*8=40
  8*9=48  8*A=50  8*B=58  8*C=60  8*D=68  8*E=70  8*F=78

  9*1= 9  9*2=12  9*3=1B  9*4=24  9*5=2D  9*6=36  9*7=3F  9*8=48
  9*9=51  9*A=5A  9*B=63  9*C=6C  9*D=75  9*E=7E  9*F=87

  A*1= A  A*2=14  A*3=1E  A*4=28  A*5=32  A*6=3C  A*7=46  A*8=50
  A*9=5A  A*A=64  A*B=6E  A*C=78  A*D=82  A*E=8C  A*F=96

  B*1= B  B*2=16  B*3=21  B*4=2C  B*5=37  B*6=42  B*7=4D  B*8=58
  B*9=63  B*A=6E  B*B=79  B*C=84  B*D=8F  B*E=9A  B*F=A5

  C*1= C  C*2=18  C*3=24  C*4=30  C*5=3C  C*6=48  C*7=54  C*8=60
  C*9=6C  C*A=78  C*B=84  C*C=90  C*D=9C  C*E=A8  C*F=B4

  D*1= D  D*2=1A  D*3=27  D*4=34  D*5=41  D*6=4E  D*7=5B  D*8=68
  D*9=75  D*A=82  D*B=8F  D*C=9C  D*D=A9  D*E=B6  D*F=C3

  E*1= E  E*2=1C  E*3=2A  E*4=38  E*5=46  E*6=54  E*7=62  E*8=70
  E*9=7E  E*A=8C  E*B=9A  E*C=A8  E*D=B6  E*E=C4  E*F=D2

  F*1= F  F*2=1E  F*3=2D  F*4=3C  F*5=4B  F*6=5A  F*7=69  F*8=78
  F*9=87  F*A=96  F*B=A5  F*C=B4  F*D=C3  F*E=D2  F*F=E1
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, j;
  
  // Print the prelude message.
  printf("Multiplication Table for Hexadecimal Digits (1 to F) Format 1:\n\n");
  
  // Print the table head.
  printf("      |");
  for (i=1; i<=15; i++) printf("%2X  ", i);
  
  // Print the dividing line.
  printf("\n    --+");
  for (i=0; i<16; i++) printf("----");
  printf("\n");
  
  // Print the table contents
  for (i=1; i<16; i++) {  
    printf("    %X |", i); // Print the head of each raw.
    for (j=1; j<=15; j++) printf("%2X  ", i*j); // Print the product of two numbers 15 times.
    printf("\n");    
  }

  // Print the separate line.
  printf("\n************************************************************************\n\n");
  
  // Print the prelude message.
  printf("Multiplication Table for Hexadecimal Digits (1 to F) Format 2:\n\n");
  
  // Print the multiplication table of format 2. 
  for (i=1; i<=15; i++) {
    printf("  ");
    for (j=1; j<=15; j++) {
      printf("%X*%X=%2X  ", i, j, i*j);  // The fist line prints 8 expressions;
      if (j==8) printf("\n  "); // The second line prints 7 expressions.
    }
    printf("\n\n");
  }
  
  return 0; 
}
