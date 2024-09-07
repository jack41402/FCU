#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	char space=' ';
	int i; // Loop variable.
	int Scount=0;
	int Icount=0;
	
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
		
		for(i=0; i<thick; i++){
			Scount+=4*(length-2-i);
		}
		Scount+=4*thick;
		
		cout<<"The number of side characters \'"<<sChar<<"\':"<<Scount<<endl<<endl;
		
		for(i=0; i<length-thick-1; i++){
			Icount+=2*(1+i*2);
		}
		Icount+=(1+i*2);
		
		cout<<"The number of interior characters \'"<<iChar<<"\':"<<Icount<<endl<<endl;
		
		for(i=0; i<(length*2)-1; i++){
			if(i<length){
				cout<<setw(6+length-i)<<setfill(space)<<"";
				if(i<thick){
					cout<<setw(1+2*i)<<setfill(sChar)<<"";
				}
				else{
					cout<<setw(thick)<<setfill(sChar)<<"";
					cout<<setw((i-thick)*2+1)<<setfill(iChar)<<"";
					cout<<setw(thick)<<setfill(sChar)<<"";
				}
				
				
				
			}
			
			else{
				cout<<setw(6+(i-length+2))<<setfill(space)<<"";
				if(i>(length*2-2)-thick){
					cout<<setw(1+2*(thick-1)-2*(i-((length*2-1)-thick)))<<setfill(sChar)<<"";
				}
				else{
					cout<<setw(thick)<<setfill(sChar)<<"";
					cout<<setw((length-2-thick)*2+1-(i-length)*2)<<setfill(iChar)<<"";
					cout<<setw(thick)<<setfill(sChar)<<"";					
				}
			}
			cout<<endl;
		}
		
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
