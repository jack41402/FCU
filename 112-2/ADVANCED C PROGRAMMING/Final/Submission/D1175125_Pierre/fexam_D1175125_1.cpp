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
		
		// ***** Complete the program to print the rhombus.
		/* 
		  (3) Output the number of side characters and the number of interior characters.
		  
		
		  (4) Print the rhombus to output every row using functions cout <<, setw(), and setfill(), 
		      not to use any loop to print characters of a row. Note that for the first and the last 
		      thick rows, all points are side characters and no interior characters are printed. 
		*/ 
		cout<<endl;
		int n = length;
		int sideChars = 0;
		int interiorChars = 0;
		for(int i = 0; i < n; ++i){
			int width = 2*i+1;
			for (int j = 0; j < width;++j){				
				if(j<thick || j>=width-thick || i< thick){
					sideChars++;
				}else{
					interiorChars++;			
				}
			}
		}
		for(int i = n - 2; i >= 0; --i){
			int width = 2*i+1;
			for (int j = 0; j < width;++j){				
				if(j<thick || j>=width-thick || i< thick){
					sideChars++;
				}else{
					interiorChars++;
				}
			}
		}
		cout << "The number of side characters '"<<sChar<<"': " <<sideChars <<endl<<endl;
		cout << "The number of interior characters '"<<iChar<<"': "<<interiorChars <<endl<<endl;
	
		for(int i = 0; i < n; ++i){
			for(int j = 0; j<n-i-1; ++j){
				cout << ' ';
			}
			for(int j = 0; j<2*i+1; ++j){
				if (j<thick || j >= 2*i+1 - thick || i < thick || i < thick){
					cout << sChar;
				}else{
					cout << iChar;
				}
			}
			cout << endl;
		}
		for(int i = n - 2; i >= 0; --i){
			for(int j = 0; j<n-i-1; ++j){
				cout << ' ';
			}
			for(int j = 0; j<2*i+1; ++j){
				if (j<thick || j >= 2*i+1 - thick || i < thick || i < thick){
					cout << sChar;
				}else{
					cout << iChar;
				}
			}
			cout << endl;
		}
		
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
