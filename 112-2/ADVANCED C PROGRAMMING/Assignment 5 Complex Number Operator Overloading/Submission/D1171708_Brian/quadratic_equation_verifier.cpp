#include <iostream>
#include <math.h>
#include <iomanip>
#include "complex_overloading.h"
using namespace std;

int main() {
    // Define the coefficients of the quadratic equation
    double a,b,c;
    cout << "Enter coefficients a, b, and c :";
    cin >> a >> b >> c ;
    cout << "\nThe two roots of quadratic equation";
    
	if(a==1){
		cout << "X**2";
	}
	else{
		cout << fixed << setprecision(4)<< a << "X**2"; 
	}
	
	if(b>0){
		if(b==1){
			cout <<"+X";
		}
		else{
			cout << "+" << fixed << setprecision(4)<< b << "X"; 
		} 
	}
	else if(b<0){
		if(b==-1){
			cout <<"-X";
		}
		else{
			cout << "-" << fixed << setprecision(4) <<-b << "X"; 
		} 		
	}
	else{
		cout <<"";
	}

	if(c>0){
		cout << "+" << fixed << setprecision(4)<< c; 
	}
	else if(c<0){
		cout << "-" << fixed << setprecision(4)<< -c;	
	}
	else{
		cout <<"";
	}
	cout << "=0.0000 are :"<< endl;
    
    Complex root1, root2;
    Complex a_complex(a,0.0);
    Complex b_complex(b,0.0);
    Complex c_complex(c,0.0);
	Complex d_complex = b_complex*b_complex - Complex(4.0, 0.0)*a_complex*c_complex;
	
	if(d_complex.getRe()>0){
    	root1 =  Complex(0.0,0.0) - (b_complex - d_complex.square())/(Complex(2.0, 0.0)*a_complex);
		root2 =  Complex(0.0,0.0) - (b_complex + d_complex.square())/(Complex(2.0, 0.0)*a_complex);
	}
	if(d_complex.getRe()==0){
    	root1 =  Complex(0.0,0.0) - (b_complex)/(Complex(2.0, 0.0)*a_complex);
	 	root2 =  Complex(0.0,0.0) - (b_complex)/(Complex(2.0, 0.0)*a_complex);
	}
	
	if(d_complex.getRe()<0){
		d_complex = Complex(0.0,0.0)-(d_complex);
		root1 = Complex(0.0,0.0) - (b_complex - Complex(0.0,1.0)*d_complex.square())/(Complex(2.0, 0.0)*a_complex);
		root2 = Complex(0.0,0.0) - (b_complex + Complex(0.0,1.0)*d_complex.square())/(Complex(2.0, 0.0)*a_complex);
	}

    Complex verify1 = a_complex * root1 * root1 + b_complex * root1 + c_complex;
    Complex verify2 = a_complex * root2 * root2 + b_complex * root2 + c_complex;
	

    cout << "	" << root1 <<" and "<<root2 << endl;
    if (verify1.abs() < 0.000001)
    	if (verify2.abs() < 0.000001){
    		cout << "Verification of the two quadratic equation roots PASSES."<<endl;
		}
    else{
    	cout << "Verification of the two quadratic equation roots FAILED."<<endl;
	}
    return 0;
}
