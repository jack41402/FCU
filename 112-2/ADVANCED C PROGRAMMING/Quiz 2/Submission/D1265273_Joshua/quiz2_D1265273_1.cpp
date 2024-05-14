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
	if (2<=h && h<=20 && 2<=w && w<=20){
		height = h;
		width = w;
	}
	else if ( w<2 || 20<w){
		width = 2;
	}
	else if ( h<2 || 20<h){
		height = 2;
	}
	else{
		height = 2;
		width = 2;
	}
}

// Compute the perimenter of the rectangle.
int Rectangle::perimeter() const {
	return height*2+width*2;
}

// Compute the area of the rectangle.
int Rectangle::area() const {
	return height*width;
}

// Input friend function. Read two integers separated by a space.
istream & operator>>(istream & input, Rectangle &r) {
	cin>>r.height>>r.width;
	return input; 
}

// Output friend function.
// Print height, width, perimeter, and area of the rectangle
// and draw the rectangle with 10 leading space on the left-hand-side.
ostream & operator<<(ostream & output, const Rectangle &r) {
	int i, j;
	cout<<"height "<<r.height<<", "<<"width "<<r.width<<", "<<"perimeter "<<r.perimeter()<<", "<<"area "<<r.area();
	cout<<"\n"<<"          ";
	for (i = 0; i<r.width; i++){
		cout<<"*";
	}
	cout<<"\n";
	for (i = 0; i<r.height - 2; i++){
		cout<<"          "<<"*";
		for (j = 0; j<r.width-2; j++){
			cout<<" ";
		}
		cout<<"*"<<"\n";
	}
	cout<<"          ";
	for (i = 0; i<r.width; i++){
		cout<<"*";
	}
	cout<<"\n";
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
