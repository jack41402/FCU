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
		
		int numSideChars = 0;
		int numInteriorChars = 0;
		

		for(int i = 0 ; i < length ; ++i){
			int width = 2 * i + 1;
			for(int j = 0 ; j < width ; ++j){
				if(j < thick || j >= width - thick || i < thick || i >= length - thick){
					numSideChars++;
				}else{
					numInteriorChars++;
				}
			}
		}
		
		for(int i = length - 2 ; i >= 0 ; --i){
			int width = 2 * i + 1;
			for(int j = 0 ; j < width ; ++j){
				if(j < thick || j >= width - thick || i < thick || i >= length - thick){
					numSideChars++;
				}else{
					numInteriorChars++;
				}
			}
		}
		
			cout << "\nThe number of side characters '" << sChar << "': " << numSideChars << endl;
			cout << "\nThe number of inetrior characters '" << iChar << "': " << numInteriorChars << endl;
			cout << "\nPrint the rhombus: " << endl;
		
		
		for(int i = 0 ; i < length ; ++i){
			cout << setw(6 + length - i - 1) << setfill(' ') << "";
			if(i < thick){
				cout << setw(2 * i + 1) << setfill(sChar) << sChar << endl;
			}else{
				cout << setw(thick) << setfill(sChar) << sChar;
				cout << setw(2 * (i - thick) + 1) << setfill(iChar) << iChar;
				cout << setw(thick) << setfill(sChar) << sChar << endl;
			}
		}
		
			for(int i = length - 2 ; i >= 0 ; --i){
			cout << setw(6 + length - i - 1) << setfill(' ') << "";
			if(i < thick){
				cout << setw(2 * i + 1) << setfill(sChar) << sChar << endl;
			}else{
				cout << setw(thick) << setfill(sChar) << sChar;
				cout << setw(2 * (i - thick) + 1) << setfill(iChar) << iChar;
				cout << setw(thick) << setfill(sChar) << sChar << endl;
			}
		}
		
		
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
