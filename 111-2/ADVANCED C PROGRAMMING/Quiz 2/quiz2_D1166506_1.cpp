#include <iostream>
#include <cstdlib> 
using namespace std; 

class Celsius {
/****
    Define and implement a temperature class Celsius. In class  Celsius, define 
	(1) double private data member degree, 
	(2) a default constructor with a double parameter of initial value 0.0, 
	(3) a public member function double toFahrenheit() const converting a Celsius degree to a double 
	    Fahrenheit degree, and 
	(4) two friend functions for istream and ostream for inputting and outputting a Celsius degree.
****/
	friend istream& operator>>(istream& , Celsius&) ;
	friend ostream& operator<<(ostream& , const Celsius&) ;

	public :
		double toFahrenheit(const Celsius) const ;
		Celsius() ;

	private :
		double degree ;
		
};

Celsius::Celsius()
{
	degree = 0.0 ;
}

istream& operator>>(istream &input , Celsius &celsius)
{
	double temp ;
	input >> temp ;
	celsius.degree = temp ;
	return input;
}

ostream& operator<<(ostream &output , const Celsius &celsius)
{
	output << celsius.degree ;
	return output;
}

double Celsius::toFahrenheit (const Celsius celsius) const
{
	return (celsius.degree*9.0/5.0)+32.0;
}

int main()
{	
/****
     In the main program, declare a Celsius variable without parameter 
	 and write only cout and cin statements to generate the text contents 
	 as the following program execution example.
	     Enter a Celsius degree: 100.0
         **** Celsius 100 degrees equals to Fahrenheit 212 degrees.
****/ 
	Celsius c;
	cout << "Enter a Celsius degree: " ;
	cin >> c ;
	cout << "**** Celsius " << c << " degrees equals to Fahrenheit " << c.toFahrenheit(c) << " degrees.\n" ;
}
