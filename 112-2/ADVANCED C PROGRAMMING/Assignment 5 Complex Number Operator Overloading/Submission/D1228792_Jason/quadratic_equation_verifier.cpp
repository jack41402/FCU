#include <iostream>
#include "complex_overloading.h"
#include <math.h>
#include <iomanip>
using namespace std;
int main(void){
	double a,b,c;
	int k=0;
	Complex ans1,ans2,equ1,equ2;
	//input the coefficients of the equation.
	cout<<"Enter coefficients a, b, and c: ";
	cin>>a>>b>>c;
	cout<<"\nThe two roots of quadratic equation ";
	if(a==1.0) cout<<"X**2";
	else if(a==-1.0) cout<<"-X**2";
	else cout<<fixed<<setprecision(4)<<a<<"X**2";
	//set up the printing.
	if(b==1.0) cout<<"+X";
	else if(b==-1.0) cout<<"-X";
	else if(b>0.0) cout<<"+"<<fixed<<setprecision(4)<<b<<"X";
	else if(b<0.0) cout<<fixed<<setprecision(4)<<b<<"X";
	if(c>0.0) cout<<"+"<<fixed<<setprecision(4)<<c;
	else if(c<0.0) cout<<fixed<<setprecision(4)<<c;
	//calculate the root.
	cout<<"=0.0000 are:\n        ";
	if(b*b-4*a*c>0.0){
		ans1.setRe((-1*b+sqrt(b*b-4*a*c))/(2*a));
		ans2.setRe((-1*b-sqrt(b*b-4*a*c))/(2*a));
	}
	else if(b*b-4*a*c==0.0){
		ans1.setRe((-1*b+sqrt(b*b-4*a*c))/(2*a));
		ans2.setRe((-1*b+sqrt(b*b-4*a*c))/(2*a));
	}
	else{
		ans1.setRe((-1*b)/(2*a));
		ans2.setRe((-1*b)/(2*a));
		ans1.setIm((sqrt(-1*(b*b-4*a*c)))/(2*a));
		ans2.setIm(-1*(sqrt(-1*(b*b-4*a*c)))/(2*a));
	}
	if(ans1.getRe()!=0.0) cout<<fixed<<setprecision(4)<<ans1.getRe();
	if(ans1.getIm()!=0.0){
		if(ans1.getIm()>0.0) cout<<"+"<<fixed<<setprecision(4)<<ans1.getIm()<<'i';
		else cout<<fixed<<setprecision(4)<<ans1.getIm()<<'i';
	}
	cout<<" and ";
	if(ans2.getRe()!=0.0) cout<<fixed<<setprecision(4)<<ans2.getRe();
	if(ans2.getIm()!=0.0){
		if(ans2.getIm()>0.0) cout<<"+"<<fixed<<setprecision(4)<<ans2.getIm()<<'i';
		else cout<<fixed<<setprecision(4)<<ans2.getIm()<<'i';
	}
	//verify.
	cout<<"\nVerification of the two quadratic equation roots ";
	equ1 = a*ans1*ans1+b*ans1+c;
	equ2 = a*ans2*ans2+b*ans2+c;
	if(equ1.absolute() >= 0.000001) k++;
	if(equ2.absolute() >= 0.000001) k++;
	if(k==0) cout<<"PASSES.\n";
	else cout<<"FALSES.\n";
	return 0;
}
