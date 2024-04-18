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
	fileIn = fopen("FCU.txt", "r");
	fseek(fileIn, 0, SEEK_END);
	lengthIn = ftell(fileIn);
	fseek(fileIn, 0, SEEK_SET);


	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
	dataIn = (char*) malloc(lengthIn*sizeof(char));
  
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	i=0;
	while(!foef(fileIn)){
		dataIn[i] = fgetc(fileIn);
		i++;
	}
	dataIn[lengthIn] = '\0';
	fclose(fileIn);
	printf(">>>>input data string: \n");
	printf("%s\n", dataIn);
	
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	while(dataIn!='\0'){
		while(strcmp(dataIn, alphanum)){
			strcpy(dataIn,dataIn+1);
			dataIn++;
			lengthIn--;
		}
	}
	for(i=0; i<lengthIn; i++){
		printf("%c", dataIn[i]);
		if((i+1)%80==0){
			printf("\n");
		}
	}
	
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	char addrs[] = "#####";
	dataOut = (char*)malloc(200*sizeof(char));
	dataOut = strcat(dataIn, addrs);
	lengthOut = 2*lengthIn+4;
	for(i=0; i<lengthOut; i++){
		printf("%c", dataOut[i]);
		if((i+1)%80==0){
			printf("\n");
		}
	}
	
	
	
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	fileOut = fopen("Result.txt", "w");
	i=0;
	while(!foef(dataOut)){
		fileOut[i] = fputc(dataOut);
		i++;
	}
	dataOut[lengthOut] = '\0';
	fclose(fileOut);
	
	free(dataIn);
	free(dataOut);
	return 0;
}
