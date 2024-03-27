#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"complex_D1228817.h"

complex add(complex x, complex y){// complex addition.
	complex i;
	i.re=(x.re)+(y.re);
	i.im=(x.im)+(y.im);
	
	return i;
}

complex minus(complex x, complex y){// complex subtraction.
	complex i;
	i.re=(x.re)-(y.re);
	i.im=(x.im)-(y.im);
	
	return i;
}

complex time(complex x, complex y){// complex multiplication.
	complex i;
	i.re=((x.re)*(y.re))-((x.im)*(y.im));
	i.im=((x.re)*(y.im))+((x.im)*(y.re));
	
	return i;
}

complex divide(complex x, complex y){// complex division.
	complex i;
	i.re=(((x.re)*(y.re))+((x.im)*(y.im)))/((y.im)*(y.im)+(y.re)*(y.re));
	i.im=(((-x.re)*(y.im))+((x.im)*(y.re)))/((y.im)*(y.im)+(y.re)*(y.re));

	return i;
}

float absComplex(complex x){// Absolute value of a complex number.
	return pow((x.re)*(x.re)+(x.im)*(x.im), 0.5);
}

complex r2c(float x){// Convert a real number to a complex number
	complex i;
	i.re=x;
	i.im=0;
	return i;
}

void printComplex(complex x){// Print a complex number.
	if(x.re==0&&x.im!=0) printf("%.4f i", x.im);
	else if(x.re!=0&&x.im==0) printf("%.4f", x.re);
	else if(x.re!=0&&x.im>0) printf("%.4f+%.4f i", x.re, x.im);
	else if(x.re==0&&x.im==0) printf("%.4f", fabs(x.re));
	else printf("%.4f%.4f i", x.re, x.im);
}

