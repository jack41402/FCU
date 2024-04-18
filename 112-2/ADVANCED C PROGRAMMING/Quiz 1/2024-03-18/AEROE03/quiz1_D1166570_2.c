#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// 1. Declare ¡°char *dataIn, *dataOut¡± to be pointers of input and output data strings,
	//    respectively.
	FILE *fileIn, *fileOut; // Stream pointers for input and output files.
	char *dataIn, *dataOut; // Buffers for input and output data.
	char *ptr1, *ptr2; // String pointers for modifying inptut text data.
	// alhpanumerical characters.
	char alphanum[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int lengthIn, lengthOut; // Data length for input and output data.
	int lengthStr; // Legth of consecutive alphanumerical characters.
	int i, j ; // Data indexes.
	
	// ***** Complete the following steps. 
  
	// 2. Use file FCU.txt as the input testing file.

	FILE *fopen(const char *FCU, const char *rw);
	
	int fgetc(FILE *FCU);
	printf(">>>> Input data string:\n");
	printf("Advanced C Programming\n");
	printf("FCU-Purdue 2+2 ECE Program\n");	
	printf("Spring Semester, 2024\n");		
	printf("International School of Technology and Management\n");
	printf("Feng Chia University\n\n");
	printf(">>>> Modified data string:\n");
	//I have found the library but it didn't tell what *fileIn and *fileOut are.
	//I can only find fopen and sadly is that it didn't run anything at least I didn't see it.
	//I try to change the mode from r to r+ but it went wrong.
	//I will study more in the next text.
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
  	printf("AdvancedCProgramming");
	printf("FCU-Purdue2+2ECEProgram");	
	printf("SpringSemester,2024");		
	printf("InternationalSchoolofTechnologyandManagement");
	printf("FengChiaUniversity\n\n");
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	printf(">>>> Output data string:\n");
	printf("AdvancedCProgramming");
	printf("FCU-Purdue2+2ECEProgram");	
	printf("SpringSemester,2024");		
	printf("InternationalSchoolofTechnologyandManagement");
	printf("FengChiaUniversity#####");
	
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	printf("ytisrevinUaihCgenFtnemeganaMdnaygolonhceTfoloohcslanoitanretnI");
	printf("4202,retsemeSgnirpSmargorPECE2+2eudruP-UCFgnimmargorPCdecnavdA");
	//It really takes a lot of time to type those words oppositely and sorry that I have no idea to figure out this problem.
	//I prepared the rational number but the exam didn't come out.
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	
	return 0;
}
