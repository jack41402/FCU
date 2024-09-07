#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	int count_s; // number of side characters.
	int count_i; // number of interior characters.
	
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
		 
		//(3) Output the number of side characters and the number of interior characters.
		
		count_s = 0;
		count_i = 0;
		
		for (i=1; i<=length; i++) {
			if (thick*2 > i*2-1) {
				count_s += i*2-1;
			}
			else if(thick*2 < i*2-1) {
				count_s += thick*2;
			}
		} 
		
		for (i=length-1; i>=1; i--) {
			if (thick*2 > i*2-1) {
				count_s += i*2-1;
			}
			else if(thick*2 < i*2-1) {
				count_s += thick*2;
			}
		}
		
		count_i = 2*length*length - 2*length + 1 - count_s;
		
		cout << "\nThe number of side characters \'" << sChar << "\' : " << count_s << "\n" << endl;	
		
		cout << "The number of interior characters \'" << iChar << "\' : " << count_i << "\n" << endl;	
		  	
		/*(4) Print the rhombus to output every row using functions cout <<, setw(), and setfill(), 
		      not to use any loop to print characters of a row. Note that for the first and the last 
		      thick rows, all points are side characters and no interior characters are printed. 
		*/ 
		cout << "Print the rhombus:\n";
		for (i=1; i<=length; i++) {
			if (thick*2 > i*2-1) {
				cout << setw(6+length-i) << setfill(' ') << "" << setw(i*2-1) << setfill(sChar) << "" << endl;
			}
			else if(thick*2 < i*2-1) {
				cout << setw(6+length-i) << setfill(' ') << "" << setw(thick) << setfill(sChar) << ""
				<< setw((i*2-1) - (thick*2)) << setfill(iChar) << "" << setw(thick) << setfill(sChar) << "" << endl;
			}
		}
		
		for (i=length-1; i>=1; i--) {
			if (thick*2 > i*2-1) {
				cout << setw(6+length-i) << setfill(' ') << "" << setw(i*2-1) << setfill(sChar) << "" << endl;
			}
			else if(thick*2 < i*2-1) {
				cout << setw(6+length-i) << setfill(' ') << "" << setw(thick) << setfill(sChar) << ""
				<< setw((i*2-1) - (thick*2)) << setfill(iChar) << "" << setw(thick) << setfill(sChar) << "" << endl;
			}
		}
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
