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
	height = h;
	width = w;
}

// Compute the perimenter of the rectangle.
int Rectangle::perimeter() const {
	return (width+height)*2;
}

// Compute the area of the rectangle.
int Rectangle::area() const {
	return width*height;
}

// Input friend function. Read two integers separated by a space.
istream & operator>>(istream & input, Rectangle &r) {
	int v = 1;
	input>>r.height>>r.width;
	while(v){
		if(r.height>20||r.height<2||r.width>20||r.width<2){
			v = 1;
			cout<<"Height and width are between 2 and 20 (including), please input again.\n";
			input>>r.height>>r.width;
		}
		else v=0;
	}
	return input;
}

// Output friend function.
// Print height, width, perimeter, and area of the rectangle
// and draw the rectangle with 10 leading space on the left-hand-side.
ostream & operator<<(ostream & output, const Rectangle &r) {
	int i,k;
	output<<"height "<<r.height<<", width "<<r.width<<", perimeter "<<r.perimeter()<<", area "<<r.area();
	output<<"\n";
	for(i=0;i<r.height;i++){
		output<<"          ";
		for(k=0;k<r.width;k++){
			if(i==0||i==r.height-1){
				output<<'*';
			}
			else{
				if(k==0||k==r.width-1) output<<'*';
				else output<<' ';
			}
		}
		output<<"\n";
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
