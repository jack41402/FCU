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
		
		cout << endl;
		
		cout<<"The number of side characters'"<<sChar<<"': " << (2*thick*(length-thick))*2-2*thick+2+2*(2*(thick-1)+2);
		cout<<endl<<endl;
		
		cout<<"The number of interior characters'"<<iChar<<"': "<<endl<<endl;
		
		
		// ***** Complete the program to print the rhombus.
		/* 
		  (3) Output the number of side characters and the number of interior characters.
		  
		  (4) Print the rhombus to output every row using functions cout <<, setw(), and setfill(), 
		      not to use any loop to print characters of a row. Note that for the first and the last 
		      thick rows, all points are side characters and no interior characters are printed. 
		*/ 
		
		cout<< "Print the rhombus:"<<endl;
		
		cout << setw(5+length+thick-1) << setfill(' ')<<"";
		cout<< setw(1) <<setfill(sChar) <<""<<endl;
		
		
		if(thick>1){
			
			for(i =0;i<thick-1;++i)
			{
				cout << setw(5+thick-1) << setfill(' ')<<"";
				
				cout << setw(length-1-i) << setfill(' ')<<"";
				
				cout<<setw(thick+2*i) << setfill(sChar)<<"";
				
				cout<<endl;
			}
		}
		
		for(i=0;i<length-thick;++i){
			
			cout << setw(5) << setfill(' ')<<"";
			
			cout << setw(length-1-i) << setfill(' ')<<"";
				
			cout<< setw(thick) << setfill(sChar)<<"";
				
			cout<<setw(2*(i+1)-1) << setfill(iChar)<<"";
				
			cout<<setw(thick) << setfill(sChar)<<"";
				
			cout << endl;
		}
		
		
		for(i=0;i<length-1-thick;++i)
		{
			cout << setw(5) << setfill(' ')<<"";
			
			cout << setw(length-(length-thick-1)+i) << setfill(' ')<<"";
			
			cout<< setw(thick) << setfill(sChar)<<"";
			
			cout<<setw(2*(length-thick)-1-(2*i)-2) << setfill(iChar)<<"";
			
			cout<< setw(thick) << setfill(sChar)<<"";
			
			cout << endl;
		}
		
		
		if(thick>1){
			
			for(i =0;i<thick-1;++i)
			{
				cout << setw(5) << setfill(' ')<<"";
				
				cout << setw(length+i) << setfill(' ')<<"";
				
				cout<<setw(thick+2-2*i) << setfill(sChar)<<"";
				
				cout<<endl;
			}
		}
		
		
		cout << setw(5+length+thick-1) << setfill(' ')<<"";
		cout<< setw(1) <<setfill(sChar) <<""<<endl;
		
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
