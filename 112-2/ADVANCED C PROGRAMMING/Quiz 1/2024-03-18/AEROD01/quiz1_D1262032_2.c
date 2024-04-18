#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// 1. Declare ¡°char *dataIn, *dataOut¡± to be pointers of input and output data strings,
	//    respectively.
	FILE *fileIn, *fileOut; // Stream pointers for input and output files.
	char *dataIn, *dataOut, *in; // Buffers for input and output data.
	char *ptr1, *ptr2; // String pointers for modifying inptut text data.
	// alhpanumerical characters.
	char alphanum[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int lengthIn, lengthOut; // Data length for input and output data.
	int lengthStr; // Legth of consecutive alphanumerical characters.
	int i, j=0; // Data indexes.
	
	// ***** Complete the following steps. 
    fileIn=fopen("FCU.txt", "r");
    fseek(fileIn,0,SEEK_END);
    lengthIn=ftell(fileIn);
    fseek(fileIn,0,SEEK_SET);
    dataIn=(char *)malloc((lengthIn+1)*sizeof(char));
    i=0;
    while(!feof(fileIn)) dataIn[i++]=fgetc(fileIn);
    dataIn[i]='\0';
    printf(">>>> Input data string:\n");
    printf("%s", dataIn);
    in=(char *)malloc((lengthIn+1)*sizeof(char));
    for(i=0;dataIn[i]!='\0';i++) {in[i]=dataIn[i];}
    in[i]='\0';
    
    ptr2=strpbrk(dataIn,alphanum);
    while(*ptr2!='\0'){
	ptr1=strpbrk(ptr2,alphanum);
	lengthStr=strspn(ptr1,alphanum);
	for(i=0;i<lengthStr;i++){
	dataIn[i+j]=*ptr1;
	ptr1++;
	}
	j+=i;
	ptr2=strpbrk(ptr1,alphanum);
}
    
    dataOut=(char *)malloc((2*strlen(dataIn)+5)*sizeof(char));
    printf("\n\n\n>>>> Output data string:\n");
    for(i=0;i<2*strlen(dataIn)+5;i++){
    	if(i<strlen(dataIn)) dataOut[i]=dataIn[i];
    	else if(i>=strlen(dataIn) && i<=strlen(dataIn)+4) dataOut[i]='#';
    	else dataOut[i]=dataIn[i-84];
	}
	printf("%s", dataOut);
	fileOut=fopen("Result.txt", "w");
	i=0;
	while(dataOut[i]!='0') fputc(dataOut[i], fileOut);
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
