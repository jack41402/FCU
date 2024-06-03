using namespace std; // Use the standard namespace

#ifndef complex
#define complex 

class Complex{
	
	friend ostream &operator<<(ostream &, const Complex &); // Declare the friend function for output stream
    friend istream &operator>>(istream &, Complex &); // Declare the friend function for input stream
	friend Complex operator+(const double &, const Complex &); // Declare friend addition operator for double and Complex
	friend Complex operator-(const double &, const Complex &); // Declare friend subtraction operator for double and Complex
	friend Complex operator*(const double &, const Complex &); // Declare friend multiplication operator for double and Complex
	friend Complex operator/(const double &, const Complex &); // Declare friend division operator for double and Complex
	friend bool operator==(const double &, const Complex &); // Declare friend equality operator for double and Complex
    friend bool operator!=(const double &, const Complex &); // Declare friend inequality operator for double and Complex
	
	private:
		double Re; // Real part of the complex number
		double Im; // Imaginary part of the complex number
	public:
		Complex operator+(const Complex &) const; // Overload addition operator for Complex objects
	    Complex operator+(const double &) const; // Overload addition operator for Complex and double
	    Complex operator-(const Complex &) const; // Overload subtraction operator for Complex objects
	    Complex operator-(const double &) const; // Overload subtraction operator for Complex and double
	    Complex operator*(const Complex &) const; // Overload multiplication operator for Complex objects
	    Complex operator*(const double &) const; // Overload multiplication operator for Complex and double
	    Complex operator/(const Complex &) const; // Overload division operator for Complex objects
	    Complex operator/(const double &) const; // Overload division operator for Complex and double
	    bool operator==(const Complex &) const; // Overload equality operator for Complex objects
	    bool operator==(const double &) const; // Overload equality operator for Complex and double
	    bool operator!=(const Complex &) const; // Overload inequality operator for Complex objects
	    bool operator!=(const double &) const; // Overload inequality operator for Complex and double
	    Complex& operator+=(const Complex &); // Overload compound addition operator for Complex objects
	    Complex& operator+=(const double &); // Overload compound addition operator for Complex and double
	    Complex& operator-=(const Complex &); // Overload compound subtraction operator for Complex objects
	    Complex& operator-=(const double &); // Overload compound subtraction operator for Complex and double
	    Complex& operator*=(const Complex &); // Overload compound multiplication operator for Complex objects
	    Complex& operator*=(const double &); // Overload compound multiplication operator for Complex and double
	    Complex& operator/=(const Complex &); // Overload compound division operator for Complex objects
	    Complex& operator/=(const double &); // Overload compound division operator for Complex and double
	    
		Complex(); // Default constructor
		Complex(const Complex &); // Copy constructor
		double getRe(void) const; // Getter function for the real part
		double getIm(void) const; // Getter function for the imaginary part
		void setRe(double); // Setter function for the real part
		void setIm(double); // Setter function for the imaginary part
		
		double abs(void) const; // Method to calculate the absolute value of the complex number
};

#endif  
