#include <iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include"complex_overloading.h"
using namespace std;


void print_equ(float a, float b, float c){//Prints the quadratic equation
	
	cout<<endl<<"The two roots of quadratic equation ";
	
	if(a==1) cout<<"X**2";
	else if(a==-1) cout<<"-X**2";
	else cout<<fixed << setprecision(4)<<a<<"X**2";
	
	if(b==1) cout<<"+X";
	else if(b==-1) cout<<"-X";
	else if(b>0) cout<<fixed << setprecision(4)<<"+"<<b<<"X";
	else if(b==0) cout<<"";
	else cout<<fixed << setprecision(4)<<b<<"X";
	
	if(c>0) cout<<fixed << setprecision(4)<<"+"<<c;
	else if(c==0) cout<<"";
	else cout<<fixed << setprecision(4)<<c;
	
	cout<<" are:"<<endl;
}

//Verifies the two roots
bool verifier(const Complex& root1, const Complex& root2, const double& a, const double& b, const double& c){
	
	const double epsilon =0.000001;
	Complex plug_in_value1=a*root1*root1+b*root1+c;//Plugs the first root into the equation
	Complex plug_in_value2=a*root2*root2+b*root2+c;//Plugs the second root into the equation
	
	if(plug_in_value1.cabs()<=epsilon&&plug_in_value2.cabs()<=epsilon) return true;
	else return false;
}

int main() {
	
float a, b, c;
Complex root1;
Complex root2;

do{
	cout<<"Enter coefficients a, b and c: ";

	cin>>a>>b>>c;
	
}while(a==0);
	

print_equ(a, b, c);


if((b*b-4*a*c)>=0){//If determinant >= 0
	root1.setRe((-b+sqrt(b*b-4*a*c))/(2*a));
	root1.setIm(0.0);
	root2.setRe((-b-sqrt(b*b-4*a*c))/(2*a));
	root2.setIm(0.0);
}
else{//If determinant < 0
	root1.setRe(-b/(2*a));
	root1.setIm(sqrt(fabs(b*b-4*a*c))/(2*a));
	root2.setRe(-b/(2*a));
	root2.setIm(-sqrt(fabs(b*b-4*a*c))/(2*a));
}

cout<<"	"<<fixed << setprecision(4)<<root1<<" and "<<root2<<endl;//Print out the two roots

cout<<"Verification of quadratic equation roots ";
if(verifier(root1, root2, a, b, c)==true) cout<<"PASSES";
else cout<<"FAILS";
	
	return 0;
}
