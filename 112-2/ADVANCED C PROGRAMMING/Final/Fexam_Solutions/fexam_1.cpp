#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	
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
		
		// Output the number of side characters. 
		cout << endl << "The number of side characters '" << sChar << "': "
		     << (2*thick*thick+2*thick*(2*(length-thick)-1)) << endl;
		
		// Output the number of interior characters.
		cout << endl << "The number of interior characters '" << iChar << "': "
		     << (2*(length-thick)*(length-thick-1)+1) << endl;
		
		// Print the rhombus to output every row using functions cout <<, setw(), and setfill(), 
		// not to use any loop to print characters of a row. Note that for the first and the last 
		// thick rows, all points are side characters and no interior characters are printed. 	
		cout << endl << "Print the rhombus:" << endl;
		for (i=0; i<length; i++) {
			if (i<thick) {
				cout << setw(6+length-1-i) << setfill(' ') << ""
				     << setw(2*i+1)<< setfill(sChar) << "" << endl;
			}
			else {
				cout << setw(6+length-1-i) << setfill(' ') << "" 
				     << setw(thick)<< setfill(sChar) << "" 
					 << setw((i-thick)*2+1) << setfill(iChar) << ""
				     << setw(thick)<< setfill(sChar) << "" << endl;
			}
		}	
		
		for (i=length-2; i>=0; i--) {
			if (i<thick) {
				cout << setw(6+length-1-i) << setfill(' ') << "" 
				     << setw(2*i+1)<< setfill(sChar) << "" << endl;
			}
			else {
				cout << setw(6+length-1-i) << setfill(' ') << "" 
				     << setw(thick)<< setfill(sChar) << "" 
					 << setw((i-thick)*2+1) << setfill(iChar) << ""
				     << setw(thick)<< setfill(sChar) << "" << endl;
			} 
			
		}
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
