#include<stdio.h>
#include<math.h>
void zon(int a,int b,int c){ //a function to print out the equation
    if(a != 0 && a != 1) 
        printf("%dX^2", a);
    if (a == 1)
        printf("X^2");
    if(b > 0)
        printf("+");
    if(b != 0 && b != 1)
        printf("%dX",b);
    if(b == 1)
        printf("X");
    if (c > 0)
        printf("+");
    if(c != 0)
        printf("%d",c);
    if(a ==0 && b == 0 && c==0)
        printf("0");
    printf("=0");

}

int main(){
    int a, b, c; 
    printf("Solving roots of equation a*X+b*X+c = 0\n");
    printf("Please enter three integer coefficients a,b, and c: ");
    scanf("%d %d %d",&a, &b, &c); 
    printf("\n");
    int bb4ac = b*b - 4*a*c; // this equation can determin how much root this equation have
    double equation1 = (-b+sqrt(bb4ac))/(2*a); // the equation might has two roots 
    double equation2 = (-b-sqrt(bb4ac))/(2*a);
    if(bb4ac == 0){ // only has one
        printf("The multiple real root of equation ");
        zon(a,b,c);
        if (equation1 == 0) equation1 = 0;
        printf(" is %.04lf.\n", equation1);
    }
    else if(bb4ac > 0){// have two
        printf("The real roots of equation ");
        zon(a,b,c);
        if (equation1 == 0) equation1 = 0;// in case it printed out -0
        if (equation2 == 0) equation1 = 0;
        printf(" are %.04lf and %.04lf.\n", equation1, equation2);// print out 4 number after decimal point
    }
    else{
        printf("The complex roots of equation "); // bb4ac < 0 will have complex roots
        zon(a,b,c);
        int nbb4ac = bb4ac * -1;
        double R = -(double)b/(2*a); //real quantity 
        double i = sqrt(nbb4ac)/(2*a); // imaginary quantity
        if(R != 0) // roots having real quantity or not.
            printf(" are %0.4lf+%0.4lfi and %0.4lf-%0.4lfi.\n", R, i,R,i);
        else
            printf(" are %0.4lfi and -%0.4lfi.\n", i,i);
    }

    
    
    
    
    
    
    
    
    // printf("%lf\n", equation1);
    // printf("%lf", bb4ac);
}
