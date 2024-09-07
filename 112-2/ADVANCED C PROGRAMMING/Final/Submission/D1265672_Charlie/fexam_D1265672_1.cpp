#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i, p, k; // Loop variable.
	int ns, nt;
	int space = 6;
	
	do {
		ns = 0;
		nt = 5;
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
		// ***** Complete the program to print the rhombus.
		for (i=0; i<thick; i++){
			ns = ns + ((length - i) - 2) * 4 + 4;
		}
		for (i=0; i<length-thick-2; i++){
			nt = nt + (((length-thick) - i) - 2) * 4 + 4;
		}
		cout << "The number of side characters '" << sChar << "': " << ns << endl;
		cout << endl;
		cout << "The number of interior characters '" << iChar << "': " << nt << endl;
		cout << endl;
		
		cout << "Print the rhombus:" << endl;
		p = 1;
		for (i = 0; i < thick; i++){
			cout << setfill(' ') << setw(space+(length-1-i)) << "" << setfill(sChar) << setw(p) << "" <<endl;
			p+=2;
		}
		k = 1;
		for (i = 0; i < length-thick-1; i++){
			cout << setfill(' ') << setw(space+(length-1-thick-i)) << "" << setfill(sChar) << setw(thick) << "";
			cout << setfill(iChar) << setw(k) << "";
			cout << setfill(sChar) << setw(thick) << "" << endl;
			k += 2;
		} 
		cout << setfill(' ') << setw(space) << "" << setfill(sChar) << setw(thick) << "";
		cout << setfill(iChar) << setw(k) << "";
		cout << setfill(sChar) << setw(thick) << "" << endl;
		for (i = 0; i < length-thick-1; i++){
			k -= 2;
			cout << setfill(' ') << setw(space+1+i) << "" << setfill(sChar) << setw(thick) << "";
			cout << setfill(iChar) << setw(k) << "";
			cout << setfill(sChar) << setw(thick) << "" << endl;
		} 
		for (i = 0; i < thick; i++){
			p-=2;
			cout << setfill(' ') << setw(space+(length-thick+i)) << "" << setfill(sChar) << setw(p) << "" <<endl;
		}
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
