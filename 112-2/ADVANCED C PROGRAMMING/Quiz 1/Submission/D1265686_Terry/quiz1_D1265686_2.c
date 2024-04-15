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
	
	fileIn = fopen("FCU.txt","r");
	
	fseek(fileIn,0,SEEK_END);
	lengthIn = ftell(fileIn);
	fseek(fileIn,0,SEEK_SET);
	
	dataIn = (char*) malloc((lengthIn+1)*sizeof(char));
	
	for(i=0;i<lengthIn;++i)
	{
		dataIn[i] = fgetc(fileIn);
	}
	
	fclose(fileIn);
	printf(">>>> Input data string:\n");
	printf("%s",dataIn);
	printf("\n\n");
	printf(">>>> Modified data string:\n");
	
	
	
	
	
	while((ptr1=strpbrk(dataIn," "))!=NULL)
	{
		ptr1=NULL;
	}
	
	while((ptr1=strpbrk(dataIn,","))!=NULL)
	{
		ptr1=NULL;
	}
	
	printf("%s",dataIn);
	
	
	fileOut = fopen("Result.txt","w");
	
	
//	fileOut = fputc(dataIn,"Result.txt");
	
	
	
	
	
	
	fseek(fileOut,0,SEEK_END);
	lengthOut = ftell(fileOut);
	fseek(fileOut,0,SEEK_SET);
	
	dataOut = (char*) malloc((lengthOut+1)*sizeof(char));
	
	strncpy(dataIn,dataOut,lengthOut);
	
	printf("%s",dataOut);
	
	
	/*
	fileOut = fopen("Result.txt",w);
	
	for(i=0;i<lengthOut;++i)
	{
		dataOut[i] = fputc(fileOut);
	}
	
	*/
	
	
	
	
	
	
	
	
	
	
	
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
