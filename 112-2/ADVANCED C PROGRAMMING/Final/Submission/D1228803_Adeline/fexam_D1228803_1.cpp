#include <iostream>
#include <iomanip>

using namespace std;


class Rhombus(int length, const char sChar, const char iChar)
{
	//void setShape;
	void printShape;
	void drawShape;
}


Rhombus::Rhombus(l = 0, sPoint = ' ', iPoint = ' ')
{
	length = l;
	sChar = sPoint;
	iChar = iPoint;
}

/*
void Rhombus::setShape(l = 0, sPoint = ' ', iPoint = ' ')
{
	
}
*/

void Rhombus::printShape() const
{
	cout<<"length"<<length<<endl;
	cout<<"side characters"<<sChar<<endl;
	cout<<"interior characters"<<iChar<<endl;
	cout<<"Print the rhombus: \n"<<endl;
}


void Rhombus::drawShape() const
{
	int i;
	cout<<"The number of side characters"<<(4 * length - 4)<<endl;
	cout<<"The number of interior characters"<<(2 * length - 2)<<endl<<endl;
	cout<<setw(10 + length - 1)<<setfill(' ')<<""<<sChar<<endl;
	for(i = 0; i < length; i++)
	{
		cout<<setw(10 + length - i + 1)<<setfill(' ')<<sChar<<setw(2 + i - 2)<<setfill(iChar)<<sChar<<endl;
	}
	for(i = length - 1; i > 1; i--)
	{
		cout<<setw(10 + length - i + 1)<<setfill(' ')<<sChar<<setw(2 + i - 2)<<setfill(iChar)<<sChar<<endl;
	}
	cout<<setw(10 + length - 1)<<setfill(' ')<<""<<sChar<<endl<<endl;
}

int main(void) 
{
	int length; // Value 6 to 30, the side of a rhombus.
	int thick; // Value 0 to 6, the thickness of the sides of a rhombus; program terminates if thick is 0.
	char sChar; // Side character.
	char iChar; // Interior character.
	int i; // Loop variable.
	
	do 
	{
		// Input the side of a rhombus.
		do 
		{
			cout << "Enter the side of a rhombus (6 to 30): ";
			cin >> length;
		} while (length < 6 || length > 30);
		
		// Input the thickness of the sides of a rhombus.
		do 
		{
			cout << "Enter the thickness of the sides of a rhombus (0 to 6): ";
			cin >> thick; 
		} while (thick < 0 || thick > 6 || thick > length / 2);
		
		if (thick == 0) return 0; // Program terminates if thick is 0.
		
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
		 
		//setShape(length, sChar, iChar)
		printShape(length, sChar, iChar);
		drawShape(length, sChar, iChar);
	
		cout << endl<< "----------------------------------------------" << endl;
		
	} while (true);
  
	return 0;
}
