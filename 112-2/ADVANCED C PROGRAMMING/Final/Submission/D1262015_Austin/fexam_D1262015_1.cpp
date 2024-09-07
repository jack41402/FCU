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
		cout << "The number of side characters " <<"'"<< sChar <<"':";
		cout << (2*length-1-2*thick)*2*thick + thick*thick*2 << endl;
		
		cout <<"\nThe number of interior characters "<<"'"<< iChar <<"':";
		cout <<((length-thick)*(length-thick) + (length-thick-1)*(length-thick-1)) << endl;
		
		for (i==0;i<=thick;i++){
			cout << setw(length+6-i+1) << setfill(' ') << " " ;
			cout << setw(i*2+1-1) << setfill(sChar) << "\n" ;
		}
		i = 0;
		for (i==0;i<=(length-thick-1);i++){
			cout << setw(length+6-i-thick) << setfill(' ') << "" ;
			cout << setw(thick) << setfill(sChar) << "";
			cout << setw(2*i+1) << setfill(iChar) << "" ;
			cout << setw(thick) << setfill(sChar) << "" ;
			cout << endl;
		}
		i=1;
		for (i==1;i<=(length-thick-1);i++){
			cout << setw(6+i+1) << setfill(' ') << " " ;
			cout << setw(thick) << setfill(sChar) << "";
			cout << setw(2*(length-thick-i)-1) << setfill(iChar) << "" ;
			cout << setw(thick) << setfill(sChar) << "" ;
			cout << endl;
		}
		i = 0;
		for (i==0;i<=thick;i++){
			cout << setw(length+6+i+1-thick) << setfill(' ') << " " ;
			cout << setw(thick*2-i*2) << setfill(sChar) << "\n" ;
		}
		i=0;
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
