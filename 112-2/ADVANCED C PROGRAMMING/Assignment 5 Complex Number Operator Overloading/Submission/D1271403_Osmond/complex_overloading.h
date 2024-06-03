using namespace std;

class Complex{
	
	friend ostream& operator <<(ostream& , const Complex& );
	friend istream& operator >>(istream& , Complex& );
	friend Complex operator +(const double&, const Complex&);
	friend Complex operator -(const double&, const Complex&);
	friend Complex operator *(const double&, const Complex&);
	friend Complex operator /(const double&, const Complex&);
	friend bool operator ==(const double&, const Complex&);
	friend bool operator !=(const double&, const Complex&);
	
	public:
		
		Complex(double=0.0, double=0.0);
		Complex(const Complex&);
		
		Complex operator +(const double&);
		Complex operator +(const Complex&);
		
		Complex operator -(const double&);
		Complex operator -(const Complex&);
		
		Complex operator *(const double&);
		Complex operator *(const Complex&);
		
		Complex operator /(const double&);
		Complex operator /(const Complex&);
		
		bool operator ==(const double&);
		bool operator ==(const Complex&);
		
		bool operator !=(const double&);
		bool operator !=(const Complex&);
		
		Complex& operator =(const double&);
		Complex& operator =(const Complex&);
		
		Complex& operator +=(const double&);
		Complex& operator +=(const Complex&);
		
		Complex& operator -=(const double&);
		Complex& operator -=(const Complex&);	
		
		Complex& operator *=(const double&);
		Complex& operator *=(const Complex&);
		
		Complex& operator /=(const double&);
		Complex& operator /=(const Complex&);
		
		double getRe();
		double getIm();
		void setRe(const double& );
		void setIm(const double& );
		double cabs();
	private:
		
		double real;
		double image;	
		
};
