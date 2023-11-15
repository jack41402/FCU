#include <stdio.h>
#include <math.h> //sqrt
#include <stdlib.h> //abs

int print_pretty_format(int a, int b, int c){    // Pretty printing of the quadratic equation. 
  if(a!=0){
    if(a==-1){     //If a is -1, just print "-" 
      printf("-X**2");
    }
    else if(a==1){  // Print coefficient a
      printf("X**2"); 
    }
    else{
      printf("%d",a);
      printf("X**2"); //If a is not 1 or -1, just print the cofficient
    }
  }

  if(b>0){
    printf("+");  //If b is 1, only print "+"
    if(b!=1){   // If b is not 1, print b with "+" sign.
      printf("%d",b);
    }
    printf("X");
  }
  else if(b<0){
    if(b==-1){
      printf("-X");
    }
    else{
      printf("%d", b);
      printf("X");
    }
  }

  if(c>0){     //If c is positive, print c with "+"
    printf("+");
    printf("%d", c);
  }
  else if(c<0){   //If c is negative, just print c
    printf("%d", c);
  }

  printf("=0"); //Print the right hand side of the equation
}


int check_det(int a, int b, int c){
    if (a == 0){
      printf("a = 0 invalid!");  //If input 0 to a, print =0 invalid
      return 0;
    }

    int det = b * b -4 *a *c;
    double sqrt_det = sqrt(abs(det));

    if(det>0){
      // different real roots
      printf("The real roots of equation ");
      print_pretty_format(a,b,c);
      printf(" are ");
      printf("%.4f and %.4f", (double) (-b+sqrt_det)/(2*a), (double) (-b-sqrt_det)/(2*a) );
    }
    else if(det == 0){
      // multiple real roots
      printf("The multiple real root of equation ");
      print_pretty_format(a,b,c);
      printf(" is ");
      if (b==0){
        printf("%.4f", (double)b/(2*a));
      }
      else{
        printf("%.4f", -(double)b/(2*a));
      }
    }
    else{
      // complex roots
      printf("The complex roots of equation ");
      print_pretty_format(a,b,c);
      printf(" are ");
      if (b ==0){
        printf("%.4fi and -%.4fi",  sqrt_det/(2*a),  sqrt_det/(2*a));
      }
      else{
        printf("%.4f+%.4fi and %.4f-%.4fi", -(double)b/(2*a), sqrt_det/(2*a), -(double)b/(2*a), sqrt_det/(2*a));
      }
    }

}

int main(){
   int a,b,c;
   printf("Solving roots of equation aX^2+bX+c=0\n");   //Starting message 
   printf("Please enter three integer coefficients a, b, and c : ");  //Request to input coefficients.
   scanf("%d %d %d", &a, &b, &c);

   check_det(a,b,c);
   return 0;
}
