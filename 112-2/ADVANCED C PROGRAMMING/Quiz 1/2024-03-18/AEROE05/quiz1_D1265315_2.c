#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// 1. Declare ¡°char *dataIn, *dataOut¡± to be pointers of input and output data strings,
	//    respectively.
	FILE *fileIn, *fileOut, *f; // Stream pointers for input and output files.
	char *dataIn, *dataOut; // Buffers for input and output data.
	char *ptr1, *ptr2; // String pointers for modifying inptut text data.
	// alhpanumerical characters.
	char alphanum[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int lengthIn, lengthOut; // Data length for input and output data.
	int lengthStr; // Legth of consecutive alphanumerical characters.
	int i, j ; // Data indexes.
	int cap = 512;
	// ***** Complete the following steps. 
  	fileIn = fopen("FCU.txt","r");
  	dataIn = (char*) malloc(cap);
	// 2. Use file FCU.txt as the input testing file.

	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
  
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	dataIn = fgetc(fileIn);
	printf(">>>> Input data string:\n");
		printf("%c",dataIn);
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	printf("\n>>>> Modified data string:\n");
				for(i=0;i<=cap;i++){
		if(!isalpha(dataIn[i]) && (dataIn[i]<30 && dataIn[i]>39) ){
			dataIn[i-1]=dataIn[i];
		}
	} 
	for(i=0;i<=cap;i++){
	if(i%80==0){
		printf("\n%c",dataIn[i]);
	}
	else{
		printf("%c",dataIn[i]);
	}
}
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	fileOut = fopen("result.txt","w");
	f = fwrite(dataOut,1,cap,fileOut);
	printf("\n>>>> Output data string:\n");
	printf("%c",dataOut);
	return 0;
}
