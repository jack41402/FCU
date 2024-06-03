#include <iostream>
using namespace std;

class Complex{
	private:
		double re; // real part
  		double im; // image part
	public:
		Complex();
    	Complex(double re, double im);
		double getRe();
		double getIm();
		void setRe(double re);
		void setIm(double im);
		
		Complex operator-();//unary operator
		Complex operator+(const Complex &c);//Complex 
		Complex operator-(const Complex &c);
		Complex operator*(const Complex &c);
		Complex operator/(const Complex &c);
		bool operator==(const Complex &c);
		bool operator!=(const Complex &c);
		
		friend Complex operator+(const Complex &c,const double d); //Complex+double
		friend Complex operator-(const Complex &c,const double d);
		friend Complex operator*(const Complex &c,const double d);
		friend Complex operator/(const Complex &c,const double d);
		friend bool operator==(const Complex &c,const double d);
		friend bool operator!=(const Complex &c,const double d);		
		
		friend Complex operator+(const double d,const Complex &c);//double + Complex 
		friend Complex operator-(const double d,const Complex &c);
		friend Complex operator*(const double d,const Complex &c);
		friend Complex operator/(const double d,const Complex &c);
		friend bool operator==(const double d,const Complex &c);
		friend bool operator!=(const double d,const Complex &c);
		
		double abs();
		double square();
		Complex& operator=(const Complex &c);
		Complex& operator+=(const Complex &c);
		Complex& operator-=(const Complex &c);
		Complex& operator*=(const Complex &c);
		Complex& operator/=(const Complex &c);
		
		friend ostream& operator<<(ostream &out, const Complex &c);
    	friend istream& operator>>(istream &in,  Complex &c);
		friend ostream& operator<<(ostream &out, double d);
    	friend istream& operator>>(istream &in,  double d);
};
