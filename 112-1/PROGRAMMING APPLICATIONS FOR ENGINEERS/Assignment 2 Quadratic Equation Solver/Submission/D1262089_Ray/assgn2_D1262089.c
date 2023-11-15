#include <stdio.h>
#include <math.h>
void e(int);
void f(int);
void g(int);
int check_a = 0;//check if a=0
void root(double, double, double);

int main() {
	int a,b,c;
	
	while (check_a != 1) {
    printf("Solving roots of equation a*X^2+b*X+c = 0\n");
    printf("Please enter three integer coefficients a, b, and c:");
    scanf("%d%d%d",&a,&b,&c);   
        
    if (a == 0) {
    	printf("Coefficient 'a' cannot be zero for a quadratic equation.\n");
    	printf("Please enter coefficient 'a' again.\n");
    	check_a = 0;
    	}
    else {
    	check_a = 1;
    	}
    
	}
	   
    root(a,b,c);
    return 0;
}

void e(int x){//print ax^2
	if(x==1){
		printf("X**2",x);	
	}else if(x==-1){
		printf("-X**2");
	}else{
		printf("%dX**2",x);
	}	
}

void f(int x){//print bx
	if(x==0){
		printf("");
	}else if(x==1){
	    printf("+X");
	}else if(x==-1){
	    printf("-X");
	}else if(x>0){
		printf("+%dX",x);
	}else {
		printf("%dX",x);	
}
}

void g(int x){//print c
	if(x>0){
		printf("+%d",x);	
	}else if(x==0){
		printf("");
	}else{
		printf("%d",x);
	}	
}

void root(double a, double b, double c) {
    double delta;
    if(a!=0) {
        delta = b*b - 4*a*c;
        if (delta > 0) { // Two real and distinct roots
         printf("The real roots of equation ");
         e(a);
         f(b);
         g(c);
         printf("=0 ");
            if((-b+sqrt(delta))/a/2!=0&&(-b-sqrt(delta))/a/2!=0){//change the -0.0000 to 0.0000
            printf("are %.4lf and %.4lf.", (-b+sqrt(delta))/a/2, (-b-sqrt(delta))/a/2);
			}else if((-b+sqrt(delta))/a/2==0&&(-b-sqrt(delta))/a/2!=0){
			printf("are 0.0000 and %.4lf.", (-b-sqrt(delta))/a/2);
			}else{
            printf("are %.4lf and 0.0000.", (-b+sqrt(delta))/a/2);
			}
        } else if (delta < 0) {//Complex roots
         printf("The complex roots of equation ");
         e(a);
         f(b);
         g(c);
         printf("=0 ");
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-delta) / (2 * a);
            if(realPart==0){
            printf("are %.4lfi and - %.4lfi.",imaginaryPart,imaginaryPart);	
			}else{
            printf("are %.4lf + %.4lfi and %.4lf - %.4lfi.", realPart, imaginaryPart, realPart, imaginaryPart);
            }
        } else {//One real root (repeated)//delta=0
         
         printf("The multiple real root of equation ");
         e(a);
         f(b);
         g(c);
         printf("=0 ");
            if(-b/a/2!=0){
            printf("is %.4lf.", -b/a/2);
			}else{
			printf("is 0.0000.");
			}
        }
    } 
}

