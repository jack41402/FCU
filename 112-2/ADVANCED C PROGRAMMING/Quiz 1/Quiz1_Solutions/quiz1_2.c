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
  
	// 2. Use file FCU.txt as the input testing file.
	fileIn = fopen("FCU.txt", "r"); // Open input text file FCU.txt.
	if (fileIn==NULL) { // If the input file does not exist, print an error message.
		printf("\nText file \"FCU.txt\" does not exist.\n");
		return -1;
	}

	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
	fseek(fileIn, 0, SEEK_END); // Move file pointer to the end of the input file.
	lengthIn = ftell(fileIn); // Get the length of the input file.
	fseek(fileIn, 0, SEEK_SET); // Move file pointer to the beginning of the input file.
	dataIn = (char *) malloc((lengthIn + 1) * sizeof(char)); // Dynamically allocate memory space for dataIn[]. 
  
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	i = 0; // Set data index to 0.
	// Read the data string dataIn character by character using function fgetc().
	while (!feof(fileIn)) dataIn[i++] = fgetc(fileIn); 
	fclose(fileIn); // Close input file FCU.txt.
	dataIn[i] = '\0'; // Insert end of string.
	printf(">>>> Input data string:\n%s", dataIn); // Print the input string dataIn.
	
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line. 
	ptr1 = dataIn; // String pointer for the original input text data.
	ptr2 = dataIn; // String pointer for the modified input text data.
	while ((ptr1=strpbrk(ptr1, alphanum))!=NULL) { // Continue if there are more alphanumerical characters¡£ 
		lengthStr = strspn(ptr1, alphanum); // Legth of current consecutive alphanumerical characters.
		strncpy(ptr2, ptr1, lengthStr); // Copy current consecutive alphanumerical characters.
		ptr1 = ptr1 + lengthStr; // Update pointer of the original text data.
		ptr2 = ptr2 + lengthStr; // Update pointer of the modified text data.
	}
	ptr2[0] = '\0'; // Insert end of string to the end of the modified text data.
	lengthIn = strlen(dataIn); // Length of the modified input text data.
	printf("\n\n>>>> Modified data string:\n"); // Print the modified string of dataIn.
	for (i=0; i<lengthIn; i++) { // Print 80 characters in a line.
		printf("%c", dataIn[i]); // Print a characters.
		if ((i+1)%80==0) printf("\n"); // For each 80 characters, print a newline.
	}
	if (i%80!=0) printf("\n"); // Print a newline, if the last line is less than 80 characters

	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	lengthOut = lengthIn * 2 + 5; // Length of the output text data.
	dataOut = (char *) malloc((lengthOut + 1) * sizeof(char)); // Dynamically allocate memory space for dataOut[].
	for (i=0; i<lengthIn; i++) {
		dataOut[i] = dataIn[i];
		dataOut[lengthOut-1-i] = dataIn[i];
	}
	for (j=0; j<5; j++) dataOut[i++] = '#';
	dataOut[lengthOut] = '\0';
	printf("\n\n>>>> Output data string:\n"); // Print the output string of dataOut.
	for (i=0; i<lengthOut; i++) { // Print 80 characters in a line.
		printf("%c", dataOut[i]); // Print a characters.
		if ((i+1)%80==0) printf("\n"); // For each 80 characters, print a newline.
	}
	if (i%80!=0) printf("\n"); // Print a newline, if the last line is less than 80 characters
	
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	fileOut = fopen("Result.txt", "w"); // Open the result file for output text data.
	i = 0; // Set data index to 0.
	// Write the data string dataOut to file ¡°Result.txt¡± character by character using function fputc().
	while (dataOut[i]!='\0') fputc(dataOut[i++], fileOut);
	fclose(fileOut); // Close the output file.
	
	return 0;
}
