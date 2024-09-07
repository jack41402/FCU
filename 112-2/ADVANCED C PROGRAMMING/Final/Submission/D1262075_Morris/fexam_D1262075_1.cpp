#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	int side, outer, inner;
	
	do {
		// Input the side of a rhombus.
		do {
			cout << "Enter the side of a rhombus (6 to 30): ";
			cin >> length;
		} while (length<6 || length>30);
		
		// Input the thickness of the sides of a rhombus.
		do {
			cout << "Enter the thickness of the sides of a rhombus (0 to 6): ";
			cin >> thick; 
		} while (thick<0 || thick>6 || thick>length/2);
		
		if (thick==0) return 0; // Program terminates if thick is 0.
		
		cout << "Enter the side character: ";
		cin >> sChar;
		
		cout << "Enter the interior character: ";
		cin >> iChar;
		
		// ***** Complete the program to print the rhombus.
		side = length * 2 -1;
		
		inner = ((side - thick * 2) * (side - thick * 2) + 1)/2;
		
		outer = (side * side + 1) / 2 -inner;
		
		cout << endl << "The number of side characters " << "'" << sChar << "'" << ": " << outer << endl << endl; 
		cout << "The number of interior characters " << "'" << iChar << "'" << ": " << inner << endl << endl;
		for(i=0;i<thick;i++){
			cout << setw(length - i) << setfill(' ') << "" << setw(1+2*i) << setfill(sChar) << "" << endl;
		}
		for(i=thick;i<length;i++){
			cout << setw(length - i) << setfill(' ') << "" << setw(thick) << setfill(sChar) << "" << setw(2*i-2*thick+1) << setfill(iChar) << "" << setw(thick) << setfill(sChar) << "" << endl;
		}
		for(i=length-1;i>thick;i--){
			cout << setw(length - i + 1) << setfill(' ') << "" << setw(thick) << setfill(sChar) << "" << setw(2*i-2*thick-1) << setfill(iChar) << "" << setw(thick) << setfill(sChar) << "" << endl;
		} 
		for(i=thick;i>0;i--){
			cout << setw(length-i+1) << setfill(' ') << "" << setw(2*i-1) << setfill(sChar) << "" << endl;
		}
		//cout << setw(6) << setfill(sChar) << setw(5 << setfill(iChar) << " ";
		/* 
		  (3) Output the number of side characters and the number of interior characters.
		  
		  (4) Print the rhombus to output every row using functions cout <<, setw(), and setfill(), 
		      not to use any loop to print characters of a row. Note that for the first and the last 
		      thick rows, all points are side characters and no interior characters are printed. 
		*/ 
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
