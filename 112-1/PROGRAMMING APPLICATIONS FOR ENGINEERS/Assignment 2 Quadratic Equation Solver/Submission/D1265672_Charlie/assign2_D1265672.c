#include <stdio.h>
#include <math.h>
void decide(long long int a, long long int b, long long int c){ // A function that decide which should be print
    // add + in front of lld is because I need it to print out the value is positive or negative
    if (a != 0){
        if (a == 1) printf("X**2"); // if num = 1 than print X**2, not 1X**2
        else if (a == -1) printf("-X**2"); // same as num = 1 but it is negative X**2
        else printf("%lldX**2", a); // if num not equal to zero than print the number before X**2
    }
    
    if (b != 0){
        if (b == 1) printf("X"); // if num1 = 1 print X, not 1X
        else if (b == -1) printf("-X"); // if num1 = -1, print -X, not -1X
        else printf("%+lldX", b); // if num1 not equal to zero than print the number before X
    }
    
    if (c != 0){
        printf("%+lld", c); // if the num2 not equal to zero than print the value
    }
}
int main(void) {
    // variable
    long long int a, b, c;
    double ans1, ans2, d;
    
    printf("Solving roots of equation a*X^2+b*X+c = 0.\n");
    printf("Please enter three integer coefficients a, b, and c: ");
    //scanf("%lld %lld %lld", &a, &b, &c);
    while(scanf("%lld %lld %lld", &a, &b, &c) == 3 && a ==0 ){
		printf("Enter again ");
	} // input a b c three data
    
    d = b * b - 4. * a * c; // count d, use to check what kind of equation
    
    if (d == 0) { // if d = 0
        ans1 = -b / (2. * a); // caculate the multiple root
        printf("The multiple real root of equation "); // print the equation
        decide(a, b, c); // print the equation of X**2 or X
        printf("=0 is %.4lf.\n", ans1+0.0); // print the root
    }
    else if (d > 0){ // if d > 0
        ans1 = (-b + sqrt(d)) / (2. * a); // calculate roots
        ans2 = (-b - sqrt(d)) / (2. * a);
        printf("The real roots of equation "); // print the equation
        decide(a, b, c); // print the equation use decide function
        printf("=0 are %.4lf and %.4lf.\n", ans1+0.0, ans2+0.0); // print two roots (add+0.0 to prevent -0.0000 happen)
    }
    else{
        ans1 = (-b) / (2. * a); // caculate roots
        ans2 = sqrt(fabs(d)) / (2. * a);
        printf("The complex roots of equation "); // print the equation
        decide(a, b, c); // print the equation use decide function
        if (ans1 == 0){ // if ans1 = 0 then dont print it out
            printf("=0 are %.4lfi and -%.4lfi.\n",ans2+0.0, ans2+0.0); // print roots
        }
        else{
            printf("=0 are %.4lf+%.4lfi and %.4lf-%.4lfi.\n",ans1, ans2+0.0, ans1, ans2+0.0); // print roots
        }
    }
    return 0;
}

