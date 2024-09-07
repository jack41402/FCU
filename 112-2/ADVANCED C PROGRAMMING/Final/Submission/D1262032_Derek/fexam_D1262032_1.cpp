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
		
		int a=0, b=0;
		for(i=0;i<thick;i++){
			a+=length-i+(length-1-i)*2+length-2-i;
		}
		cout<<endl<<"The number of side characters '"<<sChar<<"': "<<a;
		for(i=0;i<length-thick;i++){
			b+=length-thick-i+(length-thick-1-i)*2+length-thick-2-i;
		}
		b++;
		cout<<endl<<endl<<"The number of interior characters '"<<iChar<<"': "<<b;
		cout<<endl<<endl<<"Print the rhombus:"<<endl;
		for(i=0;i<thick;i++){
			cout<<setw(6+length-i)<<setfill(' ')<<" "<<setw(2*i+1)<<setfill(sChar)<<sChar<<endl;
		}
		for(i=0;i<length-thick;i++){
			cout<<setw(6+length-thick-i)<<setfill(' ')<<" "<<setw(thick)<<setfill(sChar)<<sChar<<setw(2*i+1)<<setfill(iChar)<<iChar<<setw(thick)<<setfill(sChar)<<sChar<<endl;
		}
		for(i=length-thick;i>=0;i--){
			cout<<setw(6+length-thick-i)<<setfill(' ')<<" "<<setw(thick)<<setfill(sChar)<<sChar<<setw(2*i+1)<<setfill(iChar)<<iChar<<setw(thick)<<setfill(sChar)<<sChar<<endl;
		}

		for(i=thick-1;i>=0;i--){
			cout<<setw(6+length-i)<<setfill(' ')<<" "<<setw(2*i+1)<<setfill(sChar)<<sChar<<endl;
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
