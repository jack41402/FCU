#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
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
	printf(">>>> Input data string: ");
	FILE *fopen("FCU.txt", "w")
	
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
	(char*)malloc(dataIn[i])*sizeof(char);
  
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	printf(">>>> Modified data string: ");
	fseek(FILE *dataIn, 0, SEEK_END);
	fread(char *ptr1, size_t n, size_t n, FILE *dataIn);
	fseek(FILE *dataIn, 0, SEEK_SET);
	fread(char *ptr2, size_t n, size_t n, FILE *dataIn);
	fgetc(alphanum);
	
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	printf(">>>> Output data string: ");
	char *strpbrk(const char *str1, const char *str2)
	{
		
		if() return &str1[i + 1];
		else if() (str1[i] = '\0' && str2[i] = '\0') return NULL;
	}
	size_t strspn(const char *str1, const char *str2)
	{
		int length = strlen(str1);
		int i;
		for(i = 0; str2[i] != '\0', i++)
		{
			str1[i] = st2[i];
		}
		
		return length;
	}
	
	char *strcpy(char *str1, const char *str2)
	{
		int i, j;
		for(i = 0; str1[i] != 0; i++)
		{
			for(j = 0; str2[j] != 0; j++)
			{
				str1 = str2;
				str1 = '\0';
			}
		}
		return str1;
	}
	
	fwrite(const char *ptr1, size_t n, size_t n, FILE *dataIn);
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	(char*)malloc(dataOut[i])*sizeof(char);
	
	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	fputs(const char *str1, FILE *dataOut);
	fputs(const char *str2, FILE *dataOut);
	int fclose(FILE);
	
	return 0;
}

