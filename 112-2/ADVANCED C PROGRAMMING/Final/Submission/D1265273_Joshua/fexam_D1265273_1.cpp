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
		int n_side = 0;
		if (thick == 1){
			n_side = length*4-4;
		}
		else{
			for (int i = length-thick+1; i<=length; i++){
				n_side = n_side + (i*4-4);
			}
		}
		cout<<"\n"<<"The number of side characters '"<<sChar<<"': "<<n_side<<"\n\n";
		
		int n_interior = 0;
		int a = 1;
		if (thick == 1){
			for (int i = 0; i<=length-4; i++){
				a = a+2;
				n_interior = n_interior+a*2;
			}
			n_interior = n_interior + (a+2)+2;
		}
		else{
			for (int i = 0; i<=length-thick-3; i++){
				a = a+2;
				n_interior = n_interior+a*2;
			}
			n_interior = n_interior + (a+2)+2;
		}
		cout<<"The number of interior characters'"<<iChar<<"': "<<n_interior<<"\n\n";
		cout<<"Print the rhombus:\n";
		if (thick == 1){
			int n = 1;
			for (int i = 1; i<=length; i++){
				if (i ==1){
					cout<<setw(6+length)<<sChar<<"\n";
				} 
				else{
					cout<<setw((6+length)-i+1)<<sChar;
					if (n == 1){
						cout<<iChar<<sChar<<"\n";
						n = n+2;
					}
					else{
						cout<<setw(n+1)<<setfill(iChar)<<sChar<<"\n";
						cout<<setw(i-2)<<setfill(' ');
						n = n+2;
					}
				}
			}
			int m = n-4;
			for (int i = length-1; i>=1; i--){
				if (i == 1){
					cout<<setw(6+length)<<sChar<<"\n";
				}
				else{
					cout<<setw((6+length)-i+1)<<sChar;
					if (m == 1){
						cout<<iChar<<sChar<<"\n";
					}
					else{
						cout<<setw(m+1)<<setfill(iChar)<<sChar<<"\n";
						cout<<setw(i-2)<<setfill(' ');
						m = m-2;
					}
				}
			}
		}
		else{
			int a = 1, b = 3;
			for (int i = 1; i<=thick; i++){
				if (i == 1){
					cout<<setw(6+length)<<sChar<<"\n";
				}
				else{
					
					cout<<setw(6+length-a)<<sChar;
					cout<<setw(a+i)<<setfill(sChar);
					cout<<"\n";
					cout<<setw(a+i)<<setfill(' ');
					a++;
				}
			}
			for (int i = 1; i<=length-thick; i++){
				cout<<setw(6+length-i-2)<<sChar;
				cout<<setw(3)<<setfill(sChar);
				if (i == 1){
					cout<<iChar;
				}
				else{
					cout<<b<<setw(b)<<setfill(iChar)<<setw(b)<<setfill(iChar);
					b = b+2;
				}
				cout<<setw(thick+1)<<setfill(sChar)<<"\n";
				cout<<setw(6+length-i-3)<<setfill(' ');
			}
		}
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
