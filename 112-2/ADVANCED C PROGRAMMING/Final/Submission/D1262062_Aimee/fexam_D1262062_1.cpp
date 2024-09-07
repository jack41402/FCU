#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	int side, interior;
	
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
		cout << endl;
		side = 0;
		interior = 2*length*length - 6*length + 5;
		for(i=1; i<=thick; i++) side += (4*length - 4*i);
		if(thick>=2){
			for(i=2; i<=thick; i++) interior -= (4*length - 4*i);
		}
		cout << "The number of side characters '" << sChar << "': " << side << endl << endl;
		cout << "The number of interior characters '" << iChar << "': " << interior << endl << endl;
		cout << "Print the rhombus:" << endl;
		cout << setw(6+length-1) << setfill(' ') << "" << sChar << endl;
		if(thick == 1){
			for(i=2; i<=length; i++) {
				cout << setw(6+length-i) << setfill(' ') << "" << sChar << "" << setw(2*(i-1)-1) << setfill(iChar) << "" << sChar << endl;
			}
			for(i=length-1; i>1; i--) {
				cout << setw(6+length-i) << setfill(' ') << "" << sChar << "" << setw(2*(i-1)-1) << setfill(iChar) << "" << sChar << endl;
			}
		}
		else{
			for(i=2; i<=length; i++) {
				if(i <= thick) cout << setw(6+length-i) << setfill(' ') << "" << setw(2*(i-1)+1) << setfill(sChar) << endl;
				else cout << setw(6+length-i) << setfill(' ') << "" << setw(thick) << setfill(sChar) << "" << setw(2*(i-thick)-1) << setfill(iChar) << "" << setw(thick) << setfill(sChar) << endl;
			}
			for(i=length-1; i>1; i--) {
				if(i-thick <= 0) cout << setw(6+length-i) << setfill(' ') << "" << setw(2*(i-1)+1) << setfill(sChar) << endl;
				else cout << setw(6+length-i) << setfill(' ') << "" << setw(thick) << setfill(sChar) << "" << setw(2*(i-thick)-1) << setfill(iChar) << "" << setw(thick) << setfill(sChar) << endl;
			}
		}
		cout << setw(6+length-1) << setfill(' ') << "" << sChar << endl;
		// ***** Complete the program to print the rhombus.
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
