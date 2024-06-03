//quadratic_equation_verifier

#include "complex_overloading.h"
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

void printEquation(double a, double b, double c) //prints the equation in the form of "ax^2 + bx + c = 0
{
    //ax^2
    if(a == 1) //If a = 1, print without negative sign before X**2
    {
      cout << "X**2"; //Print X**2
  	}
    else if(a == -1) //If a = -1, print negative sign before X**2
  	{
    	cout << "-X**2"; //Print -X**2
  	}
    else 
  	{
  		//Print out X**2, print double type data in the fixed point format and 4 digits after the decimal point
    	cout << fixed << setprecision(4) << a << "X**2";
  	}
  	//bx
    if(b == 1) //If b = 1, print +X
  	{
    	cout << "+X";
  	}
    else if(b == -1) //If b = -1, print negative sign before X
  	{
    	cout << "-X"; //Print X
  	}
    else if(b > 0) //If b is positive, but not 1
  	{
  		//Print out X, print double type data in the fixed point format and 4 digits after the decimal point
    	cout << "+" << fixed << setprecision(4) << b << "X";
  	}
    else if(b < 0) //If b is negative, but not -1
  	{
  		//Print out X, print double type data in the fixed point format and 4 digits after the decimal point
    	cout << fixed << setprecision(4) << b << "X";
  	}
  	//c
    if(c > 0) //If c is positive
  	{
  		//Print out constant, print double type data in the fixed point format and 4 digits after the decimal point
    	cout << "+" << fixed << setprecision(4) << c <<  "=0.0000 are:" << endl;
  	}
    else if(c < 0) //If c is negative
  	{
  		//Print out constant, print double type data in the fixed point format and 4 digits after the decimal point
    	cout << fixed << setprecision(4) << c <<  "=0.0000 are:" << endl;
  	}
    else 
  	{
  		//Without printing the constance out
    	cout << "=0.0000 are:" << endl;
  	}
}

//Verifies if the given complex root satisfies the quadratic equation
bool verifyRoot(const Complex& root, double a, double b, double c) 
{
    Complex ax2 = root * root * a; //Calculate ax^2 in the equation
    Complex bx = root * b;//Calculate bx in the equation
    Complex constant = Complex(c);//Calculate the constant term in the equation
    Complex equationResult = ax2 + bx + constant; //Calculate the equation result
    //Check if the absolute value of the result is within a small tolerance
    return equationResult.abs() < 0.000001;
}


int main() 
{
 	do //Default constructor with default value 0.0+0.0i.
 	{
	  	double a, b, c; //Variables declaration
	  	cout << "Enter coefficient a, b, and c: "; //User input
	    cin >> a >> b >> c;//Scan variables to the input
	    cout <<"\n";//Move to the next line
	 
	    double D = b * b - 4 * a * c;//Discrimination declaration
	    Complex root1, root2;//Root declaration
	 
	    if(D > 0) //If discrimination is positive
	   	{
	        root1 = Complex((-b + sqrt(D)) / (2 * a)); //Calculate the root
	        root2 = Complex((-b - sqrt(D)) / (2 * a)); //Calculate the root
	    } 
	   	else if (D == 0) //If discrimination is 0
	   	{
	        root1 = root2 = Complex(-b / (2 * a)); //Calculate the root
	    } 
	   	else //If discrimination is negative
	   	{
	        root1 = Complex(-b / (2 * a), sqrt(-D) / (2 * a)); //Calculate the root
	        root2 = Complex(-b / (2 * a), -sqrt(-D) / (2 * a)); //Calulate the root
	    }
	 
	    cout << "The two roots of quadratic equation "; //Print out the script
	    printEquation(a, b, c); //Print out the equation
	    cout << "\t" << root1 << " and " << root2 << endl; //Print out the roots
	 
	 	//Validate if the roots obtained are valid solutions to the quadratic equation
	    bool isRoot1Valid = verifyRoot(root1, a, b, c);
	    bool isRoot2Valid = verifyRoot(root2, a, b, c);
	     
	    //Print out the result pf verification
	    cout << "Verification of the two quadratic equation roots ";
	     
	   	if(isRoot1Valid || isRoot2Valid) //If the roots and equation pass the verification
	   	{
	       cout << "PASSES.\n" << endl; //The test success
	   	}
	   	else //If the roots and equation did not pass the verification
	   	{
	       cout << "FAILED.\n" << endl; //The test failed
	   	}

 	}while(1);
 
    return 0;
}
