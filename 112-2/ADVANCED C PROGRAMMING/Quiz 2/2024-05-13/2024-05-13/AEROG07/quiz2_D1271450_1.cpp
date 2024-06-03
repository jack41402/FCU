#include <iostream>
using namespace std;

class Rectangle {
	// Input/output friend functions. 
	friend istream & operator>>(istream &, Rectangle &); 
	friend ostream & operator<<(ostream &, const Rectangle &); 	
	
	private:
		int height; // Height of a rectangle.
		int width; // Width of a rectangle.

	public:
		Rectangle(int=2, int=2); // Default constructor.
		int perimeter() const; // Compute the perimenter of the rectangle.
		int area() const; // Compute the area of the rectangle.
};

// ***** Complete the default constructor, member functions and friend functions of class Rectangle.

// Default constructor.
// Height and width are between 2 and 20 (including). 
// If not within the valid range, set to the integer value 2.
Rectangle::Rectangle(int h, int w) {
	if(2<=height&&height<=20&&width<=20&&2<=width){
		width=w;
		height=h;
	}
	else{
		 height=2;
		 width=2;
	}
}

// Compute the perimenter of the rectangle.
int Rectangle::perimeter() const {
	return this->(height+width)/2;
}

// Compute the area of the rectangle.
int Rectangle::area() const {
	return this->height*width;
}

// Input friend function. Read two integers separated by a space.
istream & operator>>(istream & input, Rectangle &r) {
	input>>r.height;
	input>>" ";
	input>>r.width;
	return input;
}

// Output friend function.
// Print height, width, perimeter, and area of the rectangle
// and draw the rectangle with 10 leading space on the left-hand-side.
ostream & operator<<(ostream & output, const Rectangle &r) {
	output<<r.height<<r.width<<r.perimeter<<r.area;
		for(int i=0;i<height;++i){
		for(int j=0;j<10;++j){
			cout<<" ";
		}
		cout<<endl;
	}
	return output;
}

// Main function.
// Do not change the main program.
int main() {

	Rectangle r1, r2(5,6), r3; // Declare rectangles r1, r2, and r3.
  
	// Print rectangle r1.
	cout << "Rectangle r1: " << r1;  
	cout << "\n-----------------------------------------\n";
  
	// Print rectangle r2.
	cout << "Rectangle r2: " << r2;
	cout << "\n-----------------------------------------\n";
  
	// Input the height and width of rectangle r3.
	cout << "Enter height and width of r3: ";  
	cin >> r3;  
	cout << endl;
	
	// Print rectangle r3.
	cout << "Rectangle r3: " << r3;
  
  return 0;
}
