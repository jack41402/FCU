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
    if (fileIn == NULL){
    	printf ("file \"FCU.txt\" DNE");
    	system ("pause");
    	return -1;
	}
    
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	fseek(fileIn, 0, SEEK_END);
	lengthIn = ftell(fileIn);
	fseek(fileIn, 0 ,SEEK_SET);
	    dataIn = (char*)malloc((lengthIn + 1) *sizeof(char*));
i=0 ;
	while (!feof(fileIn))dataIn[i++] = fgetc(fileIn);
	fclose (fileIn);
	dataIn[i-1] = '\0';
			printf("%s",dataIn);

	if (i%80==1){
		printf("\n%s",dataIn);
	}else{
	} 
	
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
//	char *strpbrk(const char *str1, const char *str2){
//		int found ;
//		int i,j;
//		for (i = 0;!found && str1[i]!='\0';i++)
//		 for(j = 0;!found &&str[2]!='\0';j++)
//		   found = (str1[i]=str2[j]);
//		if (found) return(char*)& str1[i-1];
//		else return NULL;
//	}
//	size_t strspn(const char *str1, const char *str2){
//		int done = 0;
//		int length = 0;
//		int i,j;
//		for (i=0; !done&&str1[i]!='\0';i++){
//			for (j=0; 2[j]!='\0';j++){
//				if (str1[i] == str2[j]){length++;break; }
//				else if (length>0&&str2[j+1]=='\0') done = 1;
//			}
//		}
//		return length; 
//	}
//	char strncpy(char *dataOut, char *dataIn) {
//		int length = strlen(dataOut);
//		int i;
//		for (i=0;str2[i]!='\0';i++)
//		    dataOut[length+i] = str2[i];
//		str1[length + i] = '\0';
//		return str1;    
//	}
//	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
//	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
//	//    80 characters in a line.
//	dataOut = (char*)malloc((lengthIn + 1) *sizeof(char*));
//	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
//	//    fputc() in <stdio.h>.
//	fileOut = fopen("result.txt", "w");
//	i = 0;
//	while(dataOut[i]!='\0') fputc(dataOut[i++], fileOut);
//	fputc("#####",fileOut);
//	while(dataOut[i]!='\0') fputc(dataOut[lengthIn-i,i++], fileOut);
//	system("pause");
	return 0;
}
