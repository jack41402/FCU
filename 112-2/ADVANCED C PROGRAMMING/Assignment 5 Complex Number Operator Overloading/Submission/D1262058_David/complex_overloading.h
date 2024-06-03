class Complex{
	private:
		double real;
		double imaginary;
		
	public:
		Complex();
		Complex(double, double);
		double getRe();
		double getIm();
		void setRe(double r);
		void setIm(double s);
		double absolute();
		
		Complex operator+(Complex d);
		Complex operator+(double);
		Complex operator-(Complex);
		Complex operator-(double);
		Complex operator*(Complex);
		Complex operator*(double);	
		Complex operator/(Complex);
		Complex operator/(double);		
		bool operator==(Complex);
		bool operator==(double);
		bool operator!=(Complex);
		bool operator!=(double);
		
		friend Complex operator+(double, Complex);
		friend Complex operator-(double, Complex);
		friend Complex operator*(double, Complex);
		friend Complex operator/(double, Complex);
		friend bool operator==(double, Complex);
		friend bool operator!=(double, Complex);
		
		void operator=(Complex);
		void operator=(double);
		void operator+=(Complex);
		void operator+=(double);
		void operator-=(Complex);
		void operator-=(double);
		void operator*=(Complex);
		void operator*=(double);
		void operator/=(Complex);
		void operator/=(double);
};
