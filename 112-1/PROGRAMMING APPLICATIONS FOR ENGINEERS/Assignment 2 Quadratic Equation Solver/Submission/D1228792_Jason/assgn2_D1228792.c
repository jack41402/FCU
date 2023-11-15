#include <stdio.h>
#include <math.h>
int main(void){
	float ans1,ans2,x,a,b,c;
	//printing precondition
	printf("Solving roots of equation a*X^2+b*X+c = 0.\n");
	printf("Please enter three integer coefficients a,b and c: ");
	scanf("%f %f %f",&a,&b,&c);
	if(a!=0){//verify if the equation is linear equation of two variables
	//determine whether the answer is real, multiple real, or complex
		if(b*b-4*a*c>0)
		printf("The real roots of equation ");
		else if(b*b-4*a*c==0)
		printf("The multiple real root of equation ");
		else
		printf("The complex roots of equation ");
		//printing the equation prettily
			if(a==1)
				printf("X**2");
			else if(a==-1)
				printf("-X**2");
			else
				printf("%1.0fX**2",a);
			if(b!=0){
				if(b>0)
					printf("+%1.0fX",b);
				else
					printf("%1.0fX",b);
			}
			if(c!=0){
				if(c>0)
				printf("+%1.0f=0",c); 
				else
				printf("%1.0f=0",c);
			}
			else{
				printf("=0");
			}
			//determine whether the answer is real, multiple real, or complex
			//calculate the answers
			if(b*b-4*a*c>0){
			ans1=(-1*b+sqrt(b*b-4*a*c))/(2*a);
			ans2=(-1*b-sqrt(b*b-4*a*c))/(2*a);
			if(ans1==-0.0000){
				printf(" are %1.4f",0.0000);
				printf(" and %1.4f.",ans2);
			}
			else{
				printf(" are %1.4f",ans1);
				printf(" and %1.4f.",ans2);
			}
		}
		else if(b*b-4*a*c==0){
			ans1=(-1*b+sqrt(b*b-4*a*c))/(2*a);
			printf(" is %1.4f.",ans1);
		}
		else{
			if(b==0){
				ans1=(sqrt(-1*(b*b-4*a*c)))/(2*a);
				ans2=-1*ans1;
				printf(" are %1.4fi",ans1);
				printf(" and %1.4fi.",ans2);
			}
			else{
				printf(" are %1.4f",(-1*b)/(2*a));
				printf("+%1.4fi and ",(sqrt(-1*(b*b-4*a*c)))/(2*a));
				printf("%1.4f",(-1*b)/(2*a));
				printf("-%1.4fi.",(sqrt(-1*(b*b-4*a*c)))/(2*a));
			}
		}
	}
	else{//vertify if the equation is linear equation of two variables
		printf("error");
	}
	return 0;
}
