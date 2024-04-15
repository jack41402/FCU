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
	char string[5000];
	
	// ***** Complete the following steps. 
  
	// 2. Use file FCU.txt as the input testing file.
	fileIn = fopen("FCU.txt", "r");
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
	fseek(fileIn, 0, SEEK_END);
	lengthIn = ftell(fileIn);
	fseek(fileIn, 0, SEEK_SET);
	dataIn = (char *) malloc((lengthIn+1) * sizeof(char));
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	i = 0;
	printf(">>>> Input data string:\n");
  	while(!feof(fileIn)){
  		dataIn[i++] = fgetc(fileIn);
	}
	dataIn[i-1] = '\0';
	j = 0;
	while (dataIn[j] != '\0'){
		printf("%c", dataIn[j++]);
	}
	fclose(fileIn);
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	printf("\n\n>>>> Modified data string:\n");
	strcpy(string, dataIn);
	while((ptr1=strpbrk(string," "))!=NULL) *ptr1='-';
	while((ptr1=strpbrk(string,","))!=NULL) *ptr1='-';
	while((ptr1=strpbrk(string,"+"))!=NULL) *ptr1='-';
	while((ptr1=strpbrk(string,"\n"))!=NULL) *ptr1='-';
	int e = 0;
	for(j=0; string[j] != '\0'; j++){
		if (string[j] == '-'){
			j++;
			if (string[j] == '-'){
				j++;
			}
		}
		string[e++] = string[j];
	}
	string[e] = '\0';
	lengthStr = strspn(string, alphanum);
	j= 0;
	while (j<lengthStr){
		if (j%80 == 0) printf("\n");
		printf("%c", string[j++]);
	}
	//lengthStr = lengthStr * 2 + 5;
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	printf("\n\n\n>>>> Output data string:");
	fileOut = fopen("Result.txt", "w");
	for (i=0; i<5;i++){
		string[lengthStr+i] = '#';
	}
	j=1;
	for (i=lengthStr-1; i>=0;i--){
		string[lengthStr+j+4] = string[i];
		j++;
	}
	j=0;
	
	while (j<strlen(string)+1){
		if (j%80 == 0) printf("\n");
		printf("%c", string[j++]);
	}
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	printf("\n\n%s\n\n", string);
	i = 0;
	while(string[i] != '\0'){
		fputc(string[i++], fileOut);
	}
	fclose(fileOut);
	
	return 0;
}
