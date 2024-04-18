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
  
	fileIn=fopen("FCU.txt", "R");
	//if(fileIn==NULL) printf("-1\n");

	fseek(fileIn, 0, SEEK_END);
	lengthIn=ftell(fileIn);
	fseek(fileIn, 0, SEEK_SET);
	dataIn= (char*) malloc(sizeof(char)*(lengthIn+1));
	
	for(i=0; i<lengthIn; i++){
		dataIn[i]=fgetc(fileIn);
	}
	dataIn[i]='\0';
	fclose(fileIn);
	
	printf(">>>>Input data string:\n%s\n", dataIn);
	
//	dataIn="Advanced C Programming FCU-Purdue 2+2 ECE Program Spring Semester, 2024 International School of Technology and Management Feng Chia University";

ptr1=dataIn;
for(i=0; i<lengthIn; i++){
	for(j=0; j<62; j++){
		if(dataIn[i]==alphanum[j]) break;
		else if(j==61){
			strncpy(ptr1+i, ptr1+i+1, lengthIn-i);
			ptr1+=i;
			i--;
		}
	}
}



/*while(*ptr1!='\0'){
	lengthStr=strspn(dataIn, alphanum);
	strncpy(ptr1+lengthStr, ptr1+lengthStr+1, lengthIn-lengthStr-1);
	ptr1+= lengthStr;
}*/
	
	printf("%s", dataIn);
  	for(i=0; i<lengthIn; i++){
		if(i%80==0) printf("\n%c", dataIn[i]);
		else printf("%c", dataIn[i]);
	}
  
  
dataOut= (char*) malloc(sizeof(char)*(2*strlen(dataIn)+1));
strcat(dataOut, dataIn);
for(i=0; i<strlen(dataIn); i++){
	dataOut[i+strlen(dataIn)]=dataOut[strlen(dataIn)-1-i];
}
printf(">>>>Output data stream:\n");
	printf("%s", dataOut);
  	for(i=0; i<strlen(dataOut); i++){
		if(i%80==0) printf("\n%c", dataOut[i]);
		else printf("%c", dataIn[i]);
	}
fileOut=fopen("Result.txt", "W") ;
for(i=0; i<strlen(dataOut); i++){
	fputc(dataOut[i], fileOut);
}
fclose(fileOut);
	
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
