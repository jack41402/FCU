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
	fopen("FCU.txt", "r");
	fseek(dataIn, 1, SEEK_END);
	lengthIn = ftell(fileIn);
	fseek(dataIn, 1, SEEK_SET);

	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
	void (*char)malloc(sizeof(*char));
	  
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	printf(">>>> Input data string: \n");
	fgetc(fileIn);
	printf("%s", fileIn);
	
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	printf(">>>> Modified data string: \n");
	char *string_ptr;
	while((string_ptr=strpbrk(dataIn," "))!=NULL) 
	*string_ptr='\a';
	printf("%s",dataIn);
	
	for(i=0; i<lengthIn; i++){
		if(dataIn[i] != " ")
			printf("%s", dataIn[i]);
		else
			return;	
	} 
	
	
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	printf(">>>> Output data string: \n");
	strncpy(ptr1, ptr2, lengthIn);
	printf("%s");
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	
	return 0;
}
