#include<iostream>
#include <iomanip>
using namespace std;

class Complex{
	public:
		Complex();
		Complex(Complex &a);	
		double getRe();
		double getIm();
		void setRe(double r);
		void setIm(double s);
        double absComplex();
		friend Complex operator+(Complex &c1, Complex &c2);
		friend Complex operator+(double &d, Complex &c);
		friend Complex operator+(Complex &c, double &d);
		friend Complex operator-(Complex &c1, Complex &c2);
		friend Complex operator-(double &d, Complex &c);
		friend Complex operator-(Complex &c, double &d);
		friend Complex operator*(Complex &c1, Complex &c2);
		friend Complex operator*(double &D, Complex &C);
		friend Complex operator*(Complex &C, double &D);
		friend Complex operator/(Complex &c1, Complex &c2);
		friend Complex operator/(double &D, Complex &C);
		friend Complex operator/(Complex &C, double &D);
		friend bool operator==(Complex &c1, Complex &c2);
		friend bool operator==(double &D, Complex &C);
		friend bool operator==(Complex &C, double &D);
		friend bool operator!=(Complex &c1, Complex &c2);
		friend bool operator!=(double &D, Complex &C);
		friend bool operator!=(Complex &C, double &D);
		Complex operator=(const Complex &c);
		Complex operator=(const double &d);
		void operator+=(Complex &c);
		void operator+=(double &d);
		void operator-=(Complex &c);
		void operator-=(double &d);
		void operator*=(Complex &C);
		void operator*=(double &D);
		void operator/=(Complex &C);
		void operator/=(double &D);
		friend ostream& operator<<(ostream &os, Complex &c);
		friend istream& operator>>(istream &is, Complex &c);
		Complex operator-();
		
	private:
		double re;
		double im;
};
