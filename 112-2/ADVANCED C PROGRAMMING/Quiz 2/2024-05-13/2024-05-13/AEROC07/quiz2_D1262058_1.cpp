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
	if(h>=20||h<=2){
		h = 2;
	}
	if(w>=20||w<=2){
		w = 2;
	}
}

// Compute the perimenter of the rectangle.
int Rectangle::perimeter() const {
	int p = (height + width) *2;
	return p;
}

// Compute the area of the rectangle.
int Rectangle::area() const {
	int a = height * width;
	return a;
}

//Input friend function. Read two integers separated by a space.
istream & operator>>(istream & input, Rectangle &r) {
	input>>r;
}

// Output friend function.
// Print height, width, perimeter, and area of the rectangle
// and draw the rectangle with 10 leading space on the left-hand-side.
ostream & operator<<(ostream & output, const Rectangle &r) {
	output<<r;
}

// Main function.
// Do not change the main program.
int main() {
	int i, j;

	Rectangle r1, r2(5,6), r3; // Declare rectangles r1, r2, and r3.
  
	// Print rectangle r1.
	cout << "Rectangle r1: " << r1;  
	cout << "\n-----------------------------------------\n";
	for(i=0; i<r1.height; i++){
		printf("          ");
		if(i = 0 || i == r1.height-1){
			for(j=0; j<r1.width; j++){
				printf("*");
			}
			printf"\n"	
		}
		else{
			printf("*")
			for(i=0; i<r1.height-3; i++){
				printf(" ");
			}
			printf("*\n");	
		} 
	}
  
	// Print rectangle r2.
	cout << "Rectangle r2: " << r2;
	cout << "\n-----------------------------------------\n";
	for(i=0; i<r1.height; i++){
		printf("          ");
		if(i = 0 || i == r1.height-1){
			for(j=0; j<r1.width; j++){
				printf("*");
			}
			printf"\n"	
		}
		else{
			printf("*")
			for(i=0; i<r1.height-3; i++){
				printf(" ");
			}
			printf("*\n");	
		} 
	}
  
	// Input the height and width of rectangle r3.
	cout << "Enter height and width of r3: ";  
	cin >> r3; 
	cout << endl;
	
	// Print rectangle r3.
	cout << "Rectangle r3: " << r3;
	for(i=0; i<r1.height; i++){
		printf("          ");
		if(i = 0 || i == r1.height-1){
			for(j=0; j<r1.width; j++){
				printf("*");
			}
			printf"\n"	
		}
		else{
			printf("*")
			for(i=0; i<r1.height-3; i++){
				printf(" ");
			}
			printf("*\n");	
		} 
	}
  
  return 0;
}
