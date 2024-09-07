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
		int sSum = 0;
		for(i=1;i<=thick;i++){
			sSum = sSum + (length-i)*4;
		}
		cout << "\nThe number of side characters '" << sChar << "': " << sSum << "\n" << endl;
		
		int iSum = 0;
		iSum = (length-thick)*(length-thick) + (length-thick-1)*(length-thick-1);
		cout << "The number of interior characters '" << iChar << "': " << iSum << "\n" << endl;
		
		//print top triangle
		cout << "Print the rhombus:" << endl;
		for(i=1;i<=thick;i++){
			cout << setw(5) << setfill(' ') << " " << setw(length-i+thick) << setfill(' ') << " " << setw(2+(i-1)*2) << setfill(sChar) << " " << endl;
		}
		
		//print upper body
		for(i=0;i<length-thick;i++){
			cout << setw(5) << setfill(' ') << " " << setw(length-i-1) << setfill(' ') << " " << setw(thick) << setfill(sChar) << sChar << setw(1+i*2) << setfill(iChar) << iChar << setw(thick) << setfill(sChar) << sChar << endl;
		}	
			
		//print lower body
		for(i=0;i<length-thick-1;i++){
			cout << setw(6) << setfill(' ') << " " << setw(i+1) << setfill(' ') << " " << setw(thick) << setfill(sChar) << sChar << setw((length-i-thick)*2+1) << setfill(iChar) << iChar << setw(thick) << setfill(sChar) << sChar << " " << endl;
 		}
 		
		 //print botoom triangle
 		for(i=thick;i>0;i--){
 			cout << setw(5) << setfill(' ') << " " << setw(length-i) << setfill(' ') << " " << setw(1+(i-1)*2) << setfill(sChar) << sChar << " " << endl; 
 		 }
		cout << endl<< "----------------------------------------------" << endl;
		
		
	} while (true);
  
	return 0;
}
