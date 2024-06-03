#include <iostream>
#include"complex_overloading.h"
#include<math.h>
#include<iomanip>

using namespace std;
int main(void) {
	double a, b, c;//define the coefficient variable
	Complex ans_1, ans_2, ans_3, ans_4;//define the four Complex value
	int i=0;//set i variable to 0
	cout<<"Enter coefficients a, b, and c: ";
	cin>>a>>b>>c;//input three double number
	cout<<"\nThe two roots of quadratic equation ";
	if (a==1.0){//when a=1, print out X**2
		cout<<"X**2";
	} 
	else if (a==-1.0){//when a=-1, print out -X**2
		cout<<"-X**2";
	}
	else{
		cout<<fixed<<setprecision(4)<<a<<"X**2";
	}
	if (b==1.0){//when b=1, print out X
		cout<<"X";
	}
	else if (b==-1.0){//when b=-1, print out -X
		cout<<"-X";
	}
	else if (b>0.0){//print out the + sign when b>0
		cout<<"+"<<fixed<<setprecision(4)<<b<<"X";
	}
	else if (b<0.0){
		cout<<fixed<<setprecision(4)<<b<<"X";
	}
	if (c>0.0){//print out the + sign when c>0
		cout<<"+"<<fixed<<setprecision(4)<<c;
	}
	else if (c<0.0){
		cout<<fixed<<setprecision(4)<<c;
	}
	cout<<"=0.0000 are:\n";
	//use the Discriminant to determine the root are two double numbers or one double number or two complex numbers
	if (b*b-4*a*c>0.0){
		ans_1.setRe(((-1*b+sqrt(b*b-4*a*c))/(2*a)));
		ans_2.setRe(((-1*b-sqrt(b*b-4*a*c))/(2*a))); 
	}
	else if (b*b-4*a*c==0.0){
		ans_1.setRe(((-1*b+sqrt(b*b-4*a*c))/(2*a)));
		ans_2.setRe(((-1*b+sqrt(b*b-4*a*c))/(2*a))); 
	}
	else {
		ans_1.setRe((-1*b)/(2*a));
		ans_2.setRe((-1*b)/(2*a));
		ans_1.setIm((sqrt(-1*(b*b-4*a*c)))/(2*a));
		ans_2.setIm(-1*(sqrt(-1*(b*b-4*a*c)))/(2*a));
	}
	//print out the roots
	cout<<"        ";
	if (ans_1.getRe()!=0.0){
		cout<<fixed<<setprecision(4)<<ans_1.getRe();
	}
	if (ans_1.getIm()!=0.0){
		if (ans_1.getIm()>0.0){
			cout<<"+"<<fixed<<setprecision(4)<<ans_1.getIm()<<"i";
		}
		else{
			cout<<fixed<<setprecision(4)<<ans_1.getIm()<<"i";
		}
	}
	cout<<" and ";
	if (ans_2.getRe()!=0.0){
		cout<<fixed<<setprecision(4)<<ans_2.getRe();
	}
	if (ans_2.getIm()!=0.0){
		if (ans_2.getIm()>0.0){
			cout<<"+"<<fixed<<setprecision(4)<<ans_2.getIm()<<"i";
		}
		else{
			cout<<fixed<<setprecision(4)<<ans_2.getIm()<<"i";
		}
	}
	//verify while the root are precise enough
	cout<<"\n"<<"Verification of the two quadratic equation roots ";
	ans_3 = a*ans_1*ans_1+b*ans_1+c;
	ans_4 = a*ans_2*ans_2+b*ans_2+c;
	if (ans_3.abs()<=0.000001){
		i++;
	}
	if (ans_4.abs()<=0.000001){
		i++;
	}
	if (i==2){
		cout<<"PASSES.\n";
	}
	else {
		cout<<"DOESN'T PASS.\n";
	}
	return 0;
}
