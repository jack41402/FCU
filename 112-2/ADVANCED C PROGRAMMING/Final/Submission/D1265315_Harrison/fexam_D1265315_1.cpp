#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	int s;
	int side = 0;
	int hmr;
	int in,inter;
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
		
		for(i=0;i<thick;i++){
			s = length*4-4-i*4;
			side = side+s;
		}
		
		hmr = (length*2-1-thick*2-1)/2;
		
		for(i=0;i<=hmr;i++){
			in = i*4;
			inter = inter+in+1;
		}
		
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
		
		printf("\nThe number of side characters '%c' :%d\n\n",sChar,side); 
		printf("The number of interior characters '%c' :%d\n\n",iChar,inter+1);
		printf("Print the rhombus:\n");
		for(i=0;i<=length;i++){ 
		cout<<setw(hmr+thick+6+1-i) << setfill(' ') <<" ";
		if(i<thick){
			cout<<setw(2+i*2) << setfill(sChar)<<" ";
			printf("\n");
		}
		else{
		cout<<setw(thick+1) << setfill(sChar)<<" "<<setw(2+2*i-thick)<<setfill(iChar)<<" "<<setw(thick+1) << setfill(sChar)<<" ";
		printf("\n");
	}
}
		for(i=0;i<length-1;i++){
			cout<<setw(6+1+i) << setfill(' ') <<" ";
		if(i>length-thick){
			cout<<setw(length-i) << setfill(sChar)<<" ";
			printf("\n");
		}
		else{
		cout<<setw(thick+1) << setfill(sChar)<<" "<<setw(length*2-i*2-thick*2+1)<<setfill(iChar)<<" "<<setw(thick+1) << setfill(sChar)<<" ";
		printf("\n");
		}
	}
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
