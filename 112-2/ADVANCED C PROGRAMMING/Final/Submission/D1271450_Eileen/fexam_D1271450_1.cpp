#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i,j,b,c,d; // Loop variable.
	
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
		cout<<"\nThe number of side characters '"<<sChar<<"' : ";
		if(thick=1){
			b=length*4-4;
		}
		else if(thick=2){
			b=((length-1)*4-4)+(length*4-4);
		}
		else if(thick=3){
			b=((length-2)*4-4)+((length-1)*4-4)+(length*4-4);
		}
		else if(thick=4){
			b=((length-3)*4-4)+((length-2)*4-4)+((length-1)*4-4)+(length*4-4);
		}
		else if(thick=5){
			b=((length-4)*4-4)+((length-3)*4-4)+((length-2)*4-4)+((length-1)*4-4)+(length*4-4);
		}
		else{
			b=((length-5)*4-4)+((length-4)*4-4)+((length-3)*4-4)+((length-2)*4-4)+((length-1)*4-4)+(length*4-4);
		}
		cout<<b; 
		c=(length+thick)*2-1;
		cout<<"\n\nThe number of interior characters: '"<<iChar<<"' : ";
		for(i=1;i<length-thick;++i){
			d=c+(c-2*i)*2;
		}
		cout<<d;
		cout<<"\n\nPrint the Rhombus:"<<endl;
		cout<<setw(6+length-1)<<setfill(' ')<<""<<sChar<<endl;
		for(i=2;i<=thick;++i){
			cout<<setw(length-i+6)<<setfill(' ')<<""<<setw(1+2*(i-1))<<setfill(sChar)<<sChar<<endl;
		}
		for(i=thick;i<=length-1;++i){
			cout<<setw(6+length-i-1)<<setfill(' ')<<""<<setw(thick)<<setfill(sChar)<<sChar<<setw(1+(i-thick)*2)<<setfill(iChar)<<iChar<<sChar<<endl;
		}
		for(i=length+1;i<=length*2-2-thick+1;++i){
			cout<<setw(6+i-length)<<setfill(' ')<<""<<setw(thick)<<setfill(sChar)<<sChar<<setw(1+(length-1-thick)*2-(i-length)*2)<<setfill(iChar)<<iChar<<sChar<<endl;
		}
		//for(i=length*2-2-thick;i<=length*2-2;++i){
			//cout<<setw(length-thick+6+(i-length*2-2-thick)+5)<<setfill(' ')<<""<<setw(1+2*(thick-1)-(i-length*2-2-thick)*2)<<setfill(sChar)<<sChar<<endl;
	//	}
		cout<<setw(6+length-1)<<setfill(' ')<<""<<sChar<<endl;
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
