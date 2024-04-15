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
	
	fopen("FCU.txt","r");
	fseek(fileIn, lengthIn, SEEK_SET);
	ftell(fileIn);

	fseek(fileIn, lengthIn, SEEK_END);
	fread("FCU.txt", dataIn,  lengthIn, fgetc(fileIn));
	fileIn='\0';
	if(lengthIn%80==0){
		for(i=0;i<(lengthIn/80);++i){
		for(j=0;j<80;++j){
			ptr1=strpbrk(fileIn,alphanum);
			ptr2=strspn(fileIn,alphanum);
			strcpy(fileOut,ptr1);
			fileOut=strcat(fileOut,ptr2);
		}
		printf("\n");
	}
	else{
	for(i=0;i<(lengthIn/80)+1;++i){
		for(j=0;j<80;++j){
			ptr1=strpbrk(fileIn,alphanum);
			ptr2=strspn(fileIn,alphanum);
			strcpy(fileOut,ptr1);
			fileOut=strcat(fileOut,ptr2);
		}
		printf("\n");
	}
	}
	fopen("Result.txt","w");
	fwrite("Result.txt", dataOut, lengthOut, fputc(fileOut));
	
	// ***** Complete the following steps. 
  
	// 2. Use file FCU.txt as the input testing file.
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.

	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.

	return 0;
}
