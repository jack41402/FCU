#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	int sn,in,all;
	int temp,temp2,temp3,temp4;
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
		sn=0;
		in=0;
		temp = length;
		for(i=0;i<thick;i++){
			sn = sn + (temp*4-4);
			temp--;
		}
		temp = 1;
		all = 1;
		for(i=1;i<length;i++){
			temp=temp + 2;
			all=all+temp;
		}
		all = (all-temp)*2+temp;
		in = all-sn;
		cout<<"\nThe number of side characters '"<<sChar<<"': "<<sn<<"\n";
		cout<<"\nThe number of interior characters '"<<iChar<<"': "<<in<<"\n";
		cout<<"\nPrint the rhombus:\n";
		temp = length-1;
		temp2 = 0;
		temp3 = 1;
		temp4 = 1;
		for(i=0;i<length;i++){
			cout<<"      ";
			if(i<thick){
				cout<<setw(temp)<<setfill(' ')<<""<<setw(temp3)<<setfill(sChar)<<"";
				temp3+=2;
			}
			else{
				cout<<setw(temp)<<setfill(' ')<<""<<setw(thick)<<setfill(sChar)<<"";
				cout<<setw(temp4)<<setfill(iChar)<<""<<setw(thick)<<setfill(sChar)<<"";
				temp4+=2;
			}
			cout<<"\n";
			temp--;
			temp2+=2;
		}
		temp = 1;
		temp4-=4;
		temp3-=2;
		for(i=0;i<length-1;i++){
			cout<<"      ";
			if(i>length-2-thick){
				cout<<setw(temp)<<setfill(' ')<<""<<setw(temp3)<<setfill(sChar)<<"";
				temp3-=2;
			}
			else{
				cout<<setw(temp)<<setfill(' ')<<""<<setw(thick)<<setfill(sChar)<<"";
				cout<<setw(temp4)<<setfill(iChar)<<""<<setw(thick)<<setfill(sChar)<<"";
			}
			temp++;
			temp4-=2;
			cout<<"\n";
		}
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
