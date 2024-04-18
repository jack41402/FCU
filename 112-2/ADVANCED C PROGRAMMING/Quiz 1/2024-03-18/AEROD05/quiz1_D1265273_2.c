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
	fileIn= fopen("FCU.txt", "r");
	if (fileIn==NULL)
	{
		printf("cannot open the file");
	}
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
  	dataIn= (char *) malloc(100* sizeof(char));
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	printf(">>>> Input data string: \n");
	i=0;
	while(1)
	{
		dataIn[i]= fgetc(fileIn);
		printf("%c", dataIn[i]);
		i++;
		if (feof(fileIn))
		{
			break;
		}	
	}
	printf("\n\n");
	printf(">>>> Modified data string:\n");
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	for (j=0; j<i; j++)
	{
		if (j%80==0 && j!=0)
		{
			printf("\n");
		}
		if (&dataIn[j]==(strpbrk(dataIn, " ")) )
		{
			strncpy(ptr1, dataIn, j-1);
		}
		else if (&dataIn[j]==(strpbrk(dataIn, "+")) )
		{
			strncpy(ptr1, dataIn, j-1);
		}
		else if (&dataIn[j]==(strpbrk(dataIn, ",")))
		{
			strncpy(ptr1, dataIn, j-1);
		}
		else if (&dataIn[j]==(strpbrk(dataIn, "-"))) 
		{
			strncpy(ptr1, dataIn, j-1);
		}
		else if (&dataIn[j]==(strpbrk(dataIn, "\n")))
		{
			strncpy(ptr1, dataIn, j-1);
		}
	}
	printf("%s", ptr1);
	fclose(fileIn);
	printf("\n\n\n");
	printf(">>>> Outout data string:\n");
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	dataOut= realloc(dataIn, 100);
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	free(dataIn);
	free(dataOut);
	return 0;
}
