#include<stdio.h>
#include<math.h>
int main(void) {
	float x,d,e,f,h,a,b,c;//Declaring the variables and coefficients
	printf("Solving roots of equation a*X^2+b*X+c:0.");//Print Solving roots of equation a*x^2+b*x+c:0.
	printf("\n");//Change to next line
	printf("Please enter three coefficients a.b and c: ");//Print Please enter three coefficients a.b and c: 
	scanf("%f%f%f",&a,&b,&c);//scan the coefficients inputted
	printf("\n");//Change to next line
	if(a==0){//If a equals zero, print error																
		printf("error");}//Print error
	else{//If a does not equal zero, execute the codes below
	//Determine whether the root is real, multiple real or complex
	if(pow(b,2)-4*a*c==0){//If the b to the power of two minus four times c equals zero, print The multiple real root of equation
	printf("The multiple real root of equation ");}//Print The multiple real root of equation
	else if(pow(b,2)-4*a*c>0){//If the b to the power of two minus four times c does not equal zero, and is bigger than zero, print The real roots of equation
	printf("The real roots of equation ");}//Print The real roots of equation
	else{//If not all above including the b to the power of two minus four times c does not equal zero, and is not bigger than zero, but is smaller than zero, print The complex roots of equation
	printf("The complex roots of equation ");}//Print The complex roots of equation
	//Letting the code print pretty
	if(a==1){//If a equals one, print X**2
		printf("X**2");}//Print X**2
	else if(a==-1){//If a does not equal one, but equals minus one, print -X**2
		printf("-X**2");}//Print -X**2
	else {//If not all above including a does not equal one and minus one, but is bigger than one or smaller than minus one, print %.0fX**2
		printf("%.0fX**2",a);}//Print %.0fX**2, plug a into %.0f
	if(b>1){//If b is bigger than one, print +%.0fX
		printf("+%.0fX",b);}//Print +%.0fX, plug b into %.0f
	else if(b<-1){//If b isn't bigger than one, but is smaller than minus one, print %.0fX
		printf("%.0fX",b);}//Print %.0fX, plug b into %.0f
	else if(b==1){//If b isn't bigger than one and not smaller than minus one, but equals one, print +X
		printf("+X");}//Print +X
	else if(b==-1){//If b isn't bigger than one and not smaller than minus one and doesn't equal one, but equals minus one, print -X
		printf("-X");}//Print -X
	else{//If not all above including b isn't bigger than one and not smaller than minus one and doesn't equal one and minus one, but equals zero, print nothing
		printf("");}//Print nothing
	if(c>0){//If c is bigger than zero, print +%.0f
		printf("+%.0f",c);}//Print +%.0f, plug c into %.0f
	else if(c<0){//If c is not bigger than zero, but is smaller than zero, print -%.0f
		printf("-%.0f",c);}//Print -%.0f, plug c into %.0f
	else {//If not all above including c is not bigger than zero and is not smaller than zero, but it equals zero, print nothing
		printf("");}//Print nothing
	d=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);//Defining d, equals (-b+sqrt(pow(b,2)-4*a*c))/(2*a)
	e=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);//Defining e, equals (-b-sqrt(pow(b,2)-4*a*c))/(2*a)
	f=sqrt((-1)*(pow(b,2)-4*a*c))/(2*a);//Defining f equals sqrt((-1)*(pow(b,2)-4*a*c))/(2*a)
	h=-b/(2*a);//Defining h equals -b/(2*a)
	if(pow(b,2)-4*a*c==0){//If the b to the power of two minus four times c equals zero, print =0 is %.4f
		printf("=0 is %.4f",d);}//Print =0 is %.4f, plug d into %.4f
	else if(pow(b,2)-4*a*c>0){//If the b to the power of two minus four times c does not equal zero, but is bigger than zero, execute the codes below
		if(d==0){//If, while the b to the power of two minus four times c does not equal zero, but is bigger than zero, and d equals zero, print =0 are 0.0000 and %.4f.
				printf("=0 are 0.0000 and %.4f.",e);}//Print =0 are 0.0000 and %.4f., plug e into %.4f
		else if(e==0)//If, while the b to the power of two minus four times c does not equal zero, but is bigger than zero, and d does not equal zero, but e equals zero, print =0 are %.4f and 0.0000.
		printf("=0 are %.4f and 0.0000.",d);//Print =0 are %.4f and 0.0000., plug d into %.4f
		else{//If, while the b to the power of two minus four times c does not equal zero, but is bigger than zero, and d and e does not equal zero, print =0 are %.4f and %.4f.
			printf("=0 are %.4f and %.4f.",d,e);}}//Print =0 are %.4f and %.4f., plug d and e into %.4f
	else if(pow(b,2)-4*a*c<0&&b==0){//If the b to the power of two minus four times c does not equal zero, and is not bigger than zero, but is smaller than zero, and b equals zero, print=0 are %.4fi and -%.4fi.
		printf("=0 are %.4fi and -%.4fi.",f,f);}//Print=0 are %.4fi and -%.4fi., plug f and f into %.4f and -%.4f
	else{//If the b to the power of two minus four times c does not equal zero, and is not bigger than zero, but is smaller than zero, and b does not equals zero, print =0 are %.4f+%.4fi and %.4f-%.4fi.
		printf("=0 are %.4f+%.4fi and %.4f-%.4fi.", h,f,h,f);}}//Print =0 are %.4f+%.4fi and %.4f-%.4fi.,plug h, f, h and f into %.4f, %.4fi, %.4f and -%.4fi
return 0;
}

