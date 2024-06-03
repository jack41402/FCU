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
		friend Complex operator+(double, Complex);
		Complex operator-(Complex);
		Complex operator-(double);
		friend Complex operator-(double, Complex);
		Complex operator*(Complex);
		Complex operator*(double);
		friend Complex operator*(double, Complex);
		Complex operator/(Complex);
		Complex operator/(double);
		friend Complex operator/(double, Complex);
		bool operator==(Complex);
		bool operator==(double);
		friend bool operator==(double, Complex);
		bool operator!=(Complex);
		bool operator!=(double);
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
