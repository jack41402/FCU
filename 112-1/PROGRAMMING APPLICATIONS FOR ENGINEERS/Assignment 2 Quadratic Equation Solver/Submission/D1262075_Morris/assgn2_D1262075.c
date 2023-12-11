#include<stdio.h>
#include<math.h>

int main(void){
	double a,b,c;
	double r1,r2,RP,IP,D;
	printf("Solving roots of equation a*X^2+b*X+c = 0.\n\n");
	printf("Please enter three integers a,b and c:\n");
	scanf("%lf %lf %lf",&a,&b,&c);
	while(a==0){   //a cannot be zero
		printf("Please enter three integers a,b and c");
		scanf("%lf %lf %lf",&a,&b,&c);
	}
	D = (b*b) - (4*a*c);   //Discrimanant
	if(D>0)
		printf("The real roots of equation ");
	else if(D==0)
		printf("The multiple root of equation ");
	else
		printf("The complex roots of the equation ");
	
	if(a==1)
		printf("X**2");
	else if(a==-1)
		printf("-X**2");
	else 
		printf("%.4lfX**2",a);
		
	if(b==1)
		printf("X");
	else if(b==-1)
		printf("-X");
	else if(b==0) 
		printf("");
	else if(b>0)
		printf("+%.4lfX",b);
	
	if(c==0)
		printf("");
	else if(c>0)
		printf("+%.4lf",c);
	else
		printf("%.4lf",c);
		
		
	if((D>0)||(D<0))
		printf("= 0 are ");
	else
		printf("= 0 is ");
	if(D>0){        //two real roots
		r1=((-b)+sqrt(D))/(2*a);
		r2=((-b)-sqrt(D))/(2*a);
		if(r1==0) r1 = 0;
		if(r2==0) r2 = 0;
		printf("%.4lf and %.4lf",r1,r2);
	}else if(D==0){  //multiple root
		r1=(-b)/(2*a);
		printf("%.4lf",r1);
	}else{         //two complex roots 
		RP=(-b)/(2*a);
		if(a<0) a=-a;
		IP=sqrt(-D)/(2*a);
		printf("%.4lf+%.4lfi and %.4lf-%.4lfi",RP,IP,RP,IP);
	}
	
	return 0;
}
 
