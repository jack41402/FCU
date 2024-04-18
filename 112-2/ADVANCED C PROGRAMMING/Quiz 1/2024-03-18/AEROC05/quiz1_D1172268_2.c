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
	int i, j, k; // Data indexes.
	
	// ***** Complete the following steps. 
  	
	// 2. Use file FCU.txt as the input testing file.
	fileIn = fopen("FCU.txt", "r");
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
	dataIn = (char *) malloc(500);
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	while(!feof(fileIn)){
		dataIn[i] = fgetc(fileIn);
		i++;

	}
	dataIn[i] = '\0';
	printf(">>>> Input data string: %s", dataIn);
	fclose(fileIn);
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	while((ptr1=strpbrk(dataIn,"-"))!=NULL)
	*ptr1 = 'NULL ';
	while((ptr1=strpbrk(dataIn,"\n "))!=NULL)
	*ptr1='NULL';
	while((ptr1=strpbrk(dataIn,"+ "))!=NULL)
	*ptr1='NULL';
	while((ptr1=strpbrk(dataIn,", "))!=NULL)
	*ptr1='NULL';
	while((ptr1=strpbrk(dataIn," "))!=NULL)
	*ptr1='NULL';
	
	printf("\n\n>>>> Modified data string: \n");
	for(j = 0; j < 143; j++){
		if(dataIn[j] != '\0'){
			if((j + 1)%80 == 0) printf("%c\n", dataIn[j]);
			else printf("%c", dataIn[j]);
		}
		
	}
	
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	dataOut = (char *) malloc(500);
	printf("\n\nOutput data string: \n");
	for(k = 0; k < 246; k++){
		if(dataIn[k] != '\0'){
			if((k + 1)%80 == 0) printf("%c\n", dataIn[k]);
			else printf("%c", dataIn[k]);
		}
		
	}
	
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	fputc(dataOut, "Result.txt");
	free(dataIn);
	free(dataOut);
	return 0;
}
