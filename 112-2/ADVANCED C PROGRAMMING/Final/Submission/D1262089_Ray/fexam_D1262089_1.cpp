#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	int outnum;
	int innum;
	int total;
	
	outnum=0;
	innum=0;
	
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
		for(i=1;i<=thick;i++){
			outnum=outnum+(length-i)*4;
		}
		total=2*(1+2*length-1)*length/2-2*length+1;
		innum=total-outnum;
		
		
		cout <<endl<< "The number of side characters'"<<sChar<<"':"<<outnum<<endl<<endl;
		cout << "The number of interior characters'"<<iChar<<"':"<<innum<<endl<<endl;
		
		cout << "Print the rhombus:"<<endl;
		for(i=1;i<=length;i++){
			if(i>thick){
				cout<<setw(length+6-i)<<setfill(' ')<<""<<setw(thick)<<setfill(sChar)<<""<<setw((i-thick)*2-1)<<setfill(iChar)<<""<<setw(thick)<<setfill(sChar)<<""<<endl;
			}else{			
			    cout<<setw(length+6-i)<<setfill(' ')<<""<<setw(i*2-1)<<setfill(sChar)<<""<<endl;
			}
	    }
		for(i=length-1;i>=1;i--){
			if(i>thick){
				cout<<setw(length+6-i)<<setfill(' ')<<""<<setw(thick)<<setfill(sChar)<<""<<setw((i-thick)*2-1)<<setfill(iChar)<<""<<setw(thick)<<setfill(sChar)<<""<<endl;
			}else{			
			    cout<<setw(length+6-i)<<setfill(' ')<<""<<setw(i*2-1)<<setfill(sChar)<<""<<endl;
			}
	    }						
		
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
