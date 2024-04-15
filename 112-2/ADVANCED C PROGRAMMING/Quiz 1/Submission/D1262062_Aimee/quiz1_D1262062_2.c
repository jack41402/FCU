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
	fileIn = fopen("FCU.txt", "r");
	fseek(fileIn, 0, SEEK_END); // Move file pointer to the end of the input file.
	lengthIn = ftell(fileIn); // Get the length of the input file.
	fseek(fileIn, 0, SEEK_SET); // Move file pointer to the beginning of the input file.
	dataIn = (char *) malloc((lengthIn + 1) * sizeof(char)); // Dynamically allocate memory space for dataIn[]. 
  	i = 0;
	while(!feof(fileIn)) dataIn[i++] = fgetc(fileIn);
	dataIn[i] = '\0';
	printf(">>>> Input data string:");
	printf("\n%s",dataIn);
	
	i = 0;
//	for(i = 0; dataIn[i] != '\0'; ++i){
//		if(strpbrk(dataIn, alphanum) == NULL){
//			ptr1 = strpbrk(dataIn, alphanum);
//			for(j = ptr1; dataIn[j] != '\0'; ++j){
//				if(strpbrk(dataIn, alphanum)!=NULL){
//				ptr2 = strpbrk(dataIn, alphanum);
//			}
//			
//		}
//	}
//		i = 0;
//		for(i=0; i<ptr2-ptr1; ++i){
//			dataIn = strcpy();
//		}
//	}
//	printf("\n>>>> Modified data string\n");
//	i = 0;
//	lengthStr = 0;
//	for(i = 0; dataIn[i]!='\0'; ++i){
//		if((lengthStr + 1)%80 == 0) printf("%c\n", dataIn[i]);
//		else printf("%c", dataIn[i]);
//		lengthStr ++;
//	}
//	dataOut = (char *) malloc((lengthIn*2 + 7) * sizeof(char));
//	i = 0;
//	dataOut = dataIn;
//	dataOut = strcat(dataOut, "#####");
//	for(i = lengthIn; i>0; --i){
//		dataOut = strcat(dataOut, dataIn[i]);
//	}
//	dataIn[lengthIn*2 + 6] = '\0';
//	i = 0;
//	while(dataIn[i] != '\0') fputc(dataOut[i++], fileOut); ¡@
//	lengthOut = i;
//	dataOut[lengthOut] = '\0';
//	printf("\n>>>> Modifie data string\n");
//	i = 0;
//	lengthStr = 0;
//	for(i = 0; dataOut[i]!='\0'; ++i){
//		if((lengthStr + 1)%80 == 0) printf("%c\n", dataOut[i]);
//		else printf("%c", dataOut[i]);
//		lengthStr ++;
//	}
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
