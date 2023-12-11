#include<stdio.h>
#include<math.h>
int main(void){
//inputting coefficients
	float a,b,c,real,jdg,rt1,rt2,jdg1;
	printf("Solving roots equation aX^2+bX+c=0\n");
	printf("Please enter three integer coefficients a, b and c: \n");         
	scanf("%f %f %f",&a,&b,&c);
//calculating the roots	
	real=-1*b/(2*a);//the prior part of the root
	jdg=pow((pow(b,2)-4*a*c),0.5)/(2*a);//the hind part of the root
	jdg1=-1*jdg;
	rt1=real+jdg;//fisrt root
	rt2=real+jdg1;//second root
	if(real==-0){
		real=0;
    }
	if(pow(b,2)-4*a*c<0){
		printf("The complex roots of equation ");
	}
	if(pow(b,2)-4*a*c==0){
		printf("The real root of equation ");
	}
	if(pow(b,2)-4*a*c>0){
		printf("The real roots of equation ");		
	}
//examine coefficient for x^2
	if(a==1){
			printf("X**2");
	}
	else if(a==-1){
			printf("-X**2");
	}
	else{
			printf("%.0fX**2",a);
	}
//examine coefficient for x
	if(b==1){
			printf("X");
	}
	if(b==-1){
			printf("-X");
	}
	if(b>0){
			printf("+%.0fX",b);
	}
	else if(b<0){
			printf("%.0fX",b);
	}
	else{
	}
//examine constant
	if(c>0){
			printf("+%.0f",c);
	}
	else if(c<0){
			printf("%.0f",c);
		}
	else{
		}
//	categorizing the roots by the discriminants	
	if(pow(b,2)-4*a*c==0){//one root
		printf("=0 is ");	
		printf("%.4f",real);
	}
	else if(pow(b,2)-4*a*c<0){//complex roots
		jdg=pow((4*a*c-pow(b,2)),0.5)/(2*a);
		jdg1=-1*jdg;
		if (b==0){
			printf("=0 are ");
			printf("%.4fi and ", jdg);
			printf("%.4fi\n", jdg1);		
		}
		else{		
		printf("=0 are ");	
		printf("%.4f+",real);
		printf("%.4fi and ", jdg);
		printf("%.4f",real);
		printf("%.4fi\n", jdg1);
		}
	}
	else{//real roots
		printf("=0 are ");	
		printf("%.4f and ",rt1);
		printf("%.4f\n",rt2 );
	}			
}
