#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	int nums, numi;
	
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
		
		 // (3) Output the number of side characters and the number of interior characters.
		 int bot;
		 int a, b, c;
		 bot = 1 + 2 * (thick - 1);
		 a = (1 + bot) / 2 * thick;
		 b = (length - 1 - thick) * 2 * thick;
		 c = 2 * thick;
		 nums = (a + b) * 2 + c;
		 cout << endl << "The number of side characters" << " '" << sChar << "'" << ": " << nums << endl;
		 
		 bot = 1 + 2 * (length - thick - 2);
		 numi = (1+bot) * (length - 1- thick) + 1 + 2 * (length - 1 - thick);
		 cout << endl << "The number of interior characters" << " '" << iChar << "'" << ": " << numi << endl;
		  
		  
		 /* (4) Print the rhombus to output every row using functions cout <<, setw(), and setfill(), 
		      not to use any loop to print characters of a row. Note that for the first and the last 
		      thick rows, all points are side characters and no interior characters are printed. */
		a = 1;
		for(i=length-1; i>=0; i--){
			setw(6) ;
			if(i<thick){
				cout << setw(length) << " " << setw(i) << setfill(' ') << setw(a) << setfill(sChar);
				a++;
			}
			cout << endl;
			
		}
		      
		 
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
