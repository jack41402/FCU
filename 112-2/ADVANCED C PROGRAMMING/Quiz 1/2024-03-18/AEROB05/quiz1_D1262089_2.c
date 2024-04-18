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
      fileIn=fopen("FCU.txt","r");
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
      fseek(fileIn,0,SEEK_END);     
      lengthIn=ftell(fileIn);
      dataIn=(char*)malloc((lengthIn+1)*sizeof(char));
      fseek(fileIn,0,SEEK_SET);
      i=0;
      while(!feof)dataIn[i++]=fgetc(fileIn);
      fclose(fileIn);
      dataIn[lengthIn]='\0';
      printf(">>>>Input data string :\n%s",dataIn);
      
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	for(i=0;dataIn[i]!='\0';)
	strncpy(ptr1,dataIn,strspn(dataIn,alphanum));
	dataIn=strpbrk(dataIn,alphanum)+strspn(dataIn,alphanum);
	

	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	

	
	dataOut(char*)malloc((lengthOut+1)*sizeof(char));
		
fileOut=fopen("result.txt","w");
i=0;
while(dataOut[i]!='\0')fputc(dataOut[i++],fileOut);
fclose(fileOut);
free(dataIn);
free(dataOut);
system("pause");
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	
	return 0;
}
