#include <stdio.h>
#include <math.h>
void print_equation(float a,float b,float c){
    if (a==1.0)
        printf("X**2");
    else if (a==-1.0)
        printf("-X**2");
    else
        printf("%.0fX**2",a);
    if (b>0.0){
      if (b==1.0)
        printf("+X");
      else
        printf("+%.0fX",b);
    }
    else if (b<0.0){
      if (b==-1.0)
        printf("-X");
      else
        printf("%.0fX",b);
    }
    if (c>0.0)
        printf("+%.0f",c);
    else if (c<0.0)
        printf("%.0f",c);
    printf("=0");
}
int main(void) {
  int a ,b ,c ,d;
  double r1 ,r2;
  float real_root ,imaginary_root;
  printf("Solving roots of equation a*X^2+b*X+c = 0.\n\n");
  do {
    printf("Please enter three coefficients a, b, and c: \n");
    scanf("%d %d %d",&a ,&b ,&c);
    if(a==0.0)
        printf("The coefficient of X^2 cannot be zero.\n\n");
    }
    while(a==0.0);
        d=b*b-4*a*c;
  
  if(d>0){
    r1=(-b+sqrt(d)/(2*a));
    if(r1==0)
      r1=0;
    r2=(-b-sqrt(d)/(2*a));
    if(r2==0)
      r2=0;
    printf("The real roots of equation ");
    print_equation(a ,b ,c);
    printf(" are %.4lf and %.4lf.\n",r1 ,r2);
    }
  else if(d==0){
    r1=-b/(2*a);
    if(r1==0)
      r1=0;
    printf("The multiple real root of equation ");
    print_equation(a ,b ,c);
    printf(" is %.4f.\n", r1);
    }
  else{
      real_root=-b/(2*a);
      imaginary_root=sqrt(-d)/(2*fabs(a));
    printf("The complex roots of equation ");
    print_equation(a ,b ,c);
    if(real_root!=0)
      if(imaginary_root!=1.0)
        printf(" are %.4f+%.4fi and %.4f-%.4fi.\n",real_root ,imaginary_root ,real_root, imaginary_root);
      else
        printf(" are %.4f+i and %.4f-i.\n",real_root ,real_root);
    else
      if(imaginary_root!=1.0)
        printf(" are %.4fi and -%.4fi.\n",imaginary_root ,imaginary_root);
      else printf(" are i and -i.\n");
  }
  return 0;
}

