#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	int j;
	int side_c = 0;
	int interior_c = 0;
	int sum = 0;
	int k;

	
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
		
		side_c = 0;
		interior_c = 0;
		j = 0;
		k = 0;
		
		cout << "Enter the side character: ";
		cin >> sChar;
		
		cout << "Enter the interior character: ";
		cin >> iChar;
		
		for(i=0; i<thick; i++){
			side_c = side_c + 1+ 2*i;
		}

		side_c = ((((length-thick-1)*2+1)*thick) +side_c)*2;
		
		cout << "\nThe number of side charaters " << sChar << " : " << side_c<< endl;
		
		
		for(i=0; i<length-thick; i++){
			interior_c = interior_c + 1+ 2*i;
		}
		for(i=0; i<length-thick-1; i++){
			interior_c = interior_c + 1+ 2*i;
		}
		
		cout << "\nThe number of interior charaters " << iChar << " : " << interior_c<< endl;
		
		cout << "\nPrint the rhombus: \n";
		
		j=2;
		for(i=10+thick; i>10; i--){
			cout << setw(i+length-thick-1) << " " << setfill(sChar);
			cout << setw(j) << " " << setfill(' ') << endl;
			j=j+2;
			}
			
		k=2;
		for(i=10+length-thick-1; i>10; i--){
			cout << setw(i) << " " << setfill(sChar);
			cout << setw(thick) << sChar <<setfill(iChar);

			cout << setw(k) << sChar << setfill(sChar) ;
			cout << setw(thick) << " " << setfill(' ')<< endl;
			
			k=k+2;
		}
		
		for(i=10; i<10+length-thick; i++){
			cout << setw(i) << " " << setfill(sChar);
			cout << setw(thick) << sChar <<setfill(iChar);
			
			cout << setw(k) << sChar << setfill(sChar) ;
			cout << setw(thick) << " " << setfill(' ')<< endl;
			k=k-2;
		}
		
		j=j-2;
		for(i=10; i<10+thick; i++){
			cout << setw(i+length-thick) << " " << setfill(sChar);
			cout << setw(j) << " " << setfill(' ') << endl;
			j=j-2;
		}
		
			
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
