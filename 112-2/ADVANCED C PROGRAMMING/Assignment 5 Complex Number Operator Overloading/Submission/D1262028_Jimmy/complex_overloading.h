#include<iostream>
//define the class Complex
class Complex{
	private:
		double r;//real part of the Complex number
		double i;//imaginary part of the Complex number
	public:
		Complex();//set the real and imaginary part to 0
		Complex(double, double);//set the real part and imaginary part
		Complex operator+(Complex);//Complex + Complex
		Complex operator+(double);//Complex + double
		friend Complex operator+(double, Complex);//double + Complex
		Complex operator-(Complex);//Complex - Complex
		Complex operator-(double);//Complex - double
		friend Complex operator-(double, Complex);//double - Complex
		Complex operator*(Complex);//Complex * Complex
		Complex operator*(double);//Complex * double
		friend Complex operator*(double, Complex);//double * Complex
		Complex operator/(Complex);//Complex / Complex
		Complex operator/(double);//Complex / double
		friend Complex operator/(double, Complex);//double / Complex
		double abs();//calculate the absolute value of the Complex number
		double getRe();//to get the real part value
		double getIm();//to get the imaginary part value
		void setRe(double);//define the real part number
		void setIm(double);//define the imaginary part number
		bool operator==(Complex);//to check if two complex number are equal or not
		bool operator==(double);//to check if one double number and a complex number are equal or not
		bool operator!=(Complex);//to check if two complex number aren't equal or not
		bool operator!=(double);//to check if one double number and a complex number aren't equal or not
		void operator=(Complex);//let two complex number equal to each other
		void operator=(double);//let a complex number equal to a double number
		void operator+=(Complex);//two complex number plus another complex number
		void operator+=(double);//a complex number plus a double number
		void operator-=(Complex);//two complex number minus another complex number
		void operator-=(double);//a complex number minus a double number
		void operator*=(Complex);//a complex number times a double number
		void operator*=(double);//a complex number times a double number
		void operator/=(Complex);//a complex number divide a double number
		void operator/=(double);//a complex number divide a double number
}; 
