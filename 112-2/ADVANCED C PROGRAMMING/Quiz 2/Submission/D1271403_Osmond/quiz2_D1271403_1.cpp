#include <iostream>

using namespace std;

class Rectangle {
	 
	friend istream & operator>>(istream &, Rectangle &); 
	friend ostream & operator<<(ostream &, const Rectangle &); 	
	
	private:
		int height; 
		int width; 

	public:
		Rectangle(int=2, int=2); 
		int perimeter() const; 
		int area() const; 
};

Rectangle::Rectangle(int h, int w) {
}

int Rectangle::perimeter() const {
}

int Rectangle::area() const {
}

istream & operator>>(istream & input, Rectangle &r) {
}

ostream & operator<<(ostream & output, const Rectangle &r) {
}

int main() {

	Rectangle r1, r2(5,6), r3; 
  
	cout << "Rectangle r1: " << r1;  
	cout << "\n-----------------------------------------\n";
  
	cout << "Rectangle r2: " << r2;
	cout << "\n-----------------------------------------\n";
  
	cout << "Enter height and width of r3: ";  
	cin >> r3;  
	cout << endl;
	
	cout << "Rectangle r3: " << r3;
  
  return 0;
}
