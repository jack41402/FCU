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
		int b  = 1;
		// ***** Complete the program to print the rhombus.
		for(i = 0; i < length - (thick + 1); i ++){
			b = b + 2;
		}
		int c = b + 2;
		b = b * 2 + c;
		 // (3) Output the number of side characters and the number of interior characters.
		cout << "The number of the side characters: "<<"'"<<sChar << "'"<<":"<<' '<< thick* 2*(length + (length - 2)) << endl << endl;
		cout << "The number of the interior characters: "<<"'"<<iChar << "'"<<":"<<' '<< b << endl << endl;
		
		cout << "Print out the rhombus:" << endl; 
//		  (4) Print the rhombus to output every row using functions cout <<, setw(), and setfill(), 
//		      not to use any loop to print characters of a row. Note that for the first and the last 
//		      thick rows, all points are side characters and no interior characters are printed. 
		i = 1;
		int a = length * 2 - 1 ;
		int d = 0;
		int e = 0;
		cout << setw(6 + length -1) << setfill(' ')<<"" <<setw(1) <<setfill(sChar)<<""<<endl;
		while(a > 0){
			cout << setw(6 + length -2) << setfill(' ')<<"" <<setw(1) <<setfill(sChar)<<""<< setw(i) << setfill(iChar)<<""<<setw(1)<<setfill(sChar)<<""<<endl;
			length --;
			a--;
			i = i + 2;
			d = i;
			e = a;
		}
		while(a > 0){
			cout << setw(e) << setfill(' ')<<"" <<setw(1) <<setfill(sChar)<<""<< setw(i) << setfill(iChar)<<""<<setw(1)<<setfill(sChar)<<""<<endl;
			length --;
			a--;
			e++;
			d = d - 2;
		}
	
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}