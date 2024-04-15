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
	
	printf(">>>> Input data string:\n");
	
	fileIn= fopen("FCU.txt","r");

	
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
  	dataIn=(char *)malloc(alphanum);
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	fread(dataIn,1,lengthIn,fileIn);
	fgets(ptr1, lengthIn, fileIn);
	printf(">>>> Modified data string:\n");
	fprintf(fileIn,dataIn);
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	if(lengthStr%80==0) printf("\n");
	
	strpbrk(ptr1,lengthStr);
	strspn();
	 strncpy();



printf(">>>> Output data string:\n");

	strspn(*ptr1, *ptr2);
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	dataOut=(char *)malloc(fileIn);
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	fileOut= fopen("Result.txt","a+");
	fputc(fileOut,"Result.txt");
	fwrite(fileOut,lengthOut,1,"Result.txt");
	free(dataIn);
	fclose(fileIn);
	return 0;
}
